$NetBSD: patch-src_dosbox.cpp,v 1.1 2017/09/16 03:27:20 maya Exp $

Default to 8192 block size - sounds better

--- src/dosbox.cpp.orig	2010-05-10 17:43:54.000000000 +0000
+++ src/dosbox.cpp
@@ -454,7 +454,7 @@ void DOSBOX_Init(void) {
 
 	const char *blocksizes[] = {
 		 "1024", "2048", "4096", "8192", "512", "256", 0};
-	Pint = secprop->Add_int("blocksize",Property::Changeable::OnlyAtStart,1024);
+	Pint = secprop->Add_int("blocksize",Property::Changeable::OnlyAtStart,8192);
 	Pint->Set_values(blocksizes);
 	Pint->Set_help("Mixer block size, larger blocks might help sound stuttering but sound will also be more lagged.");
 
