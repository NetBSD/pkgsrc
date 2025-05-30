$NetBSD: patch-mod_evasive24.c,v 1.1 2025/05/30 17:31:48 jschauma Exp $

Patch in an s6_addr32 definition for NetBSD, and specify
sendmail(1) as the mailer, since the module attempts to
write headers to stdin.

--- mod_evasive24.c.orig	2025-02-16 11:36:05.000000000 -0500
+++ mod_evasive24.c	2025-05-29 22:23:46.266203700 -0400
@@ -31,6 +31,10 @@
 #include <errno.h>
 #include <unistd.h>  // getpid(2)
 
+#ifdef __NetBSD__
+#define s6_addr32 __u6_addr.__u6_addr32 /* XXX nonstandard */
+#endif
+
 #define PCRE2_CODE_UNIT_WIDTH 8
 #include <pcre2.h>
 
@@ -45,7 +49,13 @@
 
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
