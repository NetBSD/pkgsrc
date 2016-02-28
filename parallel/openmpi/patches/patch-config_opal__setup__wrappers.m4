$NetBSD: patch-config_opal__setup__wrappers.m4,v 1.1 2016/02/28 19:47:41 joerg Exp $

Do not second guess the compiler's choice of DT_RPATH vs DT_RUNPATH.

--- config/opal_setup_wrappers.m4.orig	2016-02-24 13:18:55.229667898 +0000
+++ config/opal_setup_wrappers.m4
@@ -177,10 +177,6 @@ EOF
            AC_MSG_RESULT([yes (no extra flags needed)])])
 
     OPAL_VAR_SCOPE_POP
-
-    # If we found RPATH support, check for RUNPATH support, too
-    AS_IF([test "$WRAPPER_RPATH_SUPPORT" = "rpath"],
-          [OPAL_SETUP_RUNPATH])
 ])
 
 # Check to see if the linker supports the DT_RUNPATH flags via
