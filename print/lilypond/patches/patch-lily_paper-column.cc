$NetBSD: patch-lily_paper-column.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-column.cc.orig	2013-06-16 19:06:43.000000000 +0000
+++ lily/paper-column.cc
@@ -227,7 +227,7 @@ Paper_column::print (SCM p)
 {
   Paper_column *me = dynamic_cast<Paper_column *> (unsmob_grob (p));
 
-  string r = to_string (Paper_column::get_rank (me));
+  string r = ::to_string (Paper_column::get_rank (me));
 
   Moment *mom = unsmob_moment (me->get_property ("when"));
   string when = mom ? mom->to_string () : "?/?";
