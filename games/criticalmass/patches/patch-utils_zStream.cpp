$NetBSD: patch-utils_zStream.cpp,v 1.1 2011/11/24 14:09:47 joerg Exp $

--- utils/zStream.cpp.orig	2011-11-24 00:46:06.000000000 +0000
+++ utils/zStream.cpp
@@ -12,6 +12,7 @@
 // ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 // FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
 //
+#include <stdlib.h>
 #include <Trace.hpp>
 #include <Endian.hpp>
 #include <zStream.hpp>
