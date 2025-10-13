$NetBSD: patch-xmagv.c,v 1.1 2025/10/13 13:04:19 ryoon Exp $

To fix GCC 14 build:
* Use modern standard.
* Add missing include.
* Add missing return types.

--- xmagv.c.orig	1995-11-17 18:19:12.000000000 +0000
+++ xmagv.c
@@ -14,6 +14,7 @@
  */
 
 #include <stdio.h>
+#include <sys/wait.h> /* For wait(2) */
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xos.h>
@@ -170,8 +171,7 @@ static char optusage[] = "\
   -root\n\
        set root window background pixmap\n";
 
-void usage(fp)
-     FILE *fp;
+void usage(FILE *fp)
 {
   char **p;
 
@@ -198,16 +198,14 @@ void f_usage()
   exit(0);
 }
 
-char *getmyname(str)
-     char *str;
+char *getmyname(char *str)
 {
   char *p;
 
   return ((p = strrchr(str, '/')) != NULL) ? p+1 : str;
 }
 
-char *getdispname(str)
-     char *str;
+char *getdispname(char *str)
 {
   char *p, *p0;
   char buf[MAXPATH];
@@ -219,8 +217,7 @@ char *getdispname(str)
   return strcpy(str, p0);
 }
 
-void disp_info(p)
-     MagWin *p;
+void disp_info(MagWin *p)
 {
   printf("%-12s %4d x%4d %3d %s\n", getmyname(p->filename),
 	 p->xsize, p->ysize, p->colsize, p->comment);
@@ -241,8 +238,7 @@ void disp_info(p)
 }
 
 #ifdef ZPIPE
