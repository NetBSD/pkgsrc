$NetBSD: patch-gcc_config_openbsd-libpthread.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/config/openbsd-libpthread.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/openbsd-libpthread.h
@@ -18,5 +18,5 @@
    along with GCC; see the file COPYING3.  If not see
    <http://www.gnu.org/licenses/>.  */
 
-#define OBSD_LIB_SPEC "%{!shared:%{pthread:-lpthread} -lc}"
+#define OBSD_LIB_SPEC "%{pthread:-lpthread%{!shared:%{p|pg:_p}}} %{!shared:-lc%{p:_p}%{!p:%{pg:_p}}}"
 
