$NetBSD: patch-gcc_config_netbsd.h,v 1.2 2018/01/25 23:27:30 maya Exp $

Handle netbsd's compatibility non-C99 cabs (causes link
failure with gfortran)

--- gcc/config/netbsd.h.orig	2017-09-29 21:34:00.000000000 +0000
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
@@ -181,6 +184,12 @@ along with GCC; see the file COPYING3.  
 #undef WINT_TYPE
 #define WINT_TYPE "int"
 
+#undef SUBTARGET_INIT_BUILTINS
+#define SUBTARGET_INIT_BUILTINS			\
+do {						\
+  netbsd_patch_builtins ();			\
+} while(0)
+
 #undef  SUBTARGET_INIT_BUILTINS
 #define SUBTARGET_INIT_BUILTINS						\
   do {									\
