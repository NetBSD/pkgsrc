$NetBSD: patch-tests_libmemcached-1.0_pool.cc,v 1.3 2013/09/12 14:20:56 fhajny Exp $

Use stdint.
--- tests/libmemcached-1.0/pool.cc.orig	2013-04-03 04:22:00.000000000 +0000
+++ tests/libmemcached-1.0/pool.cc
@@ -34,6 +34,7 @@
  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  */
+#define __STDC_CONSTANT_MACROS
 
 #include <mem_config.h>
 #include <libtest/test.hpp>
@@ -44,6 +45,7 @@ using namespace libtest;
 #include <iostream>
 #include <string>
 #include <cerrno>
+#include <stdint.h>
 
 #include <semaphore.h>
 
