$NetBSD: patch-vgauth_lib_common.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- vgauth/lib/common.c.orig	2016-02-16 20:06:48.000000000 +0000
+++ vgauth/lib/common.c
@@ -374,7 +374,7 @@ done:
 
    return err;
    }
-#elif defined(sun)
+#elif defined(sun) || defined(__NetBSD__)
    return VGAUTH_E_OK;
 #else
 #error VGAuth_InstallClient unsupported on this platform.
@@ -454,7 +454,7 @@ done:
    g_free(lowAppName);
    return err;
    }
-#elif defined(sun)
+#elif defined(sun) || defined(__NetBSD__)
    return VGAUTH_E_OK;
 #else
 #error VGAuth_UninstallClient unsupported on this platform.
