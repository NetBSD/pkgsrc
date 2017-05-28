$NetBSD: patch-gcc_config_netbsd.h,v 1.2 2017/05/28 01:42:03 maya Exp $

when using shared, link against libc.
always link against libgcc

+++ gcc/config/netbsd.h
@@ -96,6 +96,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
@@ -109,6 +110,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
@@ -133,7 +135,7 @@ along with GCC; see the file COPYING3.  
      %{p: -lgcc_p}		\
      %{pg: -lgcc_p}}"
 #else
-#define NETBSD_LIBGCC_SPEC "%{!shared:%{!symbolic: -lgcc}}"
+#define NETBSD_LIBGCC_SPEC "-lgcc"
 #endif
 
 #undef LIBGCC_SPEC
