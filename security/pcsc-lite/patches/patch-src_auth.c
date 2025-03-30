$NetBSD: patch-src_auth.c,v 1.3 2025/03/30 17:47:06 adam Exp $

Upstream code blurs checking for libraries (POLKIT), features
(PEERCRED), and OS, when guarding code that uses the library and
features.  Change to a single guard, and using the fallback allow
function otherwise.

Sent upstream 20241227.

On Darwin, cr_pid is not defined.

--- src/auth.c.orig	2025-03-26 14:52:29.000000000 +0000
+++ src/auth.c
@@ -51,28 +51,16 @@
 
 #include <errno.h>
 
-#ifdef HAVE_POLKIT
-
-#if defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
+#if defined(POLKIT) && defined(SO_PEERCRED) || defined(LOCAL_PEERCRED) && !defined(__APPLE__)
 
 #include <polkit/polkit.h>
 #include <stdbool.h>
 
-#ifdef __FreeBSD__
-
 #include <sys/ucred.h>
 typedef struct xucred platform_cred;
 #define	CRED_PID(uc)	(uc).cr_pid
 #define	CRED_UID(uc)	(uc).cr_uid
 
-#else
-
-typedef struct ucred platform_cred;
-#define	CRED_PID(uc)	(uc).pid
-#define	CRED_UID(uc)	(uc).uid
-
-#endif
-
 extern bool disable_polkit;
 
 /* Returns non zero when the client is authorized */
@@ -180,13 +168,6 @@ cleanup1:
 	return ret;
 }
 
-#else
-
-/* Do not enable polkit if it not yet supported on your system.
- * Patches are welcome. */
-#error polkit is enabled, but no socket cred implementation for this platform
-
-#endif
 
 #else
 
