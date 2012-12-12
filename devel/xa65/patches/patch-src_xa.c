$NetBSD: patch-src_xa.c,v 1.1 2012/12/12 13:16:02 wiz Exp $

Rename internal getline so it doesn't conflict with libc's

--- src/xa.c.orig	2009-01-21 16:57:32.000000000 +0000
+++ src/xa.c
@@ -87,7 +87,7 @@ static int pass2(void);
 static int puttmp(int);
 static int puttmps(signed char *, int);
 static void chrput(int);
-static int getline(char *);
+static int xagetline(char *);
 static void lineout(void);
 static long ga_p1(void);
 static long gm_p1(void);
@@ -763,7 +763,7 @@ static int pass1(void)
 	temp_er = 0;
 
 /*FIXIT*/
-     while(!(er=getline(s)))
+     while(!(er=xagetline(s)))
      {         
           er=t_p1((signed char*)s,o,&l,&al);
 	  switch(segment) {
@@ -1002,7 +1002,7 @@ static int puttmps(signed char *s, int l
 
 static char l[MAXLINE];
 
-static int getline(char *s)
+static int xagetline(char *s)
 {
      static int ec;
 
