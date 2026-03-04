$NetBSD: patch-system_file__impl.h,v 1.1 2026/03/04 10:27:20 tsutsui Exp $

- appease -Wwrite-strings warnings

--- system/file_impl.h.orig	2026-03-03 20:52:57.460204971 +0000
+++ system/file_impl.h
@@ -61,7 +61,7 @@ protected:
 	virtual ARCINFO* MakeARCINFO(ARCFILE_ATOM&);
 	iterator SearchName(const char* f, const char* ext=0);
 public:
-	ARCFILE(char* fname);
+	ARCFILE(const char* fname);
 	void SetNext(ARCFILE* _next) { next = _next;}
 	ARCFILE* Next(void) { return next; }
 	void Init(void);
