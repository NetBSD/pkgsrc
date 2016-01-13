$NetBSD: patch-libpurple_protocols_mxit_profile.c,v 1.2 2016/01/13 22:25:38 wiz Exp $

* prevent overwriting _XOPEN_SOURCE setting
  otherwise breaks build on NetBSD due to missing struct sockaddr_storage definition

--- libpurple/protocols/mxit/profile.c.orig	2015-12-31 23:19:41.000000000 +0000
+++ libpurple/protocols/mxit/profile.c
@@ -23,7 +23,6 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
  */
 
-#define		_XOPEN_SOURCE	1
 #include	<time.h>
 
 #include	"internal.h"
