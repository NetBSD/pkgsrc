$NetBSD: patch-src_lib_WPS4.cpp,v 1.1 2012/02/16 18:04:08 hans Exp $

--- src/lib/WPS4.cpp.orig	2011-04-04 21:34:27.000000000 +0200
+++ src/lib/WPS4.cpp	2012-01-27 12:03:55.579804437 +0100
@@ -198,10 +198,10 @@ bool WPS4Parser::readFODPage(WPXInputStr
 	}
 	input->seek(page_offset, WPX_SEEK_SET);	
 	
-	uint32_t fcFirst; /* Byte number of first character covered by this page 
-			     of formatting information */	
+	/* Byte number of first character covered by this page 
+	   of formatting information */	
 			    
-	fcFirst = readU32(input);
+	(void) readU32(input);
 	
 	int first_fod = FODs->size();
 
