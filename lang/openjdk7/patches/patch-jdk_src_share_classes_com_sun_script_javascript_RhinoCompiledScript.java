$NetBSD: patch-jdk_src_share_classes_com_sun_script_javascript_RhinoCompiledScript.java,v 1.1 2013/06/02 06:12:28 ryoon Exp $

* From rhino.patch.

--- jdk/src/share/classes/com/sun/script/javascript/RhinoCompiledScript.java.orig	2012-08-10 17:25:37.000000000 +0000
+++ jdk/src/share/classes/com/sun/script/javascript/RhinoCompiledScript.java
@@ -25,7 +25,7 @@
 
 package com.sun.script.javascript;
 import javax.script.*;
-import sun.org.mozilla.javascript.internal.*;
+import org.mozilla.javascript.*;
 
 /**
  * Represents compiled JavaScript code.
