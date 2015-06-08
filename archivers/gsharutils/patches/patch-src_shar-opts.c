$NetBSD: patch-src_shar-opts.c,v 1.1 2015/06/08 23:13:52 joerg Exp $

--- src/shar-opts.c.orig	2015-06-08 20:10:51.000000000 +0000
+++ src/shar-opts.c
@@ -37,6 +37,12 @@
  *  You should have received a copy of the GNU General Public License along
  *  with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
+#include "config.h"
+#if ENABLE_NLS
+#ifdef HAVE_DCGETTEXT
+# include <gettext.h>
+#endif
+#endif
 
 #ifndef __doxygen__
 #define OPTION_CODE_COMPILE 1
