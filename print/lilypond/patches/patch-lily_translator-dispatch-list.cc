$NetBSD: patch-lily_translator-dispatch-list.cc,v 1.2 2013/06/16 20:46:52 joerg Exp $

Issue 2208.

--- lily/translator-dispatch-list.cc.orig	2013-01-04 13:41:56.000000000 +0000
+++ lily/translator-dispatch-list.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "translator-dispatch-list.hh"
 #include "engraver.hh"
 
@@ -32,7 +33,7 @@ Engraver_dispatch_list::apply (Grob_info
       if (e.engraver_ == origin)
         continue;
 
-      (*e.function_) (e.engraver_, gi);
+      (e.engraver_->*e.function_)(gi);
     }
 }
 
