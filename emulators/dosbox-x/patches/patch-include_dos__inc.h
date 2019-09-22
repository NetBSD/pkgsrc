$NetBSD: patch-include_dos__inc.h,v 1.1 2019/09/22 09:54:14 nia Exp $

Use ftello and fseeko on NetBSD.

--- include/dos_inc.h.orig	2019-04-06 04:12:19.000000000 +0000
+++ include/dos_inc.h
@@ -290,6 +290,10 @@ static INLINE Bit16u DOS_PackDate(Bit16u
  #define fopen64 fopen
  #define ftello64 ftello
  #define fseeko64 fseeko
+#elif defined (__NetBSD__)
+ #define fopen64 fopen
+ #define ftello64 ftello
+ #define fseeko64 fseeko
 #elif defined (_MSC_VER)
  #define fopen64 fopen
  #if (_MSC_VER >= 1400)
