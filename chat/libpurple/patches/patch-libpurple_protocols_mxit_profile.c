$NetBSD: patch-libpurple_protocols_mxit_profile.c,v 1.1 2014/12/07 08:45:59 obache Exp $

* prevent to overwrite _XOPEN_SOURCE setting, and 500 is good enough for
  localtime_r(3).

--- libpurple/protocols/mxit/profile.c.orig	2014-11-23 16:41:26.000000000 +0000
+++ libpurple/protocols/mxit/profile.c
@@ -23,7 +23,9 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
  */
 
-#define		_XOPEN_SOURCE
+#ifndef		_XOPEN_SOURCE
+#define		_XOPEN_SOURCE 500
+#endif
 #include	<time.h>
 
 #include	"internal.h"
