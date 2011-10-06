$NetBSD: patch-python_aubio_task_onset.py,v 1.1.1.1 2011/10/06 11:45:48 ryoon Exp $

* After 2.6, with is reserved and must not be used as variable.

--- python/aubio/task/onset.py.orig	2006-08-11 12:27:47.000000000 +0000
+++ python/aubio/task/onset.py
@@ -103,7 +103,7 @@ class taskonset(task):
 		self.maxofunc = max(ofunc)
 		# onset detection function 
 		downtime = numarray.arange(len(ofunc))*self.params.step
-		oplot.append(Gnuplot.Data(downtime,ofunc,with='lines',title=self.params.onsetmode))
+		oplot.append(Gnuplot.Data(downtime,ofunc,with_='lines',title=self.params.onsetmode))
 
 		# detected onsets
 		if not nplot:
@@ -114,8 +114,8 @@ class taskonset(task):
 			#x1 = numarray.array(onsets)*self.params.step
 			#y1 = self.maxofunc*numarray.ones(len(onsets))
 			if x1:
-				oplot.append(Gnuplot.Data(x1,y1,with='impulses'))
-				wplot.append(Gnuplot.Data(x1,y1p,with='impulses'))
+				oplot.append(Gnuplot.Data(x1,y1,with_='impulses'))
+				wplot.append(Gnuplot.Data(x1,y1p,with_='impulses'))
 
 		oplots.append((oplot,self.params.onsetmode,self.maxofunc))
 
@@ -128,7 +128,7 @@ class taskonset(task):
 			t_onsets = aubio.txtfile.read_datafile(datafile)
 			x2 = numarray.array(t_onsets).resize(len(t_onsets))
 			y2 = self.maxofunc*numarray.ones(len(t_onsets))
-			wplot.append(Gnuplot.Data(x2,y2,with='impulses'))
+			wplot.append(Gnuplot.Data(x2,y2,with_='impulses'))
 			
 			tol = 0.050 
 
