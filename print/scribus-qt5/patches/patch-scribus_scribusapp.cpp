$NetBSD: patch-scribus_scribusapp.cpp,v 1.1 2024/11/12 21:46:56 markd Exp $

.../scribus/scribusapp.cpp:285:18: error: ambiguous overload for 'operator==' (operand types
 are 'const QChar' and 'const char [2]')
  285 |    if (arg.at(0) == "-")

--- scribus/scribusapp.cpp.orig	2024-06-15 14:22:33.000000000 +0000
+++ scribus/scribusapp.cpp
@@ -282,7 +282,7 @@ void ScribusQApp::parseCommandLine()
 		}
 		else
 		{ //argument is not a known option, but either positional parameter or invalid.
-			if (arg.at(0) == "-")
+			if (arg.at(0) == QString("-"))
 			{
 				std::cout << tr("Invalid argument: %1").arg(arg).toLocal8Bit().data() << std::endl;
 				std::exit(EXIT_FAILURE);
