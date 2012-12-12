$NetBSD: patch-screen.c,v 1.1 2012/12/12 13:21:42 wiz Exp $

Fix compilation on NetBSD, where init_tabs is not suitable for assignment.

--- screen.c.orig	2009-03-08 14:46:47.000000000 +0000
+++ screen.c
@@ -92,13 +93,14 @@ static int try_sequence( char *seq, wcha
  */
 static int next_tab_stop( int in )
 {
+	int itabs = init_tabs;
 	/*
 	  Assume tab stops every 8 characters if undefined
 	*/
-	if( init_tabs <= 0 )
-		init_tabs = 8;
+	if( itabs <= 0 )
+		itabs = 8;
 				
-	return ( (in/init_tabs)+1 )*init_tabs;
+	return ( (in/itabs)+1 )*itabs;
 }
 
 /**
