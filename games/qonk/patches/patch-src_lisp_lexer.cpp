$NetBSD: patch-src_lisp_lexer.cpp,v 1.2 2012/05/23 06:16:00 dholland Exp $

Add missing headers.

--- src/lisp/lexer.cpp.orig	2007-09-14 05:43:03.000000000 +0000
+++ src/lisp/lexer.cpp
@@ -19,6 +19,8 @@
 //  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 #include <sstream>
 #include <stdexcept>
+#include <cstring>
+#include <cstdio>
 
 #include "lexer.hpp"
 #include "translation.hpp"
