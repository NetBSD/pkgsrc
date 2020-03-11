$NetBSD: patch-chavier_gui.py,v 1.1 2020/03/11 20:17:12 wiz Exp $

Convert to python3 syntax.

--- chavier/gui.py.orig	2011-08-08 19:23:18.000000000 +0000
+++ chavier/gui.py
@@ -523,18 +523,18 @@ class GUI(object):
 
         alloc = self.drawing_area.get_allocation()
 
-        print 'CHART STATE'
-        print '-' * 70
-        print 'surface: %d x %d' % (alloc.width, alloc.height)
-        print 'area   :', self.chart.area
-        print
-        print 'minxval:', self.chart.minxval
-        print 'maxxval:', self.chart.maxxval
-        print 'xrange :', self.chart.xrange
-        print
-        print 'minyval:', self.chart.minyval
-        print 'maxyval:', self.chart.maxyval
-        print 'yrange :', self.chart.yrange
+        print('CHART STATE')
+        print('-' * 70)
+        print('surface: %d x %d' % (alloc.width, alloc.height))
+        print('area   :', self.chart.area)
+        prin()
+        print('minxval:', self.chart.minxval)
+        print('maxxval:', self.chart.maxxval)
+        print('xrange :', self.chart.xrange)
+        print()
+        print('minyval:', self.chart.minyval)
+        print('maxyval:', self.chart.maxyval)
+        print('yrange :', self.chart.yrange)
 
     def about(self, action=None):
         dialog = AboutDialog(self.main_window)
