$NetBSD: patch-src_preproc_eqn_other.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/preproc/eqn/other.cpp.orig	2020-03-29 11:19:22.013530414 +0000
+++ src/preproc/eqn/other.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <stdlib.h>
 
 #include "eqn.h"
