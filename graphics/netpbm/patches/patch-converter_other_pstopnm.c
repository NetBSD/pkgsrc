$NetBSD: patch-converter_other_pstopnm.c,v 1.1 2014/09/08 21:22:29 wiz Exp $

stdout is a special word.
Fix some whitespace issues while here.

--- converter/other/pstopnm.c.orig	2014-09-01 21:22:30.000000000 +0000
+++ converter/other/pstopnm.c
@@ -79,7 +79,7 @@ struct CmdlineInfo {
     unsigned int ysize;  /* zero means unspecified */
     unsigned int dpi;    /* zero means unspecified */
     enum Orientation orientation;
-    unsigned int stdout;
+    unsigned int istdout;
     unsigned int textalphabits;
 };
 
@@ -114,9 +114,9 @@ parseCommandLine(int argc, char ** argv,
     OPTENT3(0, "urx",        OPT_FLOAT, &urx, &urxSpec,                  0);
     OPTENT3(0, "ury",        OPT_FLOAT, &ury, &urySpec,                  0);
     OPTENT3(0, "nocrop",     OPT_FLAG,  NULL, &cmdlineP->nocrop,         0);
-    OPTENT3(0, "pbm",        OPT_FLAG,  NULL, &pbmOpt ,                  0);
+    OPTENT3(0, "pbm",        OPT_FLAG,  NULL, &pbmOpt,                   0);
     OPTENT3(0, "pgm",        OPT_FLAG,  NULL, &pgmOpt,                   0);
-    OPTENT3(0, "ppm",        OPT_FLAG,  NULL, &ppmOpt,                  0);
+    OPTENT3(0, "ppm",        OPT_FLAG,  NULL, &ppmOpt,                   0);
     OPTENT3(0, "verbose",    OPT_FLAG,  NULL, &cmdlineP->verbose,        0);
     OPTENT3(0, "xborder",    OPT_FLOAT, &cmdlineP->xborder, NULL,        0);
     OPTENT3(0, "xmax",       OPT_UINT,  &cmdlineP->xmax, &xmaxSpec,      0);
@@ -125,9 +125,9 @@ parseCommandLine(int argc, char ** argv,
     OPTENT3(0, "ymax",       OPT_UINT,  &cmdlineP->ymax, &ymaxSpec,      0);
     OPTENT3(0, "ysize",      OPT_UINT,  &cmdlineP->ysize, &ysizeSpec,    0);
     OPTENT3(0, "dpi",        OPT_UINT,  &cmdlineP->dpi, &dpiSpec,        0);
-    OPTENT3(0, "portrait",   OPT_FLAG,  NULL, &portraitOpt,             0);
-    OPTENT3(0, "landscape",  OPT_FLAG,  NULL, &landscapeOpt,            0);
-    OPTENT3(0, "stdout",     OPT_FLAG,  NULL, &cmdlineP->stdout,         0);
+    OPTENT3(0, "portrait",   OPT_FLAG,  NULL, &portraitOpt,              0);
+    OPTENT3(0, "landscape",  OPT_FLAG,  NULL, &landscapeOpt,             0);
+    OPTENT3(0, "stdout",     OPT_FLAG,  NULL, &cmdlineP->istdout,        0);
     OPTENT3(0, "textalphabits", OPT_UINT,
             &cmdlineP->textalphabits,  &textalphabitsSpec, 0);
 
@@ -664,7 +664,7 @@ computeOutfileArg(struct CmdlineInfo con
 -----------------------------------------------------------------------------*/
     const char * retval;  /* malloc'ed */
 
-    if (cmdline.stdout)
+    if (cmdline.istdout)
         retval = strdup("-");
     else if (streq(cmdline.inputFileName, "-"))
         retval = strdup("-");
