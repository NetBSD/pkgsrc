$NetBSD: patch-dvorakng.cpp,v 1.1 2026/08/30 09:14:25 he Exp $

Do not implicitly assume that "char" is signed.
Sprinkle "const" to deal with string constants and get rid of warnings.

--- dvorakng.cpp.orig	2026-08-30 08:59:25.654701733 +0000
+++ dvorakng.cpp
@@ -117,7 +117,7 @@ char keymap[] = //{{{
@@ -117,7 +117,7 @@ char keymap[] = //{{{
 	0
 }; //}}}
 
-char colormap[] = //{{{
+signed char colormap[] = //{{{
 {
 	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, -5, -5, -4, -4, -3, -3, -2, -2, 2, 2, 3, 4, 5,
 	0, 0, 0, 0,  0, 5, -5, -4, -3, -2, -2, 2, 2, 3, 4, 5, 0, 0, 0, 0, 0, 2, 0, /*0,*/ 5, /*-5,*/ -4, -3, -2, -2, 2, 2, 3, 4, 5, 0, 0
@@ -139,7 +139,7 @@ class	THSEntry //{{{
 		THSEntry( UINT32 hits, UINT32 misses, UINT32 timev, UINT32 lesson );
 		~THSEntry();
 
-		void	Print( UINT32 row, UINT32 column, UINT32 color, char *msg ) const;
+		void	Print( UINT32 row, UINT32 column, UINT32 color, const char *msg ) const;
 		void	PrintHistory( UINT32 row ) const;
 		float	GetSpeed() const;
 
@@ -253,9 +253,9 @@ class	TLessonManager //{{{
 THSManager			HSManager( (string)( getpwuid( getuid() )->pw_dir ) + "/.dvorakng/history" );
 TLessonManager	LessonManager;
 
-char	*OnOffFrom01( bool par ) //{{{
+const char	*OnOffFrom01( bool par ) //{{{
 {
-	char	*res = "";
+	const char	*res = "";
 
 	if( par == true )
 	{
@@ -2233,7 +2233,7 @@ THSEntry::THSEntry( UINT32 hits, UINT32 
 THSEntry::~THSEntry() //{{{
 {
 } //}}}
-void	THSEntry::Print( UINT32 row, UINT32 column, UINT32 color, char *msg ) const //{{{
+void	THSEntry::Print( UINT32 row, UINT32 column, UINT32 color, const char *msg ) const //{{{
 {
 	float	ratio = CalcRatio( FHits, FMisses );
 	float	speed = GetSpeed();
