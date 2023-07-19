$NetBSD: patch-src_lib_ecore__con_dns.h,v 1.2 2023/07/19 01:09:17 pho Exp $

Fix build with GCC 10. It seems GCC changed how it parses _Pragma()
operators. Now it appears to be compatible with Clang but I don't know when
the change was introduced. Better not to use _Pragma() on GCC.

--- src/lib/ecore_con/dns.h.orig	2023-07-19 01:04:26.411743509 +0000
+++ src/lib/ecore_con/dns.h
@@ -138,14 +138,6 @@ extern int dns_debug;
 
 #define dns_quietinit(...) \
 	DNS_PRAGMA_PUSH DNS_PRAGMA_QUIET __VA_ARGS__ DNS_PRAGMA_POP
-#elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || __GNUC__ > 4
-#define DNS_PRAGMA_PUSH _Pragma("GCC diagnostic push")
-#define DNS_PRAGMA_QUIET _Pragma("GCC diagnostic ignored \"-Woverride-init\"")
-#define DNS_PRAGMA_POP _Pragma("GCC diagnostic pop")
-
-/* GCC parses the _Pragma operator less elegantly than clang. */
-#define dns_quietinit(...) \
-	({ DNS_PRAGMA_PUSH DNS_PRAGMA_QUIET __VA_ARGS__; DNS_PRAGMA_POP })
 #else
 #define DNS_PRAGMA_PUSH
 #define DNS_PRAGMA_QUIET
