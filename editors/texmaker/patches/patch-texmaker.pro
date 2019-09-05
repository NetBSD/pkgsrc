$NetBSD: patch-texmaker.pro,v 1.1 2019/09/05 08:07:25 nros Exp $
* use pkgsrc (system) freetype2, hunspell, libjpeg and libpng
--- texmaker.pro.orig	2018-10-31 06:58:22.000000000 +0000
+++ texmaker.pro
@@ -25,6 +25,9 @@ message("Qt>=5.7 is required.")
 CONFIG	+= qt hide_symbols warn_off rtti_off exceptions_off c++11 release
 CONFIG -= precompile_header
 
+CONFIG += link_pkgconfig
+PKGCONFIG = freetype2 hunspell libjpeg libpng16
+
 gcc {
     QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
 }
@@ -38,16 +41,14 @@ DEFINES += \
     PNG_PREFIX \
     PNG_USE_READ_MACROS \
     V8_DEPRECATION_WARNINGS \
-    NOMINMAX \
-    FT2_BUILD_LIBRARY
+    USE_SYSTEM_LIBJPEG \
+    NOMINMAX 
 
 
 INCLUDEPATH += \
     pdfium/ \
     pdfium \
     pdfium/third_party/ \
-    pdfium/third_party/freetype/include \
-    pdfium/third_party/freetype/include/freetype \
     pdfium/fpdfsdk/include \
     pdfium/third_party/zlib_v128
 
@@ -117,25 +118,6 @@ HEADERS	+= texmaker.h \
 	unicodeview.h \
 	svnhelper.h \
 	quickbeamerdialog.h \
-	hunspell/affentry.hxx \
-	hunspell/affixmgr.hxx \
-	hunspell/atypes.hxx \
-	hunspell/baseaffix.hxx \
-	hunspell/csutil.hxx \
-	hunspell/dictmgr.hxx \
-	hunspell/hashmgr.hxx \
-	hunspell/htypes.hxx \
-	hunspell/hunspell.hxx \
-	hunspell/hunspell.h \
-	hunspell/langnum.hxx \
-	hunspell/license.hunspell \
-	hunspell/phonet.hxx \
-	hunspell/suggestmgr.hxx \
-	hunspell/license.myspell \
-	hunspell/filemgr.hxx \
-	hunspell/hunzip.hxx \
-	hunspell/replist.hxx \
-	hunspell/w_char.hxx \
 	singleapp/qtlocalpeer.h \
 	singleapp/qtlockedfile.h \
 	singleapp/qtsingleapplication.h \
@@ -350,20 +332,6 @@ HEADERS	+= texmaker.h \
     pdfium/core/fxcodec/jbig2/JBig2_Segment.h \
     pdfium/core/fxcodec/jbig2/JBig2_SymbolDict.h \
     pdfium/core/fxcodec/jbig2/JBig2_TrdProc.h \
-    pdfium/third_party/libjpeg/cderror.h \
-    pdfium/third_party/libjpeg/cdjpeg.h \
-    pdfium/third_party/libjpeg/jchuff.h \
-    pdfium/third_party/libjpeg/jconfig.h \
-    pdfium/third_party/libjpeg/jdct.h \
-    pdfium/third_party/libjpeg/jdhuff.h \
-    pdfium/third_party/libjpeg/jerror.h \
-    pdfium/third_party/libjpeg/jinclude.h \
-    pdfium/third_party/libjpeg/jmemsys.h \
-    pdfium/third_party/libjpeg/jmorecfg.h \
-    pdfium/third_party/libjpeg/jpegint.h \
-    pdfium/third_party/libjpeg/jpeglib.h \
-    pdfium/third_party/libjpeg/jversion.h \
-    pdfium/third_party/libjpeg/transupp.h \
     pdfium/third_party/lcms2-2.6/include/lcms2.h \
     pdfium/third_party/lcms2-2.6/include/lcms2_plugin.h \
     pdfium/core/fxcrt/cfx_string_c_template.h \
@@ -425,19 +393,7 @@ HEADERS	+= texmaker.h \
     pdfium/fpdfsdk/pdfwindow/PWL_ScrollBar.h \
     pdfium/fpdfsdk/pdfwindow/PWL_SpecialButton.h \
     pdfium/fpdfsdk/pdfwindow/PWL_Utils.h \
-    pdfium/fpdfsdk/pdfwindow/PWL_Wnd.h \
-    pdfium/third_party/freetype/include/freetype/freetype.h \
-    pdfium/third_party/freetype/include/freetype/ftmm.h \
-    pdfium/third_party/freetype/include/freetype/ftotval.h \
-    pdfium/third_party/freetype/include/freetype/ftoutln.h \
-    pdfium/third_party/freetype/include/freetype/internal/ftobjs.h \
-    pdfium/third_party/freetype/include/freetype/internal/ftstream.h \
-    pdfium/third_party/freetype/include/freetype/internal/tttypes.h \
-    pdfium/third_party/freetype/include/freetype/tttables.h \
-    pdfium/third_party/freetype/include/ft2build.h \
-    pdfium/third_party/freetype/src/base/ftbase.h \
-    pdfium/third_party/freetype/src/cff/cffobjs.h \
-    pdfium/third_party/freetype/src/cff/cfftypes.h
+    pdfium/fpdfsdk/pdfwindow/PWL_Wnd.h
 
 SOURCES	+= main.cpp \
     dropshadowlabel.cpp \
