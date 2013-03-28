$NetBSD: patch-lib_engine_addressbook_source-impl.h,v 1.1 2013/03/28 21:34:51 joerg Exp $

--- lib/engine/addressbook/source-impl.h.orig	2013-03-28 17:39:51.000000000 +0000
+++ lib/engine/addressbook/source-impl.h
@@ -206,7 +206,7 @@ template<typename BookType>
 void
 Ekiga::SourceImpl<BookType>::add_book (gmref_ptr<BookType> book)
 {
-  add_object (book);
+  this->add_object (book);
 
   add_connection (book, book->contact_added.connect (sigc::bind<0> (contact_added.make_slot (), book)));
 
