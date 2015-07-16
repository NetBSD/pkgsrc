$NetBSD: patch-gcc_config_netbsd.h,v 1.1 2015/07/16 12:03:36 ryoon Exp $

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
@@ -175,3 +178,9 @@ along with GCC; see the file COPYING3.  
 
 #undef WINT_TYPE
 #define WINT_TYPE "int"
+
+#undef SUBTARGET_INIT_BUILTINS
+#define SUBTARGET_INIT_BUILTINS			\
+do {						\
+  netbsd_patch_builtins ();			\
+} while(0)
