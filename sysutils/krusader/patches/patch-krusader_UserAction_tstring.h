$NetBSD: patch-krusader_UserAction_tstring.h,v 1.1 2012/12/22 02:31:33 joerg Exp $

--- krusader/UserAction/tstring.h.orig	2012-12-22 01:27:56.000000000 +0000
+++ krusader/UserAction/tstring.h
@@ -98,7 +98,7 @@ TagString_t<T>& TagString_t<T>::operator
 	str+=s.str;
 	const unsigned disp=length();
 	for(typename taglist::const_iterator it=s.tags.begin(),end=s.tags.end();it!=end;++it) {
-		tags.push_back(make_pair((*it).first+disp,(*it).second));
+		tags.push_back(std::make_pair((*it).first+disp,(*it).second));
 	}
 	return *this;
 }
@@ -107,7 +107,7 @@ template <class T>
 void TagString_t<T>::insertTag(uint pos,const T& t)
 {
 	assert(pos<=length());
-	tags.push_back(make_pair(pos,t));
+	tags.push_back(std::make_pair(pos,t));
 }
 
 #endif
