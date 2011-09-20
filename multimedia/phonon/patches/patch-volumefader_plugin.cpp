$NetBSD: patch-volumefader_plugin.cpp,v 1.1 2011/09/20 16:50:54 joerg Exp $

--- xine/volumefader_plugin.cpp.orig	2010-06-07 14:36:25.000000000 +0000
+++ xine/volumefader_plugin.cpp
@@ -141,10 +141,10 @@ typedef struct
 static const char *enum_fadeCurve[] = { "Fade3Decibel", "Fade6Decibel", "Fade9Decibel", "Fade12Decibel", NULL };
 
 START_PARAM_DESCR(kvolumefader_parameters_t)
-PARAM_ITEM(POST_PARAM_TYPE_INT, fadeCurve, const_cast<char**>(enum_fadeCurve), 0.0, 0.0, 0, const_cast<char*>( I18N_NOOP("fade curve") ))
-PARAM_ITEM(POST_PARAM_TYPE_DOUBLE, currentVolume, NULL, 0.0, maxVolume, 0, const_cast<char*>( I18N_NOOP("current volume") ))
-PARAM_ITEM(POST_PARAM_TYPE_DOUBLE, fadeTo, NULL, 0.0, maxVolume, 0, const_cast<char*>( I18N_NOOP("volume to fade to") ))
-PARAM_ITEM(POST_PARAM_TYPE_INT, fadeTime, NULL, 0.0, 10000.0, 0, const_cast<char*>( I18N_NOOP("fade time in milliseconds") ))
+PARAM_ITEM(kvolumefader_parameters_t, POST_PARAM_TYPE_INT, fadeCurve, const_cast<char**>(enum_fadeCurve), 0.0, 0.0, 0, const_cast<char*>( I18N_NOOP("fade curve") ))
+PARAM_ITEM(kvolumefader_parameters_t, POST_PARAM_TYPE_DOUBLE, currentVolume, NULL, 0.0, maxVolume, 0, const_cast<char*>( I18N_NOOP("current volume") ))
+PARAM_ITEM(kvolumefader_parameters_t, POST_PARAM_TYPE_DOUBLE, fadeTo, NULL, 0.0, maxVolume, 0, const_cast<char*>( I18N_NOOP("volume to fade to") ))
+PARAM_ITEM(kvolumefader_parameters_t, POST_PARAM_TYPE_INT, fadeTime, NULL, 0.0, 10000.0, 0, const_cast<char*>( I18N_NOOP("fade time in milliseconds") ))
 END_PARAM_DESCR(param_descr)
 
 static int set_parameters (xine_post_t *this_gen, void *param_gen) 
