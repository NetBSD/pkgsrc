$NetBSD: patch-arjdisp.c,v 1.1 2015/04/12 16:09:27 tnn Exp $

Add patch from Debian (security_format.patch) to fix unsafe format string usage.

--- arjdisp.c.orig	2003-06-22 11:12:28.000000000 +0000
+++ arjdisp.c
@@ -20,8 +20,6 @@ static long bytes;
 static long compsize;
 static char cmd_verb;
 static char msg_lf[]="\n";
-char strform[]="%s";                    /* Export it for scrnio.c, too
-                                           (a byte saved is a byte gained) */
 
 /* Pseudographical controls */
 
@@ -54,19 +52,19 @@ static void show_init_scrn()
  textcolor(7);
  clrscr();
  gotoxy(2, 2);
- scrprintf(win_top);
+ fputs(win_top, stdout);
  for(i=3; i<24; i++)
  {
-  gotoxy(2, i); scrprintf(win_border);
-  gotoxy(79, i); scrprintf(win_border);
+  gotoxy(2, i); fputs(win_border, stdout);
+  gotoxy(79, i); fputs(win_border, stdout);
  }
- gotoxy(2, 24); scrprintf(win_bottom);
+ gotoxy(2, 24); fputs(win_bottom, stdout);
  gotoxy(10, 5);
- scrprintf(M_ARJDISP_COPYRIGHT);
+ fputs(M_ARJDISP_COPYRIGHT, stdout);
  gotoxy(10, 6);
- scrprintf(M_ARJDISP_DISTRIBUTION);
+ fputs(M_ARJDISP_DISTRIBUTION, stdout);
  gotoxy(10, 7);
- scrprintf(M_ARJDISP_LICENSE);
+ fputs(M_ARJDISP_LICENSE, stdout);
  gotoxy(16, 10);
  scrprintf(M_PROCESSING_ARCHIVE, archive_name);
  t=strtok(M_ARJDISP_INFO, msg_lf);
@@ -74,11 +72,11 @@ static void show_init_scrn()
  while(t!=NULL&&i<=23)
  {
   gotoxy(10, i++);
-  scrprintf(strform, t);
+  scrprintf("%s", t);
   t=strtok(NULL, msg_lf);
  }
  gotoxy(16, 20);
- scrprintf(M_PRESS_ANY_KEY);
+ fputs(M_PRESS_ANY_KEY, stdout);
  uni_getch();
  gotoxy(1, 24);
 }
@@ -96,19 +94,19 @@ static void show_proc_scrn()
  {
   clrscr();
   gotoxy(2, 2);
-  scrprintf(win_top);
+  fputs(win_top, stdout);
   for(i=3; i<24; i++)
   {
-   gotoxy(2, i); scrprintf(win_border);
-   gotoxy(79, i); scrprintf(win_border);
+   gotoxy(2, i); fputs(win_border, stdout);
+   gotoxy(79, i); fputs(win_border, stdout);
   }
-  gotoxy(2, 24); scrprintf(win_bottom);
+  gotoxy(2, 24); fputs(win_bottom, stdout);
   gotoxy(10, 5);
-  scrprintf(M_ARJDISP_COPYRIGHT);
+  fputs(M_ARJDISP_COPYRIGHT, stdout);
   gotoxy(10, 6);
-  scrprintf(M_ARJDISP_DISTRIBUTION);
+  fputs(M_ARJDISP_DISTRIBUTION, stdout);
   gotoxy(10, 7);
-  scrprintf(M_ARJDISP_LICENSE);
+  fputs(M_ARJDISP_LICENSE, stdout);
   gotoxy(16, 10);
   scrprintf(M_PROCESSING_ARCHIVE, archive_name);
   gotoxy(16, 12);
@@ -132,13 +130,13 @@ static void show_proc_scrn()
     break;
   }
   gotoxy(15, 14);
-  scrprintf(ind_top);
+  fputs(ind_top, stdout);
   gotoxy(15, 15);
-  scrprintf(ind_middle);
+  fputs(ind_middle, stdout);
   gotoxy(15, 16);
-  scrprintf(ind_bottom);
+  fputs(ind_bottom, stdout);
   gotoxy(16, 18);
-  scrprintf(M_ARJDISP_CTR_START);
+  fputs(M_ARJDISP_CTR_START, stdout);
  }
  else
  {
@@ -146,7 +144,7 @@ static void show_proc_scrn()
   gotoxy(16, 15);
   memset(progress, indo, i);
   progress[i]='\0';
-  scrprintf(progress);
+  fputs(progress, stdout);
   gotoxy(16, 18);
   scrprintf(M_ARJDISP_CTR, calc_percentage(bytes, uncompsize)/10);
  }
@@ -165,19 +163,19 @@ static void show_ending_scrn()
  textcolor(7);
  clrscr();
  gotoxy(2, 2);
- scrprintf(win_top);
+ fputs(win_top, stdout);
  for(i=3; i<24; i++)
  {
-  gotoxy(2, i); scrprintf(win_border);
-  gotoxy(79, i); scrprintf(win_border);
+  gotoxy(2, i); fputs(win_border, stdout);
+  gotoxy(79, i); fputs(win_border, stdout);
  }
- gotoxy(2, 24); scrprintf(win_bottom);
+ gotoxy(2, 24); fputs(win_bottom, stdout);
  gotoxy(10, 5);
- scrprintf(M_ARJDISP_COPYRIGHT);
+ fputs(M_ARJDISP_COPYRIGHT, stdout);
  gotoxy(10, 6);
- scrprintf(M_ARJDISP_DISTRIBUTION);
+ fputs(M_ARJDISP_DISTRIBUTION, stdout);
  gotoxy(10, 7);
- scrprintf(M_ARJDISP_LICENSE);
+ fputs(M_ARJDISP_LICENSE, stdout);
  gotoxy(16, 10);
  scrprintf(M_FINISHED_PROCESSING, archive_name);
  gotoxy(1, 24);
