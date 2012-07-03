$NetBSD: patch-bb_main.C,v 1.1 2012/07/03 18:44:45 joerg Exp $

--- bb/main.C.orig	2012-07-03 11:09:12.000000000 +0000
+++ bb/main.C
@@ -802,7 +802,7 @@ void battleBall::PlayOneRound(const gobL
 
 /*=========================================================================*/
 // A long and complicated main() function!
-main (int argc, char *argv[]) {
+int main (int argc, char *argv[]) {
   bb= new battleBall(argc,argv);
   bb->Play();
   delete bb;
