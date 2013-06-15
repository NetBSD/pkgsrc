$NetBSD: patch-program_lib_Roundcube_rcube__db__pgsql.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 983308e8b364c0ae5358874087977df9740d97ac: 
  Fix connection to posgtres db using unix socket (#1489132)

--- program/lib/Roundcube/rcube_db_pgsql.php.orig	2013-05-16 18:06:36.000000000 +0000
+++ program/lib/Roundcube/rcube_db_pgsql.php
@@ -129,4 +129,37 @@ class rcube_db_pgsql extends rcube_db
         return isset($this->variables[$varname]) ? $this->variables[$varname] : $default;
     }
 
+    /**
+     * Returns PDO DSN string from DSN array
+     *
+     * @param array $dsn DSN parameters
+     *
+     * @return string DSN string
+     */
+    protected function dsn_string($dsn)
+    {
+        $params = array();
+        $result = 'pgsql:';
+
+        if ($dsn['hostspec']) {
+            $params[] = 'host=' . $dsn['hostspec'];
+        }
+        else if ($dsn['socket']) {
+            $params[] = 'host=' . $dsn['socket'];
+        }
+
+        if ($dsn['port']) {
+            $params[] = 'port=' . $dsn['port'];
+        }
+
+        if ($dsn['database']) {
+            $params[] = 'dbname=' . $dsn['database'];
+        }
+
+        if (!empty($params)) {
+            $result .= implode(';', $params);
+        }
+
+        return $result;
+    }
 }
