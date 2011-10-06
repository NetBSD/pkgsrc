$NetBSD: patch-python_aubio_task_beat.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/task/beat.py.orig	2006-09-25 19:26:08.000000000 +0000
+++ python/aubio/task/beat.py
@@ -247,7 +247,7 @@ class taskbeat(taskonset):
 
 	def plot(self,oplots,results):
 		import Gnuplot
-		oplots.append(Gnuplot.Data(results,with='linespoints',title="auto"))
+		oplots.append(Gnuplot.Data(results,with_='linespoints',title="auto"))
 
 	def plotplot(self,wplot,oplots,outplot=None,extension=None,xsize=1.,ysize=1.,spectro=False):
 		import Gnuplot
@@ -258,5 +258,5 @@ class taskbeat(taskonset):
 		#f = make_audio_plot(time,data)
 
 		g = gnuplot_create(outplot=outplot, extension=extension)
-		oplots = [Gnuplot.Data(self.gettruth(),with='linespoints',title="orig")] + oplots
+		oplots = [Gnuplot.Data(self.gettruth(),with_='linespoints',title="orig")] + oplots
 		g.plot(*oplots)
