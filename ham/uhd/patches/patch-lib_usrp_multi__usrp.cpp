$NetBSD: patch-lib_usrp_multi__usrp.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/usrp/multi_usrp.cpp.orig	2020-05-09 15:19:48.569394841 +0000
+++ lib/usrp/multi_usrp.cpp
@@ -216,7 +216,7 @@ static gain_fcns_t make_gain_fcns_from_s
     gain_fcns_t gain_fcns;
     gain_fcns.get_range = boost::bind(&get_gain_range, subtree);
     gain_fcns.get_value = boost::bind(&get_gain_value, subtree);
-    gain_fcns.set_value = boost::bind(&set_gain_value, subtree, _1);
+    gain_fcns.set_value = boost::bind(&set_gain_value, subtree, boost::placeholders::_1);
     return gain_fcns;
 }
 
