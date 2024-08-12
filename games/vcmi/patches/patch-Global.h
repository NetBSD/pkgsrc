$NetBSD: patch-Global.h,v 1.1 2024/08/12 11:19:25 nia Exp $

Add support for NetBSD.

--- Global.h.orig	2024-08-11 18:07:04.139480978 +0000
+++ Global.h
@@ -41,6 +41,10 @@ static_assert(sizeof(bool) == 1, "Bool n
 #  define VCMI_UNIX
 #  define VCMI_XDG
 #  define VCMI_FREEBSD
+#elif defined(__NetBSD__)
+#  define VCMI_UNIX
+#  define VCMI_XDG
+#  define VCMI_NETBSD
 #elif defined(__OpenBSD__)
 #  define VCMI_UNIX
 #  define VCMI_XDG
