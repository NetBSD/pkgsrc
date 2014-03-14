$NetBSD: patch-src_include_strutil.h,v 1.2 2014/03/14 14:39:22 mef Exp $

Don't depend on implicit boolean conversion for streams.

--- src/include/strutil.h.orig	2013-09-17 19:23:48.000000000 +0000
+++ src/include/strutil.h
@@ -207,7 +207,8 @@ inline bool read_until_delim( char delim
 /// Reads a string up to the given delimiter.
 inline bool read_until_delim( char delim, std::istream & istrm, std::string & ref )
 {
-	return std::getline( istrm, ref, delim );
+	std::getline( istrm, ref, delim );
+	return istrm.good() || istrm.eof();
 }
 
 /// For reading from a string with tokens separated by a char. Used to load CSV files.
@@ -220,7 +221,7 @@ bool read_until_delim( char delim, std::
 	}
 	imemstream sstrm( parsed_str );
 	sstrm >> ref ;
-	return sstrm ;
+	return sstrm.good() || sstrm.eof();
 }
 
 /// Same, with a default value if there is nothing to read.
@@ -237,7 +238,7 @@ bool read_until_delim( char delim, std::
 	}
 	imemstream sstrm( parsed_str );
 	sstrm >> ref ;
-	return sstrm ;
+	return sstrm.good() || sstrm.eof();
 }
 
 /// For reading from a string with tokens separated by a char to a fixed-size array.
@@ -246,7 +247,7 @@ bool read_until_delim( char delim, std::
 {
 	istrm.getline( ref, DtTyp< Tp >::Size, delim );
 	// Should we return an error if buffer is too small?
-	return istrm ;
+	return istrm.good() || istrm.eof();
 }
 
 /// Same, with a default value if there is nothing to read. Fixed-size array.
@@ -259,7 +260,7 @@ bool read_until_delim( char delim, std::
 		strncpy( ref, dflt, DtTyp< Tp >::Size - 1 );
 	}
 	// Should we return an error if buffer is too small?
-	return istrm;
+	return istrm.good() || istrm.eof();
 }
 
 // ----------------------------------------------------------------------------
