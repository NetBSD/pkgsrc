$NetBSD: patch-iftop.h,v 1.1 2017/12/11 10:44:17 manu Exp $

Enable BSD features for NetBSD
From <Jean-Jacques.Puig@espci.fr>

--- iftop.h
+++ iftop.h
@@ -19,7 +19,7 @@
 #if !defined s6_addr32 && defined __sun__
 #	define s6_addr32 _S6_un._S6_u32
 #elif !defined s6_addr32 && \
-		( defined __OpenBSD__ || defined __FreeBSD__ )
+		( defined __OpenBSD__ || defined __FreeBSD__ || defined __NetBSD__ )
 #	define s6_addr32 __u6_addr.__u6_addr32
 #endif	/* !defined s6_addr32 */
 
