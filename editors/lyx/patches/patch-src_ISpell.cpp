$NetBSD: patch-src_ISpell.cpp,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- src/ISpell.cpp.orig	2013-05-09 12:16:25.000000000 +0000
+++ src/ISpell.cpp
@@ -34,8 +34,6 @@
 # include <sys/time.h>
 #endif
 
-using boost::shared_ptr;
-
 using namespace std;
 using namespace lyx::support;
 
@@ -51,8 +49,8 @@ public:
 		     int * in, int * out, int * err)
 		: params(p), lang(l), pipein(in), pipeout(out), pipeerr(err) {}
 	///
-	virtual shared_ptr<ForkedProcess> clone() const {
-		return shared_ptr<ForkedProcess>(new LaunchIspell(*this));
+	virtual boost::shared_ptr<ForkedProcess> clone() const {
+		return boost::shared_ptr<ForkedProcess>(new LaunchIspell(*this));
 	}
 	///
 	int start();
