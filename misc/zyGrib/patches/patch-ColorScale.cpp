$NetBSD: patch-ColorScale.cpp,v 1.1 2013/05/04 12:59:47 joerg Exp $

--- ColorScale.cpp.orig	2013-05-04 00:40:33.000000000 +0000
+++ ColorScale.cpp
@@ -16,6 +16,7 @@ You should have received a copy of the G
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
 
+#include <clocale>
 #include "ColorScale.h" 
 
 #include "zuFile.h" 
