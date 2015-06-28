$NetBSD: patch-bind_tcl_pdflib__tcl.c,v 1.1 2015/06/28 17:11:12 joerg Exp $

--- bind/tcl/pdflib_tcl.c.orig	2002-01-07 18:26:29.000000000 +0000
+++ bind/tcl/pdflib_tcl.c
@@ -39,6 +39,7 @@
  * if building with older TCL Versions than 8.2 you have to undef this
  */
 #define USE_TCL_STUBS
+#define USE_INTERP_RESULT
 
 #include <tcl.h>
 
@@ -213,7 +214,7 @@ void SWIG_MakePtr(char *_c, const void *
 /* Function for getting a pointer value */
 
 SWIGSTATIC 
-char *SWIG_GetPtr(char *_c, void **ptr, char *_t)
+const char *SWIG_GetPtr(const char *_c, void **ptr, char *_t)
 {
   unsigned long _p;
   char temp_type[256];
@@ -397,7 +398,7 @@ pdf_errorhandler(PDF *p, int type, const
 
     /* Issue a warning message and continue for non-fatal errors */
     if (type == PDF_NonfatalError) {
-	fprintf(stderr, ex->buffer);
+	fprintf(stderr, "%s", ex->buffer);
 	return;
     }
 	
@@ -542,7 +543,7 @@ GetStringUnicodePDFChars(PDF *p, Tcl_Int
 #endif
 
 static int
-_wrap_PDF_new(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_new(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     char versionbuf[32];
     EXC_STUFF;
@@ -583,7 +584,7 @@ _wrap_PDF_new(ClientData clientData, Tcl
 }
 
 static int
-_wrap_PDF_delete(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_delete(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -605,10 +606,10 @@ _wrap_PDF_delete(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_open_file(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_open_file(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     EXC_STUFF;
 
     if (argc != 3) {
@@ -632,7 +633,7 @@ _wrap_PDF_open_file(ClientData clientDat
 }
 
 static int
-_wrap_PDF_close(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_close(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -699,7 +700,7 @@ static int _wrap_PDF_get_buffer(ClientDa
 }
 
 static int
-_wrap_PDF_begin_page(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_begin_page(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -726,7 +727,7 @@ _wrap_PDF_begin_page(ClientData clientDa
 }
 
 static int
-_wrap_PDF_end_page(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_end_page(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -748,10 +749,10 @@ _wrap_PDF_end_page(ClientData clientData
 }
 
 static int
-_wrap_PDF_set_parameter(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_parameter(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
-    char *_arg1;
-    char *_arg2;
+    const char *_arg1;
+    const char *_arg2;
     EXC_STUFF;
 
     if (argc != 4) {
@@ -784,10 +785,10 @@ _wrap_PDF_set_parameter(ClientData clien
     return TCL_OK;
 }
 
-static int _wrap_PDF_get_parameter(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+static int _wrap_PDF_get_parameter(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     char * _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     float _arg2;
     EXC_STUFF;
 
@@ -812,10 +813,10 @@ static int _wrap_PDF_get_parameter(Clien
 }
 
 static int
-_wrap_PDF_set_value(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_value(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     float _arg2;
     EXC_STUFF;
 
@@ -840,11 +841,11 @@ _wrap_PDF_set_value(ClientData clientDat
 }
 
 static int
-_wrap_PDF_get_value(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_get_value(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     float _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     float _arg2;
     EXC_STUFF;
 
@@ -869,11 +870,11 @@ _wrap_PDF_get_value(ClientData clientDat
 }
 
 static int
-_wrap_PDF_findfont(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_findfont(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
-    char *_arg2;
+    const char *_arg1;
+    const char *_arg2;
     int _arg3;
     EXC_STUFF;
 
@@ -906,7 +907,7 @@ _wrap_PDF_findfont(ClientData clientData
 }
 
 static int
-_wrap_PDF_setfont(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setfont(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     float _arg2;
@@ -1136,7 +1137,7 @@ static int _wrap_PDF_show_boxed(ClientDa
 }
 
 static int
-_wrap_PDF_set_text_pos(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_text_pos(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1216,7 +1217,7 @@ _wrap_PDF_stringwidth(ClientData clientD
 }
 
 static int
-_wrap_PDF_setdash(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setdash(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1295,7 +1296,7 @@ _wrap_PDF_setpolydash(ClientData clientD
 }
 
 static int
-_wrap_PDF_setflat(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setflat(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -1319,7 +1320,7 @@ _wrap_PDF_setflat(ClientData clientData,
 }
 
 static int
-_wrap_PDF_setlinejoin(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setlinejoin(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     EXC_STUFF;
@@ -1348,7 +1349,7 @@ _wrap_PDF_setlinejoin(ClientData clientD
 }
 
 static int
-_wrap_PDF_setlinecap(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setlinecap(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     EXC_STUFF;
@@ -1377,7 +1378,7 @@ _wrap_PDF_setlinecap(ClientData clientDa
 }
 
 static int
-_wrap_PDF_setmiterlimit(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setmiterlimit(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -1402,7 +1403,7 @@ _wrap_PDF_setmiterlimit(ClientData clien
 }
 
 static int
-_wrap_PDF_setlinewidth(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setlinewidth(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -1427,7 +1428,7 @@ _wrap_PDF_setlinewidth(ClientData client
 }
 
 static int
-_wrap_PDF_save(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_save(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1449,7 +1450,7 @@ _wrap_PDF_save(ClientData clientData, Tc
 }
 
 static int
-_wrap_PDF_restore(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_restore(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1471,7 +1472,7 @@ _wrap_PDF_restore(ClientData clientData,
 }
 
 static int
-_wrap_PDF_translate(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_translate(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1498,7 +1499,7 @@ _wrap_PDF_translate(ClientData clientDat
 }
 
 static int
-_wrap_PDF_scale(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_scale(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1525,7 +1526,7 @@ _wrap_PDF_scale(ClientData clientData, T
 }
 
 static int
-_wrap_PDF_rotate(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_rotate(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -1550,7 +1551,7 @@ _wrap_PDF_rotate(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_skew(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_skew(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1576,7 +1577,7 @@ _wrap_PDF_skew(ClientData clientData, Tc
     return TCL_OK;
 }
 
-static int _wrap_PDF_concat(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+static int _wrap_PDF_concat(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1613,7 +1614,7 @@ static int _wrap_PDF_concat(ClientData c
 }
 
 static int
-_wrap_PDF_moveto(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_moveto(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1640,7 +1641,7 @@ _wrap_PDF_moveto(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_lineto(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_lineto(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1667,7 +1668,7 @@ _wrap_PDF_lineto(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_curveto(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_curveto(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1702,7 +1703,7 @@ _wrap_PDF_curveto(ClientData clientData,
 }
 
 static int
-_wrap_PDF_circle(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_circle(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1730,7 +1731,7 @@ _wrap_PDF_circle(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_arc(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_arc(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1763,7 +1764,7 @@ _wrap_PDF_arc(ClientData clientData, Tcl
 }
 
 static int
-_wrap_PDF_rect(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_rect(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -1794,7 +1795,7 @@ _wrap_PDF_rect(ClientData clientData, Tc
 }
 
 static int
-_wrap_PDF_closepath(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_closepath(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1816,7 +1817,7 @@ _wrap_PDF_closepath(ClientData clientDat
 }
 
 static int
-_wrap_PDF_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1838,7 +1839,7 @@ _wrap_PDF_stroke(ClientData clientData, 
 }
 
 static int
-_wrap_PDF_closepath_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_closepath_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1860,7 +1861,7 @@ _wrap_PDF_closepath_stroke(ClientData cl
 }
 
 static int
-_wrap_PDF_fill(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_fill(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1882,7 +1883,7 @@ _wrap_PDF_fill(ClientData clientData, Tc
 }
 
 static int
-_wrap_PDF_fill_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_fill_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1904,7 +1905,7 @@ _wrap_PDF_fill_stroke(ClientData clientD
 }
 
 static int
-_wrap_PDF_closepath_fill_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_closepath_fill_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1926,7 +1927,7 @@ _wrap_PDF_closepath_fill_stroke(ClientDa
 }
 
 static int
-_wrap_PDF_endpath(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_endpath(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1948,7 +1949,7 @@ _wrap_PDF_endpath(ClientData clientData,
 }
 
 static int
-_wrap_PDF_clip(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_clip(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
@@ -1970,7 +1971,7 @@ _wrap_PDF_clip(ClientData clientData, Tc
 }
 
 static int
-_wrap_PDF_setgray_fill(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setgray_fill(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -1995,7 +1996,7 @@ _wrap_PDF_setgray_fill(ClientData client
 }
 
 static int
-_wrap_PDF_setgray_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setgray_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -2020,7 +2021,7 @@ _wrap_PDF_setgray_stroke(ClientData clie
 }
 
 static int
-_wrap_PDF_setgray(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setgray(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     EXC_STUFF;
@@ -2045,7 +2046,7 @@ _wrap_PDF_setgray(ClientData clientData,
 }
 
 static int
-_wrap_PDF_setrgbcolor_fill(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setrgbcolor_fill(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -2074,7 +2075,7 @@ _wrap_PDF_setrgbcolor_fill(ClientData cl
 }
 
 static int
-_wrap_PDF_setrgbcolor_stroke(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setrgbcolor_stroke(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -2103,7 +2104,7 @@ _wrap_PDF_setrgbcolor_stroke(ClientData 
 }
 
 static int
-_wrap_PDF_setrgbcolor(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setrgbcolor(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -2132,7 +2133,7 @@ _wrap_PDF_setrgbcolor(ClientData clientD
 }
 
 static int
-_wrap_PDF_place_image(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_place_image(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     float _arg2;
@@ -2171,15 +2172,15 @@ _wrap_PDF_open_image(ClientData clientDa
 
     int _result;
     PDF *p;
-    char *_arg1;
-    char *_arg2;
-    char *_arg3;
+    const char *_arg1;
+    const char *_arg2;
+    const char *_arg3;
     long  _arg4;
     int _arg5;
     int _arg6;
     int _arg7;
     int _arg8;
-    char *_arg9;
+    const char *_arg9;
     int len = 0;
     char *res;
     EXC_STUFF;
@@ -2269,7 +2270,7 @@ _wrap_PDF_open_image(ClientData clientDa
 }
 
 static int
-_wrap_PDF_close_image(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_close_image(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     EXC_STUFF;
@@ -2298,12 +2299,12 @@ _wrap_PDF_close_image(ClientData clientD
 }
 
 static int
-_wrap_PDF_open_image_file(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_open_image_file(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
-    char *_arg2;
-    char *_arg3;
+    const char *_arg1;
+    const char *_arg2;
+    const char *_arg3;
     int _arg4;
     EXC_STUFF;
 
@@ -2335,10 +2336,10 @@ _wrap_PDF_open_image_file(ClientData cli
 }
 
 static int
-_wrap_PDF_open_CCITT(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_open_CCITT(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     int _arg2;
     int _arg3;
     int _arg4;
@@ -2490,12 +2491,12 @@ _wrap_PDF_attach_file(ClientData clientD
     double  _arg2;
     double  _arg3;
     double  _arg4;
-    char *_arg5;
-    char *_arg6;
-    char *_arg7;
-    char *_arg8;
-    char *_arg9;
-    char *res;
+    const char *_arg5;
+    const char *_arg6;
+    const char *_arg7;
+    const char *_arg8;
+    const char *_arg9;
+    const char *res;
     EXC_STUFF;
 
     if (objc != 11) {
@@ -2573,9 +2574,9 @@ _wrap_PDF_add_note(ClientData clientData
     double  _arg2;
     double  _arg3;
     double  _arg4;
-    char *_arg5;
-    char *_arg6;
-    char *_arg7;
+    const char *_arg5;
+    const char *_arg6;
+    const char *_arg7;
     int _arg8;
     char *res;
     EXC_STUFF;
@@ -2644,15 +2645,15 @@ _wrap_PDF_add_note(ClientData clientData
 }
 
 static int
-_wrap_PDF_add_pdflink(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_add_pdflink(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
     float _arg3;
     float _arg4;
-    char *_arg5;
+    const char *_arg5;
     int _arg6;
-    char *_arg7;
+    const char *_arg7;
     EXC_STUFF;
 
     if (argc != 9) {
@@ -2685,13 +2686,13 @@ _wrap_PDF_add_pdflink(ClientData clientD
 }
 
 static int
-_wrap_PDF_add_launchlink(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_add_launchlink(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
     float _arg3;
     float _arg4;
-    char *_arg5;
+    const char *_arg5;
     EXC_STUFF;
 
     if (argc != 7) {
@@ -2718,14 +2719,14 @@ _wrap_PDF_add_launchlink(ClientData clie
 }
 
 static int
-_wrap_PDF_add_locallink(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_add_locallink(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
     float _arg3;
     float _arg4;
     int _arg5;
-    char *_arg6;
+    const char *_arg6;
     EXC_STUFF;
 
     if (argc != 8) {
@@ -2757,13 +2758,13 @@ _wrap_PDF_add_locallink(ClientData clien
 }
 
 static int
-_wrap_PDF_add_weblink(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_add_weblink(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
     float _arg3;
     float _arg4;
-    char *_arg5;
+    const char *_arg5;
     EXC_STUFF;
 
     if (argc != 7) {
@@ -2790,9 +2791,9 @@ _wrap_PDF_add_weblink(ClientData clientD
 }
 
 static int
-_wrap_PDF_set_border_style(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_border_style(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     float _arg2;
     EXC_STUFF;
 
@@ -2817,7 +2818,7 @@ _wrap_PDF_set_border_style(ClientData cl
 }
 
 static int
-_wrap_PDF_set_border_color(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_border_color(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -2846,7 +2847,7 @@ _wrap_PDF_set_border_color(ClientData cl
 }
 
 static int
-_wrap_PDF_set_border_dash(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_set_border_dash(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -2872,11 +2873,11 @@ _wrap_PDF_set_border_dash(ClientData cli
     return TCL_OK;
 }
 
-static int _wrap_PDF_open_pdi(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+static int _wrap_PDF_open_pdi(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
-    char *_arg2;
+    const char *_arg1;
+    const char *_arg2;
     int _arg3;
     EXC_STUFF;
 
@@ -2901,7 +2902,7 @@ static int _wrap_PDF_open_pdi(ClientData
 }
 
 static int
-_wrap_PDF_close_pdi(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_close_pdi(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     EXC_STUFF;
@@ -2924,12 +2925,12 @@ _wrap_PDF_close_pdi(ClientData clientDat
 }
 
 static int
-_wrap_PDF_open_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_open_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
     int _arg1;
     int _arg2;
-    char *_arg3;
+    const char *_arg3;
     EXC_STUFF;
 
     if (argc != 5) {
@@ -2953,7 +2954,7 @@ _wrap_PDF_open_pdi_page(ClientData clien
 }
 
 static int
-_wrap_PDF_place_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_place_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     float _arg2;
@@ -2984,7 +2985,7 @@ _wrap_PDF_place_pdi_page(ClientData clie
 }
 
 static int
-_wrap_PDF_close_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_close_pdi_page(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     int _arg1;
     EXC_STUFF;
@@ -3007,10 +3008,10 @@ _wrap_PDF_close_pdi_page(ClientData clie
 }
 
 static int
-_wrap_PDF_get_pdi_parameter(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_get_pdi_parameter(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     char * _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     int _arg2;
     int _arg3;
     int _arg4;
@@ -3040,10 +3041,10 @@ _wrap_PDF_get_pdi_parameter(ClientData c
 }
 
 static int
-_wrap_PDF_get_pdi_value(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_get_pdi_value(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     float _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     int _arg2;
     int _arg3;
     int _arg4;
@@ -3071,10 +3072,10 @@ _wrap_PDF_get_pdi_value(ClientData clien
 }
 
 static int
-_wrap_PDF_makespotcolor(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_makespotcolor(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
-    char *_arg1;
+    const char *_arg1;
     int _arg2;
     EXC_STUFF;
 
@@ -3098,10 +3099,10 @@ _wrap_PDF_makespotcolor(ClientData clien
 }
 
 static int
-_wrap_PDF_setcolor(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setcolor(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
-    char *_arg1;
-    char *_arg2;
+    const char *_arg1;
+    const char *_arg2;
     float _arg3;
     float _arg4;
     float _arg5;
@@ -3131,7 +3132,7 @@ _wrap_PDF_setcolor(ClientData clientData
 }
 
 static int
-_wrap_PDF_begin_pattern(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_begin_pattern(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     int _result;
     PDF *p;
     float _arg1;
@@ -3164,7 +3165,7 @@ _wrap_PDF_begin_pattern(ClientData clien
 }
 
 static int
-_wrap_PDF_end_pattern(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_end_pattern(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     PDF *p;
     EXC_STUFF;
@@ -3186,7 +3187,7 @@ _wrap_PDF_end_pattern(ClientData clientD
 }
 
 static int
-_wrap_PDF_begin_template(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_begin_template(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     int _result;
     PDF *p;
@@ -3214,7 +3215,7 @@ _wrap_PDF_begin_template(ClientData clie
 }
 
 static int
-_wrap_PDF_end_template(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_end_template(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     PDF *p;
     EXC_STUFF;
@@ -3235,7 +3236,7 @@ _wrap_PDF_end_template(ClientData client
     return TCL_OK;
 }
 
-static int _wrap_PDF_arcn(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+static int _wrap_PDF_arcn(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     PDF *p;
     float _arg1;
@@ -3267,7 +3268,7 @@ static int _wrap_PDF_arcn(ClientData cli
 }
 
 static int
-_wrap_PDF_add_thumbnail(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_add_thumbnail(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
 
     PDF *p;
     int _arg1;
@@ -3291,7 +3292,7 @@ _wrap_PDF_add_thumbnail(ClientData clien
 }
 
 static int
-_wrap_PDF_setmatrix(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_setmatrix(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     float _arg1;
     float _arg2;
@@ -3324,7 +3325,7 @@ _wrap_PDF_setmatrix(ClientData clientDat
 }
 
 static int
-_wrap_PDF_initgraphics(ClientData clientData, Tcl_Interp *interp, int argc, char *argv[]) {
+_wrap_PDF_initgraphics(ClientData clientData, Tcl_Interp *interp, int argc, const char *argv[]) {
     PDF *p;
     EXC_STUFF;
 
