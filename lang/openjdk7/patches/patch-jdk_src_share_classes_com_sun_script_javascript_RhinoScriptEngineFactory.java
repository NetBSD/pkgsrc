$NetBSD: patch-jdk_src_share_classes_com_sun_script_javascript_RhinoScriptEngineFactory.java,v 1.1 2013/06/02 06:12:28 ryoon Exp $

* From rhino.patch.

--- jdk/src/share/classes/com/sun/script/javascript/RhinoScriptEngineFactory.java.orig	2012-08-10 17:25:37.000000000 +0000
+++ jdk/src/share/classes/com/sun/script/javascript/RhinoScriptEngineFactory.java
@@ -26,7 +26,7 @@
 package com.sun.script.javascript;
 import javax.script.*;
 import java.util.*;
-import sun.org.mozilla.javascript.internal.*;
+import org.mozilla.javascript.*;
 import com.sun.script.util.*;
 
 /**
