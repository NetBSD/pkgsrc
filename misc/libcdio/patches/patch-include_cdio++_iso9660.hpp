$NetBSD: patch-include_cdio++_iso9660.hpp,v 1.1 2019/04/29 17:22:04 adam Exp $

Work around namespace pollution on OpenSolaris (PR 43638, Aleksey Cheusov)

--- include/cdio++/iso9660.hpp.orig	2008-11-29 04:52:43.000000000 +0000
+++ include/cdio++/iso9660.hpp
@@ -33,6 +33,10 @@
 #include <cstring>
 using namespace std;
 
+#ifdef FS
+#undef FS
+#endif
+
 /** ISO 9660 class.
 */
 class ISO9660
