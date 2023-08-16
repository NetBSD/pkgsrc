$NetBSD: patch-xvwebp.c,v 1.2 2023/08/16 17:02:20 tsutsui Exp $

- add webp support from forked upstream
  https://gitlab.com/DavidGriffith/xv/-/commit/5682a07e
 - the default quality value is changed to 75 as the original libwebp
 - the default "page" of quality qDial is changed to 5.0 as jpeg
 - fix a bug of wrong quality value (almost 0) passed to WebPEncodeRGB()
 - minimum support for loading animation webp (decode only the first frame)
 - handle RGBA images properly (libwebp APIs don't convert RGBA to RGB)
   https://bugs.chromium.org/p/webp/issues/detail?id=616
 - plug several resouce leaks
 - use snprintf(3) rather than sprintf(3)

--- xvwebp.c.orig	2023-08-16 16:22:28.293425514 +0000
+++ xvwebp.c
@@ -0,0 +1,525 @@
+/*
+ * xvwebp.c - load routine for 'webp' format pictures
+ *
+ * written and submitted by:
+ *     Rainer Canavan (xv@canavan.de)
+ *
+ * LoadWEBP(fname, pinfo)
+ * WriteWEBP(fp, pic, ptype, w,h, rmap,gmap,bmap,numcols, cstyle, comment)
+ */
+
+
+#include "xv.h"
+
+#ifdef HAVE_WEBP
+
+#include <webp/types.h>
+#include <webp/encode.h>
+#include <webp/decode.h>
+#include <webp/demux.h>
+
+static char *filename;
+static const char *bname;
+
+static void drawWEBPD   PARM((int, int, int, int));
+static void clickWEBPD  PARM((int, int));
+static void doCmd       PARM((int));
+static void convertRGBA PARM((const byte * const, byte * const,
+                                    int, int, int, int));
+static void writeWEBP   PARM((void));
+static int  WriteWEBP   PARM((FILE *, byte *, int, int, int,
+                                    byte *, byte *, byte *));
+
+
+/*** Stuff for WEBP Dialog box ***/
+#define WEBPWIDE 288
+#define WEBPHIGH 185
+
+#define QUALITY   75     /* default quality */
+
+#define RGBATORGB(rgb, bg, alpha) \
+	(((rgb) * (alpha) / 255) + ((bg) * (255 - (alpha)) / 255))
+#define TRANSBG   0xE1   /* default background color to convert alpha channel */
+
+#define DWIDE    86
+#define DHIGH    104
+
+#define P_BOK    0
+#define P_BCANC  1
+#define P_NBUTTS 2
+
+#define BUTTH    24
+
+static DIAL  qDial;
+static BUTT  pbut[P_NBUTTS];
+static CBUTT FlosslessCB;
+
+
+/*******************************************/
+void CreateWEBPW()
+{
+  webpW = CreateWindow("xv webp", "XVWEBP", NULL,
+                      WEBPWIDE, WEBPHIGH, infofg, infobg, 0);
+  if (!webpW) FatalError("can't create WEBP window!");
+
+  XSelectInput(theDisp, webpW, ExposureMask | ButtonPressMask | KeyPressMask);
+
+  DCreate(&qDial, webpW,  12, 25, DWIDE, DHIGH, 0.0,
+          100.0, QUALITY, 1.0, 5.0,
+          infofg, infobg, hicol, locol, "Quality", NULL);
+
+  CBCreate(&FlosslessCB,   webpW, 110, 6+qDial.y+ASCENT+4*LINEHIGH, "Lossless",
+           infofg, infobg, hicol, locol);
+  FlosslessCB.val = 0;
+
+  BTCreate(&pbut[P_BOK], webpW, WEBPWIDE-180-1, WEBPHIGH-10-BUTTH-1, 80, BUTTH,
+          "Ok", infofg, infobg, hicol, locol);
+  BTCreate(&pbut[P_BCANC], webpW, WEBPWIDE-90-1, WEBPHIGH-10-BUTTH-1, 80, BUTTH,
+          "Cancel", infofg, infobg, hicol, locol);
+
+  XMapSubwindows(theDisp, webpW);
+}
+
+
+/*******************************************/
+void WEBPDialog(vis)
+     int vis;
+{
+  if (vis) {
+    CenterMapWindow(webpW, pbut[P_BOK].x + (int) pbut[P_BOK].w/2,
+                          pbut[P_BOK].y + (int) pbut[P_BOK].h/2,
+                    WEBPWIDE, WEBPHIGH);
+  }
+  else XUnmapWindow(theDisp, webpW);
+  webpUp = vis;
+}
+
+
+/*******************************************/
+int WEBPCheckEvent(xev)
+     XEvent *xev;
+{
+  /* check event to see if it's for one of our subwindows.  If it is,
+     deal accordingly, and return '1'.  Otherwise, return '0' */
+
+  int rv;
+  rv = 1;
+
+  if (!webpUp) return 0;
+  if (xev->type == Expose) {
+    int x,y,w,h;
+    XExposeEvent *e = (XExposeEvent *) xev;
+    x = e->x; y = e->y; w = e->width; h = e->height;
+
+    /* throw away excess expose events for 'dumb' windows */
+    if (e->count > 0 && (e->window == qDial.win)) {}
+
+    else if (e->window == webpW)       drawWEBPD(x, y, w, h);
+    else if (e->window == qDial.win)   DRedraw(&qDial);
+    else rv = 0;
+  }
+
+  else if (xev->type == ButtonPress) {
+    XButtonEvent *e = (XButtonEvent *) xev;
+    int x,y;
+    x = e->x;  y = e->y;
+
+    if (e->button == Button1) {
+      if      (e->window == webpW)      clickWEBPD(x,y);
+      else if (e->window == qDial.win)  DTrack(&qDial, x, y);
+      else rv = 0;
+    }  /* button1 */
+    else rv = 0;
+  }  /* button press */
+
+  else if (xev->type == KeyPress) {
+    XKeyEvent *e = (XKeyEvent *) xev;
+    char buf[128];  KeySym ks;
+    int stlen;
+
+    stlen = XLookupString(e,buf,128,&ks,(XComposeStatus *) NULL);
+    buf[stlen] = '\0';
+
+    RemapKeyCheck(ks, buf, &stlen);
+
+    if (e->window == webpW) {
+      if (stlen) {
+        if (buf[0] == '\r' || buf[0] == '\n') { /* enter */
+          FakeButtonPress(&pbut[P_BOK]);
+        }
+        else if (buf[0] == '\033') {            /* ESC */
+          FakeButtonPress(&pbut[P_BCANC]);
+        }
+      }
+    }
+    else rv = 0;
+  }
+  else rv = 0;
+
+  if (rv==0 && (xev->type == ButtonPress || xev->type == KeyPress)) {
+    XBell(theDisp, 50);
+    rv = 1;   /* eat it */
+  }
+
+  return rv;
+}
+
+
+/*******************************************/
+void WEBPSaveParams(fname)
+     char *fname;
+{
+  filename = fname;
+}
+
+
+/*******************************************/
+static void drawWEBPD(x, y, w, h)
+     int x, y, w, h;
+{
+  const char *title   = "Save WEBP file...";
+
+  char ctitle1[20];
+  const char *ctitle2 = "Quality value determines";
+  const char *ctitle3 = "compression rate: higher";
+  const char *ctitle4 = "quality = bigger file.";
+
+  int i;
+  XRectangle xr;
+
+  xr.x = x;  xr.y = y;  xr.width = w;  xr.height = h;
+  XSetClipRectangles(theDisp, theGC, 0,0, &xr, 1, Unsorted);
+
+  XSetForeground(theDisp, theGC, infofg);
+  XSetBackground(theDisp, theGC, infobg);
+
+  for (i=0; i<P_NBUTTS; i++) BTRedraw(&pbut[i]);
+
+  DrawString(webpW,       15,  6+ASCENT,                          title);
+
+  snprintf(ctitle1, 20, "Default = %d", QUALITY);
+  DrawString(webpW,      110,  6+qDial.y+ASCENT,            ctitle1);
+  DrawString(webpW,      110,  6+qDial.y+ASCENT+LINEHIGH,   ctitle2);
+  DrawString(webpW,      110,  6+qDial.y+ASCENT+2*LINEHIGH, ctitle3);
+  DrawString(webpW,      110,  6+qDial.y+ASCENT+3*LINEHIGH, ctitle4);
+
+  CBRedraw(&FlosslessCB);
+
+  XSetClipMask(theDisp, theGC, None);
+}
+
+
+/*******************************************/
+static void clickWEBPD(x,y)
+     int x,y;
+{
+  int i;
+  BUTT *bp;
+
+  /* check BUTTs */
+
+  for (i=0; i<P_NBUTTS; i++) {
+    bp = &pbut[i];
+    if (PTINRECT(x, y, bp->x, bp->y, bp->w, bp->h)) break;
+  }
+
+  if (i<P_NBUTTS) {  /* found one */
+    if (BTTrack(bp)) doCmd(i);
+  }
+
+  /* check CBUTTs */
+
+  else if (CBClick(&FlosslessCB,x,y)) {
+    int oldval = FlosslessCB.val;
+
+    CBTrack(&FlosslessCB);
+
+    if (oldval != FlosslessCB.val)
+    {
+      DSetActive(&qDial, !FlosslessCB.val);
+      DRedraw(&qDial); /* necessary? */
+    }
+  }
+}
+
+
+/*******************************************/
+static void doCmd(cmd)
+     int cmd;
+{
+  switch (cmd) {
+    case P_BOK:
+      {
+        char *fullname;
+
+        writeWEBP();
+        WEBPDialog(0);
+
+        fullname = GetDirFullName();
+        if (!ISPIPE(fullname[0])) {
+          XVCreatedFile(fullname);
+          StickInCtrlList(0);
+        }
+      }
+      break;
+
+    case P_BCANC:
+      WEBPDialog(0);
+      break;
+
+    default:
+      break;
+  }
+}
+
+/*******************************************/
+static void convertRGBA(rgba, rgb, width, height, stride, bgcolor)
+     const byte * const rgba; /* input loaded RGBA buffer */
+     byte * const rgb;  /* output xv pic RGB buffer */
+     int width;         /* image width */
+     int height;        /* image height */
+     int stride;        /* input image stride */
+     int bgcolor;       /* background color for alpha channel conversion */
+{
+  const byte *rgbap;
+  byte *rgbp;
+  int x, y;
+
+  rgbp = rgb;
+  for (y = 0; y < height; y++) {
+    rgbap = rgba + y * stride;
+    for (x = 0; x < width; x++) {
+      int alpha = rgbap[3];
+      *rgbp++ = RGBATORGB(rgbap[0], bgcolor, alpha); /* convert R */
+      *rgbp++ = RGBATORGB(rgbap[1], bgcolor, alpha); /* convert G */
+      *rgbp++ = RGBATORGB(rgbap[2], bgcolor, alpha); /* convert B */
+      rgbap += 4; /* skip A */
+    }
+  }
+}
+
+/*******************************************/
+int LoadWEBP(fname, pinfo)
+     char    *fname;
+     PICINFO *pinfo;
+/*******************************************/
+{
+  /* returns '1' on success */
+
+  FILE  *fp;
+  int   c, w, h, stride;
+  size_t filesize, picsize;
+  byte  *filebuf, *pic24;
+  WebPDecoderConfig config;
+  VP8StatusCode status;
+
+  bname = BaseName(fname);
+
+  pinfo->pic     = (byte *) NULL;
+  pinfo->comment = (char *) NULL;
+
+  fp = xv_fopen(fname,"r");
+  if (!fp) {
+     SetISTR(ISTR_WARNING,"%s:  %s", bname, "can't open file");
+     return 0;
+   }
+
+  /* compute file length */
+  fseek(fp, 0L, 2);
+  filesize = ftell(fp);
+  fseek(fp, 0L, 0);
+
+  if (filesize < 24) {
+     fclose(fp);
+     SetISTR(ISTR_WARNING,"%s:  %s", bname, "file is too short");
+     return 0;
+   }
+
+  /* read in the entire file */
+
+  filebuf = (byte *) calloc((size_t) filesize, (size_t) 1);
+  if (!filebuf) FatalError("couldn't malloc 'file buffer'");
+  c = fread(filebuf, (size_t) 1, (size_t) filesize, fp);
+  fclose(fp);
+  if (c != filesize) {
+    SetISTR(ISTR_WARNING,"%s:  %s", bname, "file read error");
+    free(filebuf);
+    return 0;
+  }
+
+  WebPInitDecoderConfig(&config);
+  if (WebPGetFeatures(filebuf, filesize, &config.input) != VP8_STATUS_OK) {
+    SetISTR(ISTR_WARNING,"%s:  %s", bname, "WebP get features failed");
+    free(filebuf);
+    return 0;
+  }
+  w = config.input.width;
+  h = config.input.height;
+  stride = w * 3;
+  picsize = stride * h;
+  pic24 = calloc((size_t)picsize, (size_t)1);
+  if (!pic24) FatalError("couldn't malloc 'image buffer'");
+
+  if (config.input.has_animation != 0) {
+    /* decode the first frame of animation webp */
+    WebPAnimDecoderOptions opts;
+    WebPData webpdata;
+    WebPAnimDecoder* dec;
+    WebPAnimInfo ainfo;
+    int timestamp, x, y, astride;
+    byte *rgbabuf;
+
+    WebPAnimDecoderOptionsInit(&opts);
+    opts.color_mode = MODE_RGBA;
+    webpdata.bytes = filebuf;
+    webpdata.size = filesize;
+    dec = WebPAnimDecoderNew(&webpdata, &opts);
+    if (dec == NULL) {
+      SetISTR(ISTR_WARNING,"%s:  %s", bname, "WebPAnimDecoderNew failed");
+      free(pic24);
+      free(filebuf);
+      return 0;
+    }
+    if (WebPAnimDecoderGetInfo(dec, &ainfo) &&
+        WebPAnimDecoderHasMoreFrames(dec) &&
+        WebPAnimDecoderGetNext(dec, &rgbabuf, &timestamp)) {
+      astride = w * 4;
+      convertRGBA(rgbabuf, pic24, w, h, astride, TRANSBG);
+    } else {
+      SetISTR(ISTR_WARNING,"%s:  %s", bname, "WebPAnimDecoder failed");
+      WebPAnimDecoderDelete(dec);
+      free(pic24);
+      free(filebuf);
+      return 0;
+    }
+    WebPAnimDecoderDelete(dec);
+  } else {
+    /* decode RGBA image and convert it to RGB with TRANSBG background */
+    int x, y, rgbasize, astride;
+    byte *rgbabuf;
+    astride = w * 4;
+    rgbasize = astride * h;
+    rgbabuf = calloc((size_t)rgbasize, (size_t)1);
+    config.output.colorspace = MODE_RGBA;
+    config.output.is_external_memory = 1;
+    config.output.u.RGBA.rgba = rgbabuf;
+    config.output.u.RGBA.size = rgbasize;
+    config.output.u.RGBA.stride = astride;
+    status = WebPDecode(filebuf, (size_t)filesize, &config);
+    if (status != VP8_STATUS_OK) {
+      SetISTR(ISTR_WARNING,"%s:  %s", bname, "WebPDecode failed");
+      free(pic24);
+      free(rgbabuf);
+      free(filebuf);
+      return 0;
+    }
+    convertRGBA(rgbabuf, pic24, w, h, astride, TRANSBG);
+    free(rgbabuf);
+    WebPFreeDecBuffer(&config.output);
+  }
+  free(filebuf);
+
+  pinfo->pic     = pic24;
+  pinfo->type    = PIC24;
+  pinfo->w       = w;
+  pinfo->h       = h;
+  pinfo->normw = pinfo->w;   pinfo->normh = pinfo->h;
+  pinfo->frmType = F_WEBP;
+  snprintf(pinfo->fullInfo, 128, "WEBP%s, RGB%s. (%ld bytes)",
+    config.input.has_animation != 0 ? " (with animation)" : "",
+    config.input.has_alpha != 0 ? "A" : "", filesize);
+  snprintf(pinfo->shrtInfo, 128, "%dx%d WEBP.", w,h);
+  pinfo->colType = F_FULLCOLOR;
+
+  return 1;
+}
+
+/*******************************************/
+static void writeWEBP()
+{
+  FILE       *fp;
+  int         w, h, nc, rv, ptype, pfree;
+  byte       *inpix, *rmap, *gmap, *bmap;
+
+  fp = OpenOutFile(filename);
+  if (!fp) return;
+
+  bname = BaseName(filename);
+
+  WaitCursor();
+  inpix = GenSavePic(&ptype, &w, &h, &pfree, &nc, &rmap, &gmap, &bmap);
+
+  rv = WriteWEBP(fp, inpix, ptype, w, h, rmap, gmap, bmap);
+
+  SetCursors(-1);
+
+  if (CloseOutFile(fp, filename, rv) == 0) DirBox(0);
+
+  if (pfree) free(inpix);
+}
+
+
+/*******************************************/
+int WriteWEBP(fp,pic,ptype,w,h,rmap,gmap,bmap)
+     FILE *fp;
+     byte *pic;
+     int   ptype, w,h;
+     byte *rmap, *gmap, *bmap;
+
+/*******************************************/
+{
+  int i;
+  byte *xpic;
+  size_t imagesize;
+  size_t outsize;
+  int pfree;
+
+  imagesize = w*h*3;
+  WaitCursor();
+  pfree = 0;
+  if (ptype == PIC8) {
+    byte *last = pic + w*h;
+    register byte *from, *to;
+
+    from = pic;
+
+    if (!(pic = (byte *)malloc(imagesize))) FatalError("out of memory\n");
+    to = pic;
+    pfree = 1; /* Let the modified buffer be released later */
+
+    do {
+      i = *from;
+      *to++ = rmap[i];
+      *to++ = gmap[i];
+      *to++ = bmap[i];
+    } while (++from < last);
+
+  }
+  if (FlosslessCB.val == 0) {
+    outsize = WebPEncodeRGB(pic, w, h, w*3, (float)qDial.val, &xpic);
+  } else {
+    outsize = WebPEncodeLosslessRGB(pic, w, h, w*3, &xpic);
+  }
+  if (pfree == 1) { free(pic); }
+  if (outsize <= 0) {
+    WebPFree(xpic);
+    return -1;
+  }
+  fwrite(xpic, outsize, 1, fp);
+  SetCursors(-1);
+  WebPFree(xpic);
+  if (ferror(fp)) return -1;
+  return 0;
+}
+
+/*******************************************/
+void
+VersionInfoWEBP()	/* GRR 19980605 */
+{
+  int ver;
+  ver = WebPGetDecoderVersion();
+  fprintf(stderr, "   Compiled with libwebp; using libwebp %i.%i.%i.\n",
+    (ver >> 16) & 255, (ver >> 8 ) & 255, ver & 255);
+}
+
+#endif
