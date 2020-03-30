$NetBSD: patch-src_preproc_eqn_text.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/preproc/eqn/text.cpp.orig	2020-03-29 11:19:04.623523486 +0000
+++ src/preproc/eqn/text.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <ctype.h>
 #include <stdlib.h>
 #include "eqn.h"
