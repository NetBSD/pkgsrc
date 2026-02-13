$NetBSD: patch-src_debugger.c,v 1.1 2026/02/13 15:09:13 nia Exp $

Various fixes from
https://github.com/dmcoles/elkulator

--- src/debugger.c.orig	2026-02-13 13:35:14.833535357 +0000
+++ src/debugger.c
@@ -206,7 +206,7 @@ void debugout(char *s)
 
 void debugout(char *s)
 {
-        printf(s);
+        printf("%s", s);
 fflush(stdout);
 }
 
@@ -271,7 +271,7 @@ int dopaddr[256]=
 /*F0*/  BRA,  INDY, IND,  IMP,  ZP,   ZPX,  ZPX,  IMP,  IMP,  ABSY, IMP,  IMP,  ABS,  ABSX, ABSX, IMP,
 };
 
-uint8_t dopnamenmos[256][6]=
+char dopnamenmos[256][6]=
 {
 /*00*/  "BRK","ORA","HLT","SLO","NOP","ORA","ASL","SLO","PHP","ORA","ASL","ANC","NOP","ORA","ASL","SLO",
 /*10*/  "BPL","ORA","HLT","SLO","NOP","ORA","ASL","SLO","CLC","ORA","NOP","SLO","NOP","ORA","ASL","SLO",
@@ -495,7 +495,7 @@ void dodebugger()
                 c=ReadConsoleA(cinf,ins,255,(LPDWORD)&d,NULL);
                 ins[d]=0;
 #else
-		d=(int)fgets(ins,255,stdin);
+		fgets(ins, 255, stdin);
 #endif
                 d=0;
                 while (ins[d]!=32 && ins[d]!=0xA && ins[d]!=0xD && ins[d]!=0) d++;
