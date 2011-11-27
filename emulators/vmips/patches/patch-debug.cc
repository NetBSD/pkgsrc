$NetBSD: patch-debug.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- debug.cc.orig	2011-11-27 02:49:35.000000000 +0000
+++ debug.cc
@@ -17,6 +17,8 @@ You should have received a copy of the G
 with VMIPS; if not, write to the Free Software Foundation, Inc.,
 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
+#include <stdlib.h>
+#include <string.h>
 #include "debug.h"
 #include "remotegdb.h"
 #include "cpu.h"
