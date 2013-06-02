$NetBSD: patch-jdk_src_share_classes_com_sun_script_javascript_RhinoWrapFactory.java,v 1.1 2013/06/02 06:12:28 ryoon Exp $

* From rhino.patch.

--- jdk/src/share/classes/com/sun/script/javascript/RhinoWrapFactory.java.orig	2012-08-10 17:25:37.000000000 +0000
+++ jdk/src/share/classes/com/sun/script/javascript/RhinoWrapFactory.java
@@ -27,7 +27,7 @@ package com.sun.script.javascript;
 
 import java.lang.reflect.*;
 import static sun.security.util.SecurityConstants.*;
-import sun.org.mozilla.javascript.internal.*;
+import org.mozilla.javascript.*;
 
 /**
  * This wrap factory is used for security reasons. JSR 223 script
