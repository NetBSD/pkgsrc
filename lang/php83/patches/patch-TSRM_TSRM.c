$NetBSD: patch-TSRM_TSRM.c,v 1.1 2024/11/10 22:09:50 prlw1 Exp $

Backport of

https://github.com/php/php-src/commit/2d6bd1644d104fe934a5117d232d3f50ffe9ff28

to fix

Cannot load lib/httpd/mod_php8.so into server: /usr/pkg/lib/httpd/mod_php8.so:
No space available for static Thread Local Storage

PR pkg/56717

--- TSRM/TSRM.c.orig	2024-10-22 18:39:14.000000000 +0000
+++ TSRM/TSRM.c
@@ -756,14 +756,16 @@ TSRM_API size_t tsrm_get_ls_cache_tcb_of
     // TODO: Implement support for fast JIT ZTS code ???
 	return 0;
 #elif defined(__x86_64__) && defined(__GNUC__) && !defined(__FreeBSD__) && \
-	!defined(__OpenBSD__) && !defined(__MUSL__) && !defined(__HAIKU__)
+	!defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__MUSL__) \
+	&& !defined(__HAIKU__)
 	size_t ret;
 
 	asm ("movq _tsrm_ls_cache@gottpoff(%%rip),%0"
           : "=r" (ret));
 	return ret;
 #elif defined(__i386__) && defined(__GNUC__) && !defined(__FreeBSD__) && \
-	!defined(__OpenBSD__) && !defined(__MUSL__) && !defined(__HAIKU__)
+	!defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__MUSL__) && \
+	!defined(__HAIKU__)
 	size_t ret;
 
 	asm ("leal _tsrm_ls_cache@ntpoff,%0"
