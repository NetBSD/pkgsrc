$NetBSD: patch-gcc_config_netbsd.h,v 1.1 2017/05/03 00:21:03 maya Exp $

when using shared, link against libc
another unexplained change`

--- gcc/config/netbsd.h.orig	2014-01-02 22:23:26.000000000 +0000
+++ gcc/config/netbsd.h
@@ -17,6 +17,9 @@ You should have received a copy of the G
 along with GCC; see the file COPYING3.  If not see
 <http://www.gnu.org/licenses/>.  */
 
+
+#include "netbsd-protos.h"
+
 /* TARGET_OS_CPP_BUILTINS() common to all NetBSD targets.  */
 #define NETBSD_OS_CPP_BUILTINS_COMMON()		\
   do						\
@@ -96,6 +99,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
@@ -109,6 +113,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
@@ -175,3 +180,9 @@ along with GCC; see the file COPYING3.  
 
 #undef WINT_TYPE
 #define WINT_TYPE "int"
+
+#undef SUBTARGET_INIT_BUILTINS
+#define SUBTARGET_INIT_BUILTINS			\
+do {						\
+  netbsd_patch_builtins ();			\
+} while(0)
