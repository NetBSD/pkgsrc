$NetBSD: patch-tests_libmemcached-1.0_pool.cc,v 1.2 2013/06/04 21:17:17 fhajny Exp $

--- tests/libmemcached-1.0/pool.cc.orig	2013-05-05 20:36:30.000000000 +0000
+++ tests/libmemcached-1.0/pool.cc
@@ -34,7 +34,7 @@
  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  */
-
+#define __STDC_CONSTANT_MACROS
 #include <config.h>
 #include <libtest/test.hpp>
 
@@ -44,6 +44,7 @@ using namespace libtest;
 #include <iostream>
 #include <string>
 #include <cerrno>
+#include <stdint.h>
 
 #include <semaphore.h>
 
