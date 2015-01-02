$NetBSD: patch-lib_fdbuf_fdobuf.h,v 1.1 2015/01/02 04:38:20 schmonz Exp $

Provide uid_t and gid_t definitions.

--- lib/fdbuf/fdobuf.h.orig    2015-01-02 02:59:35.000000000 +0000
+++ lib/fdbuf/fdobuf.h
@@ -14,6 +14,8 @@
 // along with this program; if not, write to the Free Software
 // Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
+#include <sys/types.h>
+
 #ifndef FDBUF__FDOBUF__H__
 #define FDBUF__FDOBUF__H__
 
