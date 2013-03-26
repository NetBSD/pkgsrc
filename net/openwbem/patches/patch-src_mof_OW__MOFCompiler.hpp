$NetBSD: patch-src_mof_OW__MOFCompiler.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/mof/OW_MOFCompiler.hpp.orig	2013-03-25 15:37:55.000000000 +0000
+++ src/mof/OW_MOFCompiler.hpp
@@ -35,6 +35,7 @@
 #ifndef OW_MOF_COMPILER_HPP_INCLUDE_GUARD_
 #define OW_MOF_COMPILER_HPP_INCLUDE_GUARD_
 #include "OW_config.h"
+#include "OW_List.hpp"
 #include "OW_CIMOMHandleIFC.hpp"
 #include "OW_String.hpp"
 #include "OW_MOFParserErrorHandlerIFC.hpp"