@@ -502,18 +458,6 @@ SOURCES	+= main.cpp \
 	unicodeview.cpp \
 	quickbeamerdialog.cpp \
 	svnhelper.cpp \
-	hunspell/affentry.cxx \
-	hunspell/affixmgr.cxx \
-	hunspell/csutil.cxx \
-	hunspell/dictmgr.cxx \
-	hunspell/hashmgr.cxx \
-	hunspell/hunspell.cxx \
-	hunspell/phonet.cxx \
-	hunspell/suggestmgr.cxx \
-	hunspell/utf_info.cxx \
-	hunspell/filemgr.cxx \
-	hunspell/replist.cxx \
-	hunspell/hunzip.cxx \
 	singleapp/qtlocalpeer.cpp \
 	singleapp/qtlockedfile.cpp \
 	singleapp/qtsingleapplication.cpp \
@@ -778,46 +722,6 @@ SOURCES	+= main.cpp \
     pdfium/core/fxcodec/jbig2/JBig2_Segment.cpp \
     pdfium/core/fxcodec/jbig2/JBig2_SymbolDict.cpp \
     pdfium/core/fxcodec/jbig2/JBig2_TrdProc.cpp \
-    pdfium/third_party/libjpeg/fpdfapi_jcapimin.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcapistd.c \
-    pdfium/third_party/libjpeg/fpdfapi_jccoefct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jccolor.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcdctmgr.c \
-    pdfium/third_party/libjpeg/fpdfapi_jchuff.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcinit.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcmainct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcmarker.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcmaster.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcomapi.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcparam.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcphuff.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcprepct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jcsample.c \
-    pdfium/third_party/libjpeg/fpdfapi_jctrans.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdapimin.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdapistd.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdcoefct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdcolor.c \
-    pdfium/third_party/libjpeg/fpdfapi_jddctmgr.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdhuff.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdinput.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdmainct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdmarker.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdmaster.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdmerge.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdphuff.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdpostct.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdsample.c \
-    pdfium/third_party/libjpeg/fpdfapi_jdtrans.c \
-    pdfium/third_party/libjpeg/fpdfapi_jerror.c \
-    pdfium/third_party/libjpeg/fpdfapi_jfdctfst.c \
-    pdfium/third_party/libjpeg/fpdfapi_jfdctint.c \
-    pdfium/third_party/libjpeg/fpdfapi_jidctfst.c \
-    pdfium/third_party/libjpeg/fpdfapi_jidctint.c \
-    pdfium/third_party/libjpeg/fpdfapi_jidctred.c \
-    pdfium/third_party/libjpeg/fpdfapi_jmemmgr.c \
-    pdfium/third_party/libjpeg/fpdfapi_jmemnobs.c \
-    pdfium/third_party/libjpeg/fpdfapi_jutils.c \
     pdfium/third_party/lcms2-2.6/src/cmscam02.c \
     pdfium/third_party/lcms2-2.6/src/cmscgats.c \
     pdfium/third_party/lcms2-2.6/src/cmscnvrt.c \
@@ -955,24 +859,7 @@ SOURCES	+= main.cpp \
     pdfium/fpdfsdk/pdfwindow/PWL_ScrollBar.cpp \
     pdfium/fpdfsdk/pdfwindow/PWL_SpecialButton.cpp \
     pdfium/fpdfsdk/pdfwindow/PWL_Utils.cpp \
-    pdfium/fpdfsdk/pdfwindow/PWL_Wnd.cpp \
-    pdfium/third_party/freetype/src/base/ftbase.c \
-    pdfium/third_party/freetype/src/base/ftbitmap.c \
-    pdfium/third_party/freetype/src/base/ftglyph.c \
-    pdfium/third_party/freetype/src/base/ftinit.c \
-    pdfium/third_party/freetype/src/base/ftlcdfil.c \
-    pdfium/third_party/freetype/src/base/ftmm.c \
-    pdfium/third_party/freetype/src/base/ftsystem.c \
-    pdfium/third_party/freetype/src/cff/cff.c \
-    pdfium/third_party/freetype/src/cid/type1cid.c \
-    pdfium/third_party/freetype/src/psaux/psaux.c \
-    pdfium/third_party/freetype/src/pshinter/pshinter.c \
-    pdfium/third_party/freetype/src/psnames/psmodule.c \
-    pdfium/third_party/freetype/src/raster/raster.c \
-    pdfium/third_party/freetype/src/sfnt/sfnt.c \
-    pdfium/third_party/freetype/src/smooth/smooth.c \
-    pdfium/third_party/freetype/src/truetype/truetype.c \
-    pdfium/third_party/freetype/src/type1/type1.c
+    pdfium/fpdfsdk/pdfwindow/PWL_Wnd.cpp
     
 equals(INTERNALBROWSER,yes){
 DEFINES += INTERNAL_BROWSER
