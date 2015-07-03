$NetBSD: patch-libelemental_value.cc,v 1.1 2015/07/03 12:46:10 joerg Exp $

--- libelemental/value.cc.orig	2015-06-27 14:24:42.000000000 +0000
+++ libelemental/value.cc
@@ -23,7 +23,6 @@
 #include <libelemental/value.hh>
 #include <libelemental/value-types.hh>
 
-#include <ext/stdio_filebuf.h>
 #include <glibmm/utility.h>
 #include <pango/pango-attributes.h>
 
@@ -130,19 +129,6 @@ EntriesView::max_name_length = 0;
 //******************************************************************************
 // class EntriesStream
 
-
-EntriesStream::EntriesStream (FILE* file) throw ()
-:	buf (new __gnu_cxx::stdio_filebuf<char> (file, std::ios_base::out)),
-	buf_owned (true), os (*new std::ostream (buf)), os_owned (true)
-{}
-
-
-EntriesStream::EntriesStream (int fd) throw ()
-:	buf (new __gnu_cxx::stdio_filebuf<char> (fd, std::ios_base::out)),
-	buf_owned (true), os (*new std::ostream (buf)), os_owned (true)
-{}
-
-
 EntriesStream::EntriesStream (std::streambuf& buf_) throw ()
 :	buf (&buf_), buf_owned (false),
 	os (*new std::ostream (buf)), os_owned (true)
