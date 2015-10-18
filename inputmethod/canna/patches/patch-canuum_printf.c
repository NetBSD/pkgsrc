$NetBSD: patch-canuum_printf.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Appease prototype warnings.

--- canuum/printf.c.orig	2003-01-04 07:31:02.000000000 +0000
+++ canuum/printf.c
@@ -29,8 +29,18 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
 
 #include <stdio.h>
+#if STDC_HEADERS
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
+#endif /* STDC_HEADERS */
 #include "commonhd.h"
 #include "sdefine.h"
 #include "sheader.h"
