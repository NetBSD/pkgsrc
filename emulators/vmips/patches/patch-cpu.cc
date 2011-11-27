$NetBSD: patch-cpu.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- cpu.cc.orig	2011-11-27 02:48:15.000000000 +0000
+++ cpu.cc
@@ -17,6 +17,7 @@ You should have received a copy of the G
 with VMIPS; if not, write to the Free Software Foundation, Inc.,
 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
+#include <string.h>
 #include "cpu.h"
 #include "cpzero.h"
 #include "debug.h"
