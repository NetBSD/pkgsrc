$NetBSD: patch-include_rb__gsl__common.h,v 1.1 2014/03/26 13:25:26 taca Exp $

Fix for Ruby 2.1.

--- include/rb_gsl_common.h.orig	2014-03-25 15:47:30.000000000 +0000
+++ include/rb_gsl_common.h
@@ -14,6 +14,11 @@
 
 #include "rb_gsl_config.h"
 #include "ruby.h"
+#ifdef HAVE_RUBY_IO_H
+#include "ruby/version.h"
+#else
+#include "version.h"
+#endif
 #include <ctype.h>
 #include <gsl/gsl_errno.h>
 #include <gsl/gsl_version.h>
