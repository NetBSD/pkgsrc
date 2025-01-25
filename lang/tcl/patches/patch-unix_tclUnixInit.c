$NetBSD: patch-unix_tclUnixInit.c,v 1.6 2025/01/25 21:29:26 adam Exp $

Carried over from TCL 8.4

--- unix/tclUnixInit.c.orig	2024-11-27 15:56:57.000000000 +0000
+++ unix/tclUnixInit.c
@@ -22,7 +22,7 @@
 #    endif
 #endif
 #include <sys/resource.h>
-#if defined(__FreeBSD__) && defined(__GNUC__)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(__GNUC__)
 #   include <floatingpoint.h>
 #endif
 #if defined(__bsdi__)
@@ -31,6 +31,12 @@
 #	include <dlfcn.h>
 #   endif
 #endif
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/utsname.h>
+#endif
+
 
 #ifdef __CYGWIN__
 #ifdef __cplusplus
@@ -393,7 +399,7 @@ TclpInitPlatform(void)
     (void) signal(SIGPIPE, SIG_IGN);
 #endif /* SIGPIPE */
 
-#if defined(__FreeBSD__) && defined(__GNUC__)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(__GNUC__)
     /*
      * Adjust the rounding mode to be more conventional. Note that FreeBSD
      * only provides the __fpsetreg() used by the following two for the GNU
@@ -797,6 +803,11 @@ TclpSetVariables(
     int unameOK;
     const char *p, *q;
     Tcl_Obj *pkgListObj = Tcl_NewObj();
+#if defined(__NetBSD__)
+    char machine_arch[SYS_NMLN];
+    int mib[2] = { CTL_HW, HW_MACHINE_ARCH };
+    size_t len = sizeof(machine_arch);
+#endif
 
 #ifdef HAVE_COREFOUNDATION
     char tclLibPath[MAXPATHLEN + 1];
@@ -947,8 +958,15 @@ TclpSetVariables(
 
 #endif /* DJGPP */
 	}
+#if defined(__NetBSD__)
+	if (sysctl(mib, sizeof(mib) / sizeof(int), machine_arch, &len, NULL, 0) < 0)
+	    unameOK = 0;
+	else
+            Tcl_SetVar2(interp, "tcl_platform", "machine", machine_arch, TCL_GLOBAL_ONLY);
+#else
 	Tcl_SetVar2(interp, "tcl_platform", "machine", name.machine,
 		TCL_GLOBAL_ONLY);
+#endif /* __NetBSD__ */
     }
 #endif /* !NO_UNAME */
     if (!unameOK) {
