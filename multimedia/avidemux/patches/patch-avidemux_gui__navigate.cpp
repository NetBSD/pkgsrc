$NetBSD: patch-avidemux_gui__navigate.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: error: call of overloaded 'abs(__uint32_t)' is ambiguous

--- avidemux/gui_navigate.cpp.orig	2008-09-13 17:47:05.000000000 +0000
+++ avidemux/gui_navigate.cpp
@@ -243,7 +243,7 @@ void GUI_NextPrevBlackFrame(int dir)
         else total=curframe+1;
    while(1)
    {
-        int current=abs(curframe-orgFrame);
+        int current=abs((int64_t)curframe-(int64_t)orgFrame);
       f=curframe+dir;
       if(work->update(current,total)) break;
 
