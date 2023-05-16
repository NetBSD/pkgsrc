$NetBSD: patch-src_debugger.c,v 1.1 2023/05/16 06:01:45 thorpej Exp $

Squelch "passing arguments to 'DEBUGRenderCmdLine' without a prototype is
deprecated in all versions of C and is not supported in C2x" error
thrown by Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Xcode 14.3).

--- src/debugger.c.orig	2023-05-16 05:55:48
+++ src/debugger.c	2023-05-16 05:56:11
@@ -36,7 +36,7 @@ static void DEBUGRenderCmdLine();
 static void DEBUGRenderVRAM(int y, int data);
 static void DEBUGRenderCode(int lines,int initialPC);
 static void DEBUGRenderStack(int bytesCount);
-static void DEBUGRenderCmdLine();
+static void DEBUGRenderCmdLine(int x, int width, int height);
 static bool DEBUGBuildCmdLine(SDL_Keycode key);
 static void DEBUGExecCmd();
 
