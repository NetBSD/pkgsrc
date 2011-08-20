$NetBSD: patch-hello.cpp,v 1.1 2011/08/20 15:33:37 joerg Exp $

--- hello.cpp.orig	2000-04-06 04:48:53.000000000 +0000
+++ hello.cpp
@@ -78,7 +78,7 @@ void Output(SDL_Surface *screen, const c
 	}
 }
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
 	SDL_Surface *screen;
 	int x, y, i;
