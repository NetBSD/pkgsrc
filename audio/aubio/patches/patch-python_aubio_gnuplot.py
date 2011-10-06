$NetBSD: patch-python_aubio_gnuplot.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/gnuplot.py.orig	2006-08-24 02:13:22.000000000 +0000
+++ python/aubio/gnuplot.py
@@ -155,7 +155,7 @@ def make_audio_plot(time,data,maxpoints=
   """ create gnuplot plot from an audio file """
   import Gnuplot, Gnuplot.funcutils
   x,y = downsample_audio(time,data,maxpoints=maxpoints)
-  return Gnuplot.Data(x,y,with='lines')
+  return Gnuplot.Data(x,y,with_='lines')
 
 def make_audio_envelope(time,data,maxpoints=10000):
   """ create gnuplot plot from an audio file """
@@ -165,7 +165,7 @@ def make_audio_envelope(time,data,maxpoi
   x = [i.mean() for i in numarray.array(time).resize(len(time)/bufsize,bufsize)] 
   y = [i.mean() for i in numarray.array(data).resize(len(time)/bufsize,bufsize)] 
   x,y = downsample_audio(x,y,maxpoints=maxpoints)
-  return Gnuplot.Data(x,y,with='lines')
+  return Gnuplot.Data(x,y,with_='lines')
 
 def gnuplot_addargs(parser):
   """ add common gnuplot argument to OptParser object """
