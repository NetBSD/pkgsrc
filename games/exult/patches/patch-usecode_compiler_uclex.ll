$NetBSD: patch-usecode_compiler_uclex.ll,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/compiler/uclex.ll.orig	2011-11-25 17:49:15.000000000 +0000
+++ usecode/compiler/uclex.ll
@@ -23,6 +23,7 @@ along with this program; if not, write t
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
+#include <cstring>
 #include <string>
 #include <vector>
 #include "ucparse.h"
