$NetBSD: patch-lib_StatementBlock.cpp,v 1.1 2022/01/27 17:39:45 nros Exp $

* fix build brakeage

--- lib/StatementBlock.cpp.orig	2022-01-27 08:09:06.446355683 +0000
+++ lib/StatementBlock.cpp
@@ -230,8 +230,8 @@ int StatementBlock::execIntern(QoreValue
                 if ((*i).second) {
                     {
                         // instantiate exception for on_error blocks as an implicit arg
-                        unique_ptr<SingleArgvContextHelper> argv_helper;
-                        unique_ptr<CatchExceptionHelper> ex_helper;
+                        std::unique_ptr<SingleArgvContextHelper> argv_helper;
+                        std::unique_ptr<CatchExceptionHelper> ex_helper;
                         if (type == OBE_Error) {
                             QoreException* except = xsink->getException();
                             assert(except);
