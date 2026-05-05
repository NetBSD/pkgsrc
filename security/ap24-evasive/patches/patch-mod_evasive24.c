$NetBSD: patch-mod_evasive24.c,v 1.2 2026/05/05 10:19:43 tm Exp $

Patch in an s6_addr32 definition for NetBSD, and specify
sendmail(1) as the mailer, since the module attempts to
write headers to stdin.

--- mod_evasive24.c.orig	Sun Feb 16 16:36:05 2025
+++ mod_evasive24.c	Tue May  5 08:16:45 2026
@@ -31,6 +31,12 @@
 #include <errno.h>
 #include <unistd.h>  // getpid(2)
 
+#ifdef __NetBSD__
+#define s6_addr32 __u6_addr.__u6_addr32 /* XXX nonstandard */
+#elif defined(__sun)
+#define s6_addr32 _S6_un._S6_u32
+#endif
+
 #define PCRE2_CODE_UNIT_WIDTH 8
 #include <pcre2.h>
 
@@ -45,7 +51,13 @@
 
 AP_DECLARE_MODULE(evasive);
 
+/* NetBSD's mail(1) does not read headers from stdin,
+ * so default to sendmail(1) */
+#ifdef __NetBSD__
+#define MAILER  "/usr/sbin/sendmail -t"
+#else
 #define MAILER  "/bin/mail %s"
+#endif
 
 #define DEFAULT_HASH_TBL_SIZE   3079UL  // Default hash table size
 #define DEFAULT_PAGE_COUNT      2       // Default maximum page hit count per interval
