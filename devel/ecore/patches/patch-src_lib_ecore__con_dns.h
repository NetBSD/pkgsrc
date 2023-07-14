$NetBSD: patch-src_lib_ecore__con_dns.h,v 1.1 2023/07/14 09:54:08 pho Exp $

Fix build with GCC 10. It seems GCC changed how it parses _Pragma()
operators. Now it appears to be compatible with Clang but I don't know when
the change was introduced. Better not to use _Pragma() on GCC.

--- src/lib/ecore_con/dns.h.orig	2023-07-14 09:33:19.288248573 +0000
+++ src/lib/ecore_con/dns.h
@@ -131,21 +131,14 @@ extern int dns_debug;
  *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
-#if defined(__clang__) || __GNUC__ >= 10
+#if defined(__clang__)
 #define DNS_PRAGMA_PUSH _Pragma("clang diagnostic push")
 #define DNS_PRAGMA_QUIET _Pragma("clang diagnostic ignored \"-Winitializer-overrides\"")
 #define DNS_PRAGMA_POP _Pragma("clang diagnostic pop")
 
 #define dns_quietinit(...) \
 	DNS_PRAGMA_PUSH DNS_PRAGMA_QUIET __VA_ARGS__ DNS_PRAGMA_POP
-#elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || __GNUC__ > 4
-#define DNS_PRAGMA_PUSH _Pragma("GCC diagnostic push")
-#define DNS_PRAGMA_QUIET _Pragma("GCC diagnostic ignored \"-Woverride-init\"")
-#define DNS_PRAGMA_POP _Pragma("GCC diagnostic pop")
 
-/* GCC parses the _Pragma operator less elegantly than clang. */
-#define dns_quietinit(...) \
-	({ DNS_PRAGMA_PUSH DNS_PRAGMA_QUIET __VA_ARGS__; DNS_PRAGMA_POP })
 #else
 #define DNS_PRAGMA_PUSH
 #define DNS_PRAGMA_QUIET
