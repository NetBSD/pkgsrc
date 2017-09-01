$NetBSD: patch-utils_rand__tags.cpp,v 1.2 2017/09/01 07:52:02 wiz Exp $

https://github.com/trendmicro/tlsh/commit/fb076b0f62b620e0de4cf95a5ccb81f21d4abc24#diff-02ad04ab1753a2119772311c29f24d23

--- utils/rand_tags.cpp.orig	2016-12-16 17:30:02.495417195 +0000
+++ utils/rand_tags.cpp
@@ -366,7 +366,7 @@ struct tagdef oneoff_def[] = {
 
 static void rhtml_contents(std::string &htmls, int *ntags, int *ndistinct_tags)
 {
-	if ((*ntags <= 0) && (ndistinct_tags <= 0))
+	if ((*ntags <= 0) && (*ndistinct_tags <= 0))
 		return; 
 	if (random() % 10 == 1) {
 		anchor(htmls);
