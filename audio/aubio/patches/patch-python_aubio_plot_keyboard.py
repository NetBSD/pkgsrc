$NetBSD: patch-python_aubio_plot_keyboard.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/plot/keyboard.py.orig	2006-07-26 23:27:19.000000000 +0000
+++ python/aubio/plot/keyboard.py
@@ -30,8 +30,8 @@ def draw_keyboard(firstnote = 21, lastno
   yb      = [y0+(y1-y0)*2/3. for i in range(len(xb))]
   ybdelta = [(y1-y0)*1/3. for i in range(len(xb))]
 
-  whites  = Gnuplot.Data(xw,yw,xwdelta,ywdelta,with = 'boxxyerrorbars')
-  blacks  = Gnuplot.Data(xb,yb,xbdelta,ybdelta,with = 'boxxyerrorbars fill solid')
+  whites  = Gnuplot.Data(xw,yw,xwdelta,ywdelta,with_ = 'boxxyerrorbars')
+  blacks  = Gnuplot.Data(xb,yb,xbdelta,ybdelta,with_ = 'boxxyerrorbars fill solid')
 
   return blacks,whites
 
