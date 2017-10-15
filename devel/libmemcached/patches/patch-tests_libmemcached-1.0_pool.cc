$NetBSD: patch-tests_libmemcached-1.0_pool.cc,v 1.4.30.1 2017/10/15 11:26:40 spz Exp $

Use stdint.

--- tests/libmemcached-1.0/pool.cc.orig	2014-02-09 11:52:42.000000000 +0000
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
 
