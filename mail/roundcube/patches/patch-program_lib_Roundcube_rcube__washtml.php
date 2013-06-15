$NetBSD: patch-program_lib_Roundcube_rcube__washtml.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 1fe7d6ad75d2a5a2ab72a24de8cd8cdb341cff0e:
  Fix displaying messages with invalid self-closing HTML tags (#1489137)

--- program/lib/Roundcube/rcube_washtml.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_washtml.php
@@ -113,10 +113,9 @@ class rcube_washtml
         'type', 'rows', 'cols', 'disabled', 'readonly', 'checked', 'multiple', 'value'
     );
 
-    /* Block elements which could be empty but cannot be returned in short form (<tag />) */
-    static $block_elements = array('div', 'p', 'pre', 'blockquote', 'a', 'font', 'center',
-        'table', 'ul', 'h1', 'h2', 'h3', 'h4', 'h5', 'h6', 'ol', 'dl', 'strong',
-        'i', 'b', 'u', 'span',
+    /* Elements which could be empty and be returned in short form (<tag />) */
+    static $void_elements = array('area', 'base', 'br', 'col', 'command', 'embed', 'hr',
+        'img', 'input', 'keygen', 'link', 'meta', 'param', 'source', 'track', 'wbr'
     );
 
     /* State for linked objects in HTML */
@@ -134,12 +133,15 @@ class rcube_washtml
     /* Ignore these HTML tags but process their content */
     private $_ignore_elements = array();
 
-    /* Block elements which could be empty but cannot be returned in short form (<tag />) */
-    private $_block_elements = array();
+    /* Elements which could be empty and be returned in short form (<tag />) */
+    private $_void_elements = array();
 
     /* Allowed HTML attributes */
     private $_html_attribs = array();
 
+    /* Max nesting level */
+    private $max_nesting_level;
+
 
     /**
      * Class constructor
@@ -149,9 +151,9 @@ class rcube_washtml
         $this->_html_elements   = array_flip((array)$p['html_elements']) + array_flip(self::$html_elements) ;
         $this->_html_attribs    = array_flip((array)$p['html_attribs']) + array_flip(self::$html_attribs);
         $this->_ignore_elements = array_flip((array)$p['ignore_elements']) + array_flip(self::$ignore_elements);
-        $this->_block_elements  = array_flip((array)$p['block_elements']) + array_flip(self::$block_elements);
+        $this->_void_elements   = array_flip((array)$p['void_elements']) + array_flip(self::$void_elements);
 
-        unset($p['html_elements'], $p['html_attribs'], $p['ignore_elements'], $p['block_elements']);
+        unset($p['html_elements'], $p['html_attribs'], $p['ignore_elements'], $p['void_elements']);
 
         $this->config = $p + array('show_washed' => true, 'allow_remote' => false, 'cid_map' => array());
     }
@@ -284,12 +286,26 @@ class rcube_washtml
      * It output only allowed tags with allowed attributes
      * and allowed inline styles
      */
-    private function dumpHtml($node)
+    private function dumpHtml($node, $level = 0)
     {
         if (!$node->hasChildNodes()) {
             return '';
         }
 
+        $level++;
+
+        if ($this->max_nesting_level > 0 && $level == $this->max_nesting_level - 1) {
+            // log error message once
+            if (!$this->max_nesting_level_error) {
+                $this->max_nesting_level_error = true;
+                rcube::raise_error(array('code' => 500, 'type' => 'php',
+                    'line' => __LINE__, 'file' => __FILE__,
+                    'message' => "Maximum nesting level exceeded (xdebug.max_nesting_level={$this->max_nesting_level})"),
+                    true, false);
+            }
+            return '<!-- ignored -->';
+        }
+
         $node = $node->firstChild;
         $dump = '';
 
@@ -299,19 +315,19 @@ class rcube_washtml
                 $tagName = strtolower($node->tagName);
                 if ($callback = $this->handlers[$tagName]) {
                     $dump .= call_user_func($callback, $tagName,
-                        $this->wash_attribs($node), $this->dumpHtml($node), $this);
+                        $this->wash_attribs($node), $this->dumpHtml($node, $level), $this);
                 }
                 else if (isset($this->_html_elements[$tagName])) {
-                    $content = $this->dumpHtml($node);
+                    $content = $this->dumpHtml($node, $level);
                     $dump .= '<' . $tagName . $this->wash_attribs($node) .
-                        ($content != '' || isset($this->_block_elements[$tagName]) ? ">$content</$tagName>" : ' />');
+                        ($content === '' && isset($this->_void_elements[$tagName]) ? ' />' : ">$content</$tagName>");
                 }
                 else if (isset($this->_ignore_elements[$tagName])) {
                     $dump .= '<!-- ' . htmlspecialchars($tagName, ENT_QUOTES) . ' not allowed -->';
                 }
                 else {
                     $dump .= '<!-- ' . htmlspecialchars($tagName, ENT_QUOTES) . ' ignored -->';
-                    $dump .= $this->dumpHtml($node); // ignore tags not its content
+                    $dump .= $this->dumpHtml($node, $level); // ignore tags not its content
                 }
                 break;
 
@@ -324,14 +340,14 @@ class rcube_washtml
                 break;
 
             case XML_HTML_DOCUMENT_NODE:
-                $dump .= $this->dumpHtml($node);
+                $dump .= $this->dumpHtml($node, $level);
                 break;
 
             case XML_DOCUMENT_TYPE_NODE:
                 break;
 
             default:
-                $dump . '<!-- node type ' . $node->nodeType . ' -->';
+                $dump .= '<!-- node type ' . $node->nodeType . ' -->';
             }
         } while($node = $node->nextSibling);
 
@@ -358,6 +374,9 @@ class rcube_washtml
             $this->config['base_url'] = '';
         }
 
+        // Detect max nesting level (for dumpHTML) (#1489110)
+        $this->max_nesting_level = (int) @ini_get('xdebug.max_nesting_level');
+
         @$node->loadHTML($html);
         return $this->dumpHtml($node);
     }
@@ -405,6 +424,7 @@ class rcube_washtml
             rcube::raise_error(array('code' => 620, 'type' => 'php',
                 'line' => __LINE__, 'file' => __FILE__,
                 'message' => $errstr), true, false);
+
             return '';
         }
 
