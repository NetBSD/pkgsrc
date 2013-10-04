$NetBSD: patch-libtest__exception.hpp,v 1.1 2013/10/04 07:03:37 fhajny Exp $

va_args fix

--- libtest/exception.hpp.orig	2013-05-03 04:24:12.000000000 +0000
+++ libtest/exception.hpp
@@ -33,7 +33,7 @@
  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  */
-
+#include <cstdarg>
 #pragma once
 
 namespace libtest {
