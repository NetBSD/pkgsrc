$NetBSD: patch-gcc_config_sol2.h,v 1.1 2014/05/10 14:14:59 richard Exp $

--- gcc/config/sol2.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/sol2.h
@@ -171,12 +171,20 @@ along with GCC; see the file COPYING3.
 #define RDYNAMIC_SPEC "--export-dynamic"
 #endif
 
+#ifndef USE_GLD
+/* With Sun ld, use mapfile to enforce direct binding to libgcc_s unwinder.  */
+#define LINK_LIBGCC_MAPFILE_SPEC "-M %slibgcc-unwind.map"
+#else
+/* GNU ld doesn't support direct binding.  */
+#define LINK_LIBGCC_MAPFILE_SPEC ""
+#endif
+
 #undef  LINK_SPEC
 #define LINK_SPEC \
   "%{h*} %{v:-V} \
    %{!shared:%{!static:%{rdynamic: " RDYNAMIC_SPEC "}}} \
    %{static:-dn -Bstatic} \
-   %{shared:-G -dy %{!mimpure-text:-z text}} \
+   %{shared:-G -dy %{!mimpure-text:-z text} " LINK_LIBGCC_MAPFILE_SPEC "} \
    %{symbolic:-Bsymbolic -G -dy -z text} \
    %(link_arch) \
    %{Qy:} %{!Qn:-Qy}"
