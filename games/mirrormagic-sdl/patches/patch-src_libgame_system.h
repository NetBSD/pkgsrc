$NetBSD: patch-src_libgame_system.h,v 1.1 2012/08/10 18:04:53 joerg Exp $

--- src/libgame/system.h.orig	2002-03-19 02:42:52.000000000 +0000
+++ src/libgame/system.h
@@ -278,6 +278,8 @@ void InitGfxDoor1Info(int, int, int, int
 void InitGfxDoor2Info(int, int, int, int);
 void InitGfxScrollbufferInfo(int, int);
 
+#define inline
+
 inline void InitVideoDisplay(void);
 inline void CloseVideoDisplay(void);
 inline void InitVideoBuffer(DrawBuffer **,DrawWindow **, int,int,int, boolean);
@@ -315,4 +317,6 @@ inline void NextEvent(Event *event);
 inline Key GetEventKey(KeyEvent *, boolean);
 inline boolean CheckCloseWindowEvent(ClientMessageEvent *);
 
+#undef inline
+
 #endif /* SYSTEM_H */
