$NetBSD: patch-src_auth.c,v 1.1 2024/12/27 15:10:09 gdt Exp $

Upstream code blurs checking for libraries (POLKIT), features
(PEERCRED), and OS, when guarding code that uses the library and
features.  Change to a single guard, and using the fallback allow
function otherwise.

Sent upstream 20241227.

--- src/auth.c.orig	2024-12-24 10:16:27.000000000 +0000
+++ src/auth.c
@@ -51,28 +51,16 @@
 
 #include <errno.h>
 
-#ifdef HAVE_POLKIT
-
-#if defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
+#if defined(POLKIT) && defined(SO_PEERCRED) || defined(LOCAL_PEERCRED)
 
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
@@ -180,13 +168,7 @@ cleanup1:
 	return ret;
 }
 
-#else
-
-#error polkit is enabled, but no socket cred implementation for this platform
-
-#endif
-
-#else
+#else /* defined(POLKIT) && defined(SO_PEERCRED) || defined(LOCAL_PEERCRED) */
 
 unsigned IsClientAuthorized(int socket, const char* action, const char* reader)
 {
@@ -197,4 +179,4 @@ unsigned IsClientAuthorized(int socket, 
 	return 1;
 }
 
-#endif
+#endif /* defined(POLKIT) && defined(SO_PEERCRED) || defined(LOCAL_PEERCRED) */
