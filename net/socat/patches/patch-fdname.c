$NetBSD: patch-fdname.c,v 1.1 2021/01/08 08:47:29 otis Exp $

Use correct prototype for getprotobynumber_r() on SunOS

--- fdname.c.orig	2021-01-03 18:23:22.000000000 +0000
+++ fdname.c
@@ -232,7 +232,7 @@ int sockname(int fd, FILE *outfile, char
    /*Linux struct ifreq ifc = {{{ 0 }}};*/
    struct ifreq ifc = {{ 0 }};
 #endif
-   int rc;
+   int rc = 0;
 
 #if defined(SO_PROTOCOL) || defined(SO_PROTOTYPE)
    optlen = sizeof(proto);
@@ -254,7 +254,12 @@ int sockname(int fd, FILE *outfile, char
 
 #if defined(SO_PROTOCOL) || defined(SO_PROTOTYPE)
 #if HAVE_GETPROTOBYNUMBER_R
+#if defined(__sun)
+   protoentp = getprotobynumber_r(proto, &protoent, protoname, sizeof(protoname));
+   rc = errno;
+#else
    rc = getprotobynumber_r(proto, &protoent, protoname, sizeof(protoname), &protoentp);
+#endif
    if (protoentp == NULL) {
       Warn2("sockname(): getprotobynumber_r(proto=%d, ...): %s",
 	    proto, strerror(rc));
