$NetBSD: patch-plug-ins_bracketing__to__hdr_br__core_ResponseSolver.hpp,v 1.1 2011/11/23 23:30:30 joerg Exp $

--- plug-ins/bracketing_to_hdr/br_core/ResponseSolver.hpp.orig	2011-11-23 16:54:11.000000000 +0000
+++ plug-ins/bracketing_to_hdr/br_core/ResponseSolver.hpp
@@ -44,7 +44,7 @@
 #include "Exception.hpp"        // IF_FAIL_EXCEPTION()
 #include "br_macros.hpp"
 #include "ResponseSolverBase.hpp"
-
+#include <cstring>
 
 namespace br {
 
