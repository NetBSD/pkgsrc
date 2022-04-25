$NetBSD: patch-source3_printing_samba-bgqd.c,v 1.1 2022/04/25 16:25:02 jperkin Exp $

Fix includes for SIG*.

--- source3/printing/samba-bgqd.c.orig	2022-03-15 13:19:34.136201100 +0000
+++ source3/printing/samba-bgqd.c
@@ -15,6 +15,7 @@
  *  along with this program; if not, see <http://www.gnu.org/licenses/>.
  */
 
+#include "includes.h"
 #include "replace.h"
 #include "system/filesys.h"
 #include "lib/util/server_id.h"
