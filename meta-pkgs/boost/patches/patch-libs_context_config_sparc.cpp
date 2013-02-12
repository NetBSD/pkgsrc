$NetBSD: patch-libs_context_config_sparc.cpp,v 1.2 2013/02/12 21:07:22 adam Exp $

Add support for SPARC.

--- /dev/null	2012-11-04 15:17:53.000000000 +0100
+++ libs/context/config/sparc.cpp	2012-11-04 18:56:51.000000000 +0100
@@ -0,0 +1,11 @@
+// power.cpp
+//
+// Copyright (c) 2012 Steven Watanabe
+//
+// Distributed under the Boost Software License Version 1.0. (See
+// accompanying file LICENSE_1_0.txt or copy at
+// http://www.boost.org/LICENSE_1_0.txt)
+
+#if !defined(__sparc)
+#error "Not SPARC"
+#endif
