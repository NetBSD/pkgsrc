$NetBSD: patch-src_x11_fg__joystick__x11.c,v 1.2 2017/04/25 11:42:42 wiz Exp $

This code does not work on NetBSD, remove wrong ifdefs.
https://github.com/dcnieho/FreeGLUT/pull/53

--- src/x11/fg_joystick_x11.c.orig	2014-12-02 05:22:12.000000000 +0000
+++ src/x11/fg_joystick_x11.c
@@ -50,7 +50,7 @@ void fgPlatformJoystickRawRead( SFG_Joys
 {
     int status;
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
     int len;
 
     if ( joy->pJoystick.os->is_analog )
@@ -215,7 +215,7 @@ void fgPlatformJoystickRawRead( SFG_Joys
 
 void fgPlatformJoystickOpen( SFG_Joystick* joy )
 {
-#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__) || defined( __NetBSD__ )
+#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__)
 	int i = 0;
        char *cp;
 #endif
@@ -229,7 +229,7 @@ void fgPlatformJoystickOpen( SFG_Joystic
 #  endif
 #endif
 
-#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__) || defined( __NetBSD__ )
+#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__)
     for( i = 0; i < _JS_MAX_AXES; i++ )
         joy->pJoystick.os->cache_axes[ i ] = 0.0f;
 
@@ -409,7 +409,7 @@ void fgPlatformJoystickOpen( SFG_Joystic
 
 void fgPlatformJoystickInit( SFG_Joystick *fgJoystick[], int ident )
 {
-#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__) || defined( __NetBSD__ )
+#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__)
     fgJoystick[ ident ]->id = ident;
     fgJoystick[ ident ]->error = GL_FALSE;
 
@@ -436,7 +436,7 @@ void fgPlatformJoystickInit( SFG_Joystic
 
 void fgPlatformJoystickClose ( int ident )
 {
-#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__) || defined( __NetBSD__ )
+#if defined( __FreeBSD__ ) || defined(__FreeBSD_kernel__)
     if( fgJoystick[ident]->pJoystick.os )
     {
         if( ! fgJoystick[ ident ]->error )
