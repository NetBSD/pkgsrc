$NetBSD: patch-libkdcraw_kdcraw__p.cpp,v 1.1 2019/11/02 17:09:55 maya Exp $

Fix with libraw 0.19
from https://github.com/KDE/libkdcraw/commit/f40ebe30dca1cfadc8171364ac325532e6c3f229

--- libkdcraw/kdcraw_p.cpp.orig	2015-05-14 20:54:16.000000000 +0000
+++ libkdcraw/kdcraw_p.cpp
@@ -367,6 +367,7 @@ bool KDcraw::Private::loadFromLibraw(con
             raw.imgdata.params.fbdd_noiserd = lround(m_parent->m_rawDecodingSettings.NRThreshold / 100.0);
             break;
         }
+#if !LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 19)
         case RawDecodingSettings::LINENR:
         {
             // (100 - 1000) => (0.001 - 0.02) conversion.
@@ -374,7 +375,6 @@ bool KDcraw::Private::loadFromLibraw(con
             raw.imgdata.params.cfaline      = true;
             break;
         }
-
         case RawDecodingSettings::IMPULSENR:
         {
             // (100 - 1000) => (0.005 - 0.05) conversion.
@@ -383,23 +383,28 @@ bool KDcraw::Private::loadFromLibraw(con
             raw.imgdata.params.cfa_clean    = true;
             break;
         }
+#endif
         default:   // No Noise Reduction
         {
             raw.imgdata.params.threshold    = 0;
             raw.imgdata.params.fbdd_noiserd = 0;
+#if !LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 19)
             raw.imgdata.params.linenoise    = 0;
             raw.imgdata.params.cfaline      = false;
             raw.imgdata.params.lclean       = 0;
             raw.imgdata.params.cclean       = 0;
             raw.imgdata.params.cfa_clean    = false;
+#endif
             break;
         }
     }
 
+#if !LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 19)
     // Chromatic aberration correction.
     raw.imgdata.params.ca_correc  = m_parent->m_rawDecodingSettings.enableCACorrection;
     raw.imgdata.params.cared      = m_parent->m_rawDecodingSettings.caMultiplier[0];
     raw.imgdata.params.cablue     = m_parent->m_rawDecodingSettings.caMultiplier[1];
+#endif
 
     // Exposure Correction before interpolation.
     raw.imgdata.params.exp_correc = m_parent->m_rawDecodingSettings.expoCorrection;
@@ -453,9 +458,10 @@ bool KDcraw::Private::loadFromLibraw(con
 
     raw.imgdata.params.dcb_iterations = m_parent->m_rawDecodingSettings.dcbIterations;
     raw.imgdata.params.dcb_enhance_fl = m_parent->m_rawDecodingSettings.dcbEnhanceFl;
+#if !LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 19)
     raw.imgdata.params.eeci_refine    = m_parent->m_rawDecodingSettings.eeciRefine;
     raw.imgdata.params.es_med_passes  = m_parent->m_rawDecodingSettings.esMedPasses;
-
+#endif
     //-------------------------------------------------------------------------------------------
 
     setProgress(0.1);
