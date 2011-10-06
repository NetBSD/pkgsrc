$NetBSD: patch-python_aubio_bench_onset.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/bench/onset.py.orig	2006-07-26 23:27:19.000000000 +0000
+++ python/aubio/bench/onset.py
@@ -111,7 +111,7 @@ class benchonset(bench):
 		for i in self.vlist:
 			gd.append(i['GD']) 
 			fp.append(i['FP']) 
-		d.append(Gnuplot.Data(fp, gd, with='linespoints', 
+		d.append(Gnuplot.Data(fp, gd, with_='linespoints', 
 			title="%s %s" % (plottitle,i['mode']) ))
 
 	def plotplotroc(self,d,outplot=0,extension='ps'):
@@ -147,7 +147,7 @@ class benchonset(bench):
 		for i in self.vlist:
 			x.append(i['prec']) 
 			y.append(i['recl']) 
-		d.append(Gnuplot.Data(x, y, with='linespoints', 
+		d.append(Gnuplot.Data(x, y, with_='linespoints', 
 			title="%s %s" % (plottitle,i['mode']) ))
 
 	def plotplotpr(self,d,outplot=0,extension='ps'):
@@ -172,7 +172,7 @@ class benchonset(bench):
 		for i in self.vlist:
 			x.append(i['thres']) 
 			y.append(i['dist']) 
-		d.append(Gnuplot.Data(x, y, with='linespoints', 
+		d.append(Gnuplot.Data(x, y, with_='linespoints', 
 			title="%s %s" % (plottitle,i['mode']) ))
 
 	def plotplotfmeas(self,d,outplot="",extension='ps', title="F-measure"):
@@ -205,7 +205,7 @@ class benchonset(bench):
 		for i in self.vlist:
 			x.append(i[var]) 
 			y.append(i['dist']) 
-		d.append(Gnuplot.Data(x, y, with='linespoints', 
+		d.append(Gnuplot.Data(x, y, with_='linespoints', 
 			title="%s %s" % (plottitle,i['mode']) ))
 	
 	def plotplotfmeasvar(self,d,var,outplot="",extension='ps', title="F-measure"):
@@ -244,7 +244,7 @@ class benchonset(bench):
 		total = v['Torig']
 		for i in range(len(per)): per[i] /= total/100.
 
-		d.append(Gnuplot.Data(val, per, with='fsteps', 
+		d.append(Gnuplot.Data(val, per, with_='fsteps', 
 			title="%s %s" % (plottitle,v['mode']) ))
 		#d.append('mean=%f,sigma=%f,eps(x) title \"\"'% (mean,smean))
 		#d.append('mean=%f,sigma=%f,eps(x) title \"\"'% (amean,samean))
@@ -275,7 +275,7 @@ class benchonset(bench):
 		total = v['Torig']
 		for i in range(len(per)): per[i] /= total/100.
 
-		d.append(Gnuplot.Data(val, per, with='fsteps', 
+		d.append(Gnuplot.Data(val, per, with_='fsteps', 
 			title="%s %s" % (plottitle,v['mode']) ))
 		#d.append('mean=%f,sigma=%f,eps(x) title \"\"'% (mean,smean))
 		#d.append('mean=%f,sigma=%f,eps(x) title \"\"'% (amean,samean))
