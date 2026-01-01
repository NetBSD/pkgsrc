$NetBSD: patch-ttf.h,v 1.1 2026/01/01 23:59:16 dholland Exp $

Avoid UB in FoundryName()

--- ttf.h~	2026-01-01 23:05:18.789393675 +0000
+++ ttf.h
@@ -24,7 +24,7 @@ namespace ttf {
 	Face (const std::string &filename);
 	~Face (void);
 	const char         *FontFamilyName (void) const;
-	const char         *FoundryName (void) const;
+	std::string         FoundryName (void) const;
 	const char         *Weight (void) const;
 	const char         *Width (void) const;
 	xlfdcontainer       xlfdnames;
