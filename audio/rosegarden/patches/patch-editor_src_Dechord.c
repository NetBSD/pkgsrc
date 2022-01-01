$NetBSD: patch-editor_src_Dechord.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Ues standard headers.
Use ctype functions correctly.

--- editor/src/Dechord.c~	1997-02-24 21:43:40.000000000 +0000
+++ editor/src/Dechord.c
@@ -22,6 +22,8 @@
 		 yield single notes
 */
 
+#include <ctype.h>
+
 #include "Dechord.h"
 #ifdef USE_POSIX_REGEXP
 
@@ -170,7 +172,7 @@ Pitch NoteToPitch(char Note, ClefTag cur
   Pitch p;
   Begin("NoteToPitch");
 
-  Note = toupper((int)Note);
+  Note = toupper((unsigned char)Note);
   if((Note < 'A') && (Note > 'G')) Error("wrong note");
 
   p = Note - 'E' /* - 7 ?? */ + ClefPitchOffset(currentClef);
@@ -512,9 +514,9 @@ Chord* SpellChord(char ChordString[], Cl
   /* So the Find<x> functions will only see what is "after" the root,
      ie from "Cmaj7" we just want to see "maj7" */
 
-  while(isspace(subChordString[0])) subChordString++;
+  while(isspace((unsigned char)subChordString[0])) subChordString++;
 
-  if(isupper((int)RootNote[0])) {
+  if(isupper((unsigned char)RootNote[0])) {
 
     if(Regexec(GetAltBass, ChordString) == REG_MATCHED) { /* Get possible altered bass */
 #ifdef USE_POSIX_REGEXP
