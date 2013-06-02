$NetBSD: patch-jdk_src_share_classes_com_sun_script_javascript_RhinoScriptEngine.java,v 1.1 2013/06/02 06:12:28 ryoon Exp $

* From rhino.patch.

--- jdk/src/share/classes/com/sun/script/javascript/RhinoScriptEngine.java.orig	2013-05-29 03:57:57.000000000 +0000
+++ jdk/src/share/classes/com/sun/script/javascript/RhinoScriptEngine.java
@@ -26,7 +26,7 @@
 package com.sun.script.javascript;
 import com.sun.script.util.*;
 import javax.script.*;
-import sun.org.mozilla.javascript.internal.*;
+import org.mozilla.javascript.*;
 import java.lang.reflect.Method;
 import java.io.*;
 import java.security.*;
