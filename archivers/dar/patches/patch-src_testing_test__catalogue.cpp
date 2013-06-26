$NetBSD: patch-src_testing_test__catalogue.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/test_catalogue.cpp.orig	2013-06-20 19:28:21.000000000 +0000
+++ src/testing/test_catalogue.cpp
@@ -258,7 +258,7 @@ void f2()
                                 if(i->is_more_recent_than(*w, 0))
 				{
                                     cout << "plus recent" << endl;
-				    cout << "new is " << deci(w->get_last_modif()).human() << " ref " << deci(i->get_last_modif()).human() << endl;
+				    cout << "new is " << libdar::deci(w->get_last_modif()).human() << " ref " << libdar::deci(i->get_last_modif()).human() << endl;
 				}
                                 else
                                     cout << "pas plus recent" << endl;
