$NetBSD: patch-tests_libmemcached-1.0_ketama.cc,v 1.4.30.1 2017/10/15 11:26:40 spz Exp $

Use stdint.

--- tests/libmemcached-1.0/ketama.cc.orig	2014-02-09 11:52:42.000000000 +0000
+++ tests/libmemcached-1.0/ketama.cc
@@ -33,6 +33,7 @@
  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  */
+#define __STDC_CONSTANT_MACROS
 
 #include <mem_config.h>
 #include <libtest/test.hpp>
@@ -45,6 +46,7 @@
 
 #include <tests/ketama.h>
 #include <tests/ketama_test_cases.h>
+#include <stdint.h>
 
 test_return_t ketama_compatibility_libmemcached(memcached_st *)
 {
