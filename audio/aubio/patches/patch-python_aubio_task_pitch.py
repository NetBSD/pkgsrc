$NetBSD: patch-python_aubio_task_pitch.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/task/pitch.py.orig	2006-07-26 23:27:19.000000000 +0000
+++ python/aubio/task/pitch.py
@@ -156,7 +156,7 @@ class taskpitch(task):
 
 		time = [ (i+self.params.pitchdelay)*self.params.step for i in range(len(pitch)) ]
 		pitch = [aubio_freqtomidi(i) for i in pitch]
-		oplots.append(Gnuplot.Data(time,pitch,with='lines',
+		oplots.append(Gnuplot.Data(time,pitch,with_='lines',
 			title=self.params.pitchmode))
 		titles.append(self.params.pitchmode)
 
@@ -170,7 +170,7 @@ class taskpitch(task):
 		if truth:
 			timet,pitcht = self.gettruth()
 			if timet and pitcht:
-				oplots = [Gnuplot.Data(timet,pitcht,with='lines',
+				oplots = [Gnuplot.Data(timet,pitcht,with_='lines',
 					title='ground truth')] + oplots
 
 		g = gnuplot_create(outplot=outplot, extension=extension)
