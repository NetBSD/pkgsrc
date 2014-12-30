$NetBSD: patch-ColorScale.cpp,v 1.2 2014/12/30 08:50:55 plunky Exp $

--- ColorScale.cpp.orig	2014-11-02 00:01:52.000000000 +0000
+++ ColorScale.cpp
@@ -16,6 +16,7 @@ You should have received a copy of the G
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
 
+#include <clocale>
 #include "ColorScale.h" 
 
 #include "zuFile.h" 
