$NetBSD: patch-cone_cursesmessage.C,v 1.1 2013/11/11 16:42:21 joerg Exp $

--- cone/cursesmessage.C.orig	2013-11-10 20:55:41.000000000 +0000
+++ cone/cursesmessage.C
@@ -3761,13 +3761,13 @@ bool CursesMessage::decrypt(std::string 
 			gi.passphrase_fd=passphrase_fd.c_str();
 		}
 
-		gi.input_func= &tempSaveText.input_func;
+		gi.input_func= &DecryptSaveText::input_func;
 		gi.input_func_arg= &tempSaveText;
 
-		gi.output_func= &tempSaveText.output_func;
+		gi.output_func= &DecryptSaveText::output_func;
 		gi.output_func_arg= &tempSaveText;
 
-		gi.errhandler_func= &tempSaveText.err_func;
+		gi.errhandler_func= &DecryptSaveText::err_func;
 		gi.errhandler_arg= &tempSaveText;
 
 		opts.push_back(std::string("--no-tty"));
