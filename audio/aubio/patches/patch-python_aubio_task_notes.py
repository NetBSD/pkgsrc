$NetBSD: patch-python_aubio_task_notes.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/task/notes.py.orig	2006-07-26 23:27:19.000000000 +0000
+++ python/aubio/task/notes.py
@@ -95,15 +95,15 @@ class tasknotes(task):
 		import numarray
 		import Gnuplot
 
-		oplots.append(Gnuplot.Data(now,freq,with='lines',
+		oplots.append(Gnuplot.Data(now,freq,with_='lines',
 			title=self.params.pitchmode))
-		oplots.append(Gnuplot.Data(now,ifreq,with='lines',
+		oplots.append(Gnuplot.Data(now,ifreq,with_='lines',
 			title=self.params.pitchmode))
 
 		temponsets = []
 		for i in onset:
 			temponsets.append(i*1000)
-		oplots.append(Gnuplot.Data(now,temponsets,with='impulses',
+		oplots.append(Gnuplot.Data(now,temponsets,with_='impulses',
 			title=self.params.pitchmode))
 
 	def plotplot(self,wplot,oplots,outplot=None,multiplot = 0):
@@ -117,10 +117,10 @@ class tasknotes(task):
 		# check if ground truth exists
 		#timet,pitcht = self.gettruth()
 		#if timet and pitcht:
-		#	oplots = [Gnuplot.Data(timet,pitcht,with='lines',
+		#	oplots = [Gnuplot.Data(timet,pitcht,with_='lines',
 		#		title='ground truth')] + oplots
 
-		t = Gnuplot.Data(0,0,with='impulses') 
+		t = Gnuplot.Data(0,0,with_='impulses') 
 
 		g = gnuplot_init(outplot)
 		g('set title \'%s\'' % (re.sub('.*/','',self.input)))
