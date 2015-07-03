$NetBSD: patch-libelemental_value.hh,v 1.1 2015/07/03 12:46:10 joerg Exp $

--- libelemental/value.hh.orig	2015-06-27 14:24:40.000000000 +0000
+++ libelemental/value.hh
@@ -142,12 +142,6 @@ class EntriesStream
 {
 public:
 
-	//! Constructs a new EntriesStream for an open FILE pointer.
-	EntriesStream (FILE* file) throw ();
-
-	//! Constructs a new EntriesStream for an open file descriptor.
-	EntriesStream (int fd) throw ();
-
 	//! Constructs a new EntriesStream for a stream buffer.
 	EntriesStream (std::streambuf& buf) throw ();
 
