$NetBSD: patch-utils_rand__tags.cpp,v 1.1 2016/12/17 14:18:32 joerg Exp $

Checking for negative pointers doesn't make sense.

--- utils/rand_tags.cpp.orig	2016-12-16 17:30:02.495417195 +0000
+++ utils/rand_tags.cpp
@@ -366,7 +366,7 @@ struct tagdef oneoff_def[] = {
 
 static void rhtml_contents(std::string &htmls, int *ntags, int *ndistinct_tags)
 {
-	if ((*ntags <= 0) && (ndistinct_tags <= 0))
+	if ((*ntags <= 0) && (ndistinct_tags == 0))
 		return; 
 	if (random() % 10 == 1) {
 		anchor(htmls);