-int is_compressed_file(name)
-     char *name;
+int is_compressed_file(char *name)
 {
   char *p;
   
@@ -256,8 +252,7 @@ int is_compressed_file(name)
 #endif /* ZPIPE */
 
 /* open MAG file */
-FILE *open_mag_file(p, str)
-     MagWin *p; char *str;
+FILE *open_mag_file(MagWin *p, char *str)
 {
   int i;
   int fd[2];
@@ -310,8 +305,7 @@ FILE *open_mag_file(p, str)
 #define HDERR_NOMAG 1
 #define HDERR_NOSUP 2
 #define HDERR_LARGE 3
-int ReadHeader(fp, p)
-     FILE *fp; MagWin *p;
+int ReadHeader(FILE *fp, MagWin *p)
 {
   int c, i;
   char buf[MAGHDSIZE];
@@ -369,8 +363,7 @@ int ReadHeader(fp, p)
   return 0;
 }
 
-int CheckPixlen(p)
-     MagWin *p;
+int CheckPixlen(MagWin *p)
 {
   if (p->fptr != p->hdofs + p->f.pixdataofs + p->f.pixlen)
     return error("``%s'' pixlen may be %ld not %ld!",
@@ -383,8 +376,7 @@ int CheckPixlen(p)
 typedef struct {unsigned char g,r,b;} MAKIPAL;
 static MAKIPAL colbuf[MAX_COLOR];
 
-int ReadColors(p)
-     MagWin *p;
+int ReadColors(MagWin *p)
 {
   int i;
   unsigned char rdbuf[3*MAX_COLOR], *pp;
@@ -403,8 +395,7 @@ int ReadColors(p)
 }
 
 /* return alloc miss count */
-int AllocColors_sub(p)
-     MagWin *p;
+int AllocColors_sub(MagWin *p)
 {
   int i, r;
   MAKIPAL *pp;
@@ -446,8 +437,7 @@ int AllocColors_sub(p)
   return r;
 }
 
-void FreeColors_sub(p)
-     MagWin *p;
+void FreeColors_sub(MagWin *p)
 {
   int i,n;
   XPIX pxtbl[MAX_COLOR];
@@ -462,8 +452,7 @@ void FreeColors_sub(p)
 
 static Colormap org_cmap;
 
-void FreeColors(p)
-     MagWin *p;
+void FreeColors(MagWin *p)
 {
   FreeColors_sub(p);
   if (cmap_mode) {
@@ -472,8 +461,7 @@ void FreeColors(p)
   }
 }
 
-void AllocColors(p)
-     MagWin *p;
+void AllocColors(MagWin *p)
 {
   int i;
   
@@ -499,8 +487,7 @@ void AllocColors(p)
 /* seek MAG file
  * from header top
  */
-int SeekMagFile(p, pos)
-     MagWin *p; long pos;
+int SeekMagFile(MagWin *p, long pos)
 {
   int i;
   long l;
@@ -520,8 +507,7 @@ int SeekMagFile(p, pos)
   return 0;
 }
 
-int ReadMagFile(p)
-     MagWin *p;
+int ReadMagFile(MagWin *p)
 {
   /* read flag A */
   if (SeekMagFile(p, p->f.flagAofs))
@@ -563,8 +549,7 @@ int cancel_check()
   return 0;
 }
 
-void DumpColors(p)
-     MagWin *p;
+void DumpColors(MagWin *p)
 {
   int i;
   
@@ -573,8 +558,7 @@ void DumpColors(p)
 	   i, col[i].red>>8, col[i].green>>8, col[i].blue>>8);
 }
 
-PreDumpPixels(p)
-     MagWin *p;
+int PreDumpPixels(MagWin *p)
 {
   int r;
   char *fn;
@@ -610,8 +594,7 @@ PreDumpPixels(p)
   return ferror(stdout);
 }
 
-PostDumpPixels(p)
-     MagWin *p;
+int PostDumpPixels(MagWin *p)
 {
   int r;
   
@@ -626,8 +609,7 @@ PostDumpPixels(p)
   return r;
 }
 
-DumpPpm6(wp, x, y, xs, n, buf, pp)
-     MagWin *wp; char *buf; XPIX *pp;
+int DumpPpm6(MagWin *wp, int x, int y, int xs, int n, char *buf, XPIX *pp)
 {
   while (xs--) {
     if (fputc(col[*pp].red>>8, stdout) == EOF ||
@@ -639,8 +621,7 @@ DumpPpm6(wp, x, y, xs, n, buf, pp)
   return 0;
 }
 
-DumpPpm(wp, x, y, xs, n, buf, pp)
-     MagWin *wp; char *buf; XPIX *pp;
+int DumpPpm(MagWin *wp, int x, int y, int xs, int n, char *buf, XPIX *pp)
 {
   int i, cnt;
   char *p, *form;
@@ -663,8 +644,7 @@ DumpPpm(wp, x, y, xs, n, buf, pp)
   return 0;
 }
 
-DumpPix(wp, x, y, xs, n, buf, pp)
-     MagWin *wp; char *buf; XPIX *pp;
+int DumpPix(MagWin *wp, int x, int y, int xs, int n, char *buf, XPIX *pp)
 {
   int i, cnt;
   char *form, *p;
@@ -687,8 +667,7 @@ DumpPix(wp, x, y, xs, n, buf, pp)
 
 #define isdumpbit1(c) bitmap_fg[c]
 
-DumpBit(wp, x, y, xs, n, buf, pp)
-     MagWin *wp; char *buf; XPIX *pp;
+int DumpBit(MagWin *wp, int x, int y, int xs, int n, char *buf, XPIX *pp)
 {
   int i, cnt;
   char *p;
@@ -730,8 +709,7 @@ DumpBit(wp, x, y, xs, n, buf, pp)
   return 0;
 }
 
-DumpPixels(wp, x, y, xs, pp)
-     MagWin *wp; XPIX *pp;
+int DumpPixels(MagWin *wp, int x, int y, int xs, XPIX *pp)
 {
   int n, r;
   char buf[MAX_FILE_X+2];
@@ -762,8 +740,7 @@ DumpPixels(wp, x, y, xs, pp)
 }
 
 /* read pixel data from file */
-int readpixel(p, px)
-     MagWin *p; unsigned short *px;
+int readpixel(MagWin *p, unsigned short *px)
 {
   int c;
   
@@ -778,8 +755,7 @@ int readpixel(p, px)
   return 0;
 }
 
-int DecodePixGroup(p, pbuf, y, x2, f)
-     MagWin *p; XPIX pbuf[];
+int DecodePixGroup(MagWin *p, XPIX pbuf[], int y, int x2, unsigned char f)
 {
   unsigned short px;
   
@@ -801,8 +777,7 @@ int DecodePixGroup(p, pbuf, y, x2, f)
   return 0;
 }
 
-int DecodeMag(p)
-     MagWin *p;
+int DecodeMag(MagWin *p)
 {
   int x,y,x2, y2, aspf, dx;
   unsigned char a_bit,flag,*pf, *pp, *pa, *pb;
@@ -857,8 +832,7 @@ int DecodeMag(p)
 
 
 /* allocate work area and set pointer */
-AllocMemories(p)
-     MagWin *p;
+int AllocMemories(MagWin *p)
 {
   if (debug_f) {
     fprintf(stderr, "malloc %ld + %ld + %ld\n",
@@ -871,8 +845,7 @@ AllocMemories(p)
   return p->pix_buffer == NULL || p->flag_a == NULL || p->flag_b == NULL;
 }
 
-void FreeMemories(p)
-     MagWin *p;
+void FreeMemories(MagWin *p)
 {
   if (p->pix_buffer != NULL)
     free(p->pix_buffer);
@@ -890,8 +863,7 @@ void optstr(ac, av, opt)
     *opt = *++*av;
 }
 
-optnum(ac, av, n, max)
-     int *ac; char ***av; int *n; int max;
+int optnum(int *ac, char ***av, int *n, int max)
 {
   long i;
   char *p;
@@ -910,11 +882,7 @@ optnum(ac, av, n, max)
 static Pixmap root_pix;
 static Pixmap tile_pix;
 
-void tilepixmap(src, dst, dstx, dsty)
-     Pixmap src;
-     Pixmap dst;
-     int dstx;
-     int dsty;
+void tilepixmap(Pixmap src, Pixmap dst, int dstx, int dsty)
 {
   int dx, dy;
   
@@ -985,8 +953,7 @@ void setroot()
  * options
  */
 
-f_bit1(ac, av)
-     int *ac; char ***av;
+int f_bit1(int *ac, char ***av)
 {
   int i;
   
@@ -1059,9 +1026,7 @@ static OPTION opttbl[] = {
   OPTTBL(NULL,		0,		NULL,		0)
 };
 
-int parse_option(ac, av)
-     int *ac;
-     char ***av;
+int parse_option(int *ac, char ***av)
 {
   OPTION *p;
   int i;
@@ -1099,8 +1064,7 @@ int parse_option(ac, av)
 }
 
 
-void default_onoff(str, f)
-     char *str; int *f;
+void default_onoff(char *str, int *f)
 {
   char *p;
 
@@ -1108,8 +1072,7 @@ void default_onoff(str, f)
     *f = ((p = XGetDefault(dsp, myname, str)) != NULL) && !strcmp(p, "on");
 }
 
-void default_string(str, f)
-     char *str; char **f;
+void default_string(char *str, char **f)
 {
   if (*f == NULL)
     *f = XGetDefault(dsp, myname, str);
@@ -1167,8 +1130,7 @@ void adjust_options()
  * event
  */
 
-void Scroll(dx, dy)
-     int dx, dy;
+void Scroll(int dx, int dy)
 {
   int x0, y0, x1, y1, adx, ady;
   
@@ -1209,8 +1171,7 @@ int prevpict()
   return r;
 }
 
-int mouseop(f, x, y)
-     int f, x, y;
+int mouseop(int f, int x, int y)
 {
   int dx, dy;
 
@@ -1240,8 +1201,7 @@ int mouseop(f, x, y)
   return 0;
 }
 
-int scraccel(n)
-     int n;
+int scraccel(int n)
 {
   if (n > 0 && n < SCRDOTS*SCRDIV)
     ++n;
@@ -1250,8 +1210,7 @@ int scraccel(n)
   return n;
 }
 
-int mainevent(f)
-     int f;
+int mainevent(int f)
 {
   static int cnt = 0;
   
@@ -1284,8 +1243,7 @@ int mainevent(f)
 #define CMD_up 6
 #define CMD_down 7
 
-int keyop(p, sym)
-     char *p; KeySym *sym;
+int keyop(char *p, KeySym *sym)
 {
   int r, cmd, fct, *cp;
   static int cmdtbl[] = {
@@ -1395,8 +1353,8 @@ void SetBGcolors()
   }
 }
 
-disp_mag_file(path)
-     char *path;		/* MAG file pathname */
+int disp_mag_file(char *path)
+   /*  char *path;		 MAG file pathname */
 {
   int i, r;
   MagWin hdr;
@@ -1477,8 +1435,7 @@ disp_mag_file(path)
   return r;
 }
 
-int main(argc, argv)
-     int argc; char **argv;
+int main(int argc, char **argv)
 {
   int i, ac;
   char **av;
