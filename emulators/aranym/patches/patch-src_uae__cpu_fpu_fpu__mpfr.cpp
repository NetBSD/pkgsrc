$NetBSD: patch-src_uae__cpu_fpu_fpu__mpfr.cpp,v 1.1 2012/09/28 16:30:16 ryoon Exp $

On NetBSD, MPFR_USE_INTMAX_T is not defined in mpfr.h.
On ather platform (Gentoo Linux and DragonFly at least),
MPFR_USE_INTMAX_T is defined.

--- src/uae_cpu/fpu/fpu_mpfr.cpp.orig	2012-03-20 16:48:10.000000000 +0000
+++ src/uae_cpu/fpu/fpu_mpfr.cpp
@@ -18,6 +18,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#define MPFR_USE_INTMAX_T 1
+
 #include "sysdeps.h"
 #include <cstdio>
 #include "memory.h"
