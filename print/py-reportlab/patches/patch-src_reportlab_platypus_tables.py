$NetBSD: patch-src_reportlab_platypus_tables.py,v 1.1.2.2 2017/11/06 19:11:47 bsiegert Exp $

b6902985cf64efab2c1259a42b06e0eddbe93805:
attempt to remove quadratic performance hit when longTableOptimize is set

--- src/reportlab/platypus/tables.py.orig	2016-02-17 12:30:12.000000000 +0000
+++ src/reportlab/platypus/tables.py
@@ -204,7 +204,7 @@ class Table(Flowable):
     def __init__(self, data, colWidths=None, rowHeights=None, style=None,
                 repeatRows=0, repeatCols=0, splitByRow=1, emptyTableAction=None, ident=None,
                 hAlign=None,vAlign=None, normalizedData=0, cellStyles=None, rowSplitRange=None,
-                spaceBefore=None,spaceAfter=None):
+                spaceBefore=None,spaceAfter=None, longTableOptimize=None):
         self.ident = ident
         self.hAlign = hAlign or 'CENTER'
         self.vAlign = vAlign or 'MIDDLE'
@@ -218,7 +218,8 @@ class Table(Flowable):
         elif colWidths and _seqCW: ncols = len(colWidths)
         else: ncols = 0
         if not emptyTableAction: emptyTableAction = rl_config.emptyTableAction
-        self._longTableOptimize = getattr(self,'_longTableOptimize',rl_config.longTableOptimize)
+        self._longTableOptimize = (getattr(self,'_longTableOptimize',rl_config.longTableOptimize)
+                                    if longTableOptimize is None else longTableOptimize)
         if not (nrows and ncols):
             if emptyTableAction=='error':
                 raise ValueError("%s must have at least a row and column" % self.identity())
@@ -583,19 +584,19 @@ class Table(Flowable):
                 H[i] = h
                 # we can stop if we have filled up all available room
                 if longTable:
-                    hmax = i
-                    height = sum(H[:i])
+                    hmax = i+1      #we computed H[i] so known len == i+1
+                    height = sum(H[:hmax])
                     if height > availHeight:
-                        #we can terminate if all spans are complete in H[:i]
+                        #we can terminate if all spans are complete in H[:hmax]
                         if spanCons:
-                            msr = max([x[1] for x in spanCons.keys()])  #RS=[endrowspan,.....]
-                            if hmax>=msr:
+                            msr = max(x[1] for x in spanCons.keys())    #RS=[endrowspan,.....]
+                            if hmax>msr:
                                 break
             if None not in H: hmax = lim
 
             if spanCons:
                 try:
-                    spanFixDim(H0,H,spanCons,lim=hmax)
+                    spanFixDim(H0,H,spanCons)
                 except:
                     annotateException('\nspanning problem in %s hmax=%s lim=%s avail=%s x %s\nH0=%r H=%r\nspanCons=%r' % (self.identity(),hmax,lim,availWidth,availHeight,H0,H,spanCons))
 
@@ -1260,11 +1261,17 @@ class Table(Flowable):
         #we're going to split into two superRows
         ident = self.ident
         if ident: ident = IdentStr(ident)
-        R0 = self.__class__( data[:n], colWidths=self._colWidths, rowHeights=self._argH[:n],
+        lto = self._longTableOptimize
+        if lto:
+            splitH = self._rowHeights
+        else:
+            splitH = self._argH
+        R0 = self.__class__( data[:n], colWidths=self._colWidths, rowHeights=splitH[:n],
                 repeatRows=repeatRows, repeatCols=repeatCols,
                 splitByRow=splitByRow, normalizedData=1, cellStyles=self._cellStyles[:n],
                 ident=ident,
-                spaceBefore=getattr(self,'spaceBefore',None))
+                spaceBefore=getattr(self,'spaceBefore',None),
+                longTableOptimize=lto)
 
         nrows = self._nrows
         ncols = self._ncols
@@ -1324,22 +1331,23 @@ class Table(Flowable):
             if isinstance(repeatRows,int):
                 iRows = data[:repeatRows]
                 nRepeatRows = repeatRows
-                iRowH = self._argH[:repeatRows]
+                iRowH = splitH[:repeatRows]
                 iCS = self._cellStyles[:repeatRows]
             else:
                 #we have a list of repeated rows eg (1,3)
                 repeatRows = list(sorted(repeatRows))
                 iRows = [data[i] for i in repeatRows]
                 nRepeatRows = len(repeatRows)
-                iRowH = [self._argH[i] for i in repeatRows]
+                iRowH = [splitH[i] for i in repeatRows]
                 iCS = [self._cellStyles[i] for i in repeatRows]
             R1 = self.__class__(iRows+data[n:],colWidths=self._colWidths,
-                    rowHeights=iRowH+self._argH[n:],
+                    rowHeights=iRowH+splitH[n:],
                     repeatRows=nRepeatRows, repeatCols=repeatCols,
                     splitByRow=splitByRow, normalizedData=1,
                     cellStyles=iCS+self._cellStyles[n:],
                     ident=ident,
                     spaceAfter=getattr(self,'spaceAfter',None),
+                    longTableOptimize=lto,
                     )
             R1._cr_1_1(n,nRepeatRows,A)
             R1._cr_1_1(n,nRepeatRows,self._bkgrndcmds)
@@ -1352,6 +1360,7 @@ class Table(Flowable):
                     splitByRow=splitByRow, normalizedData=1, cellStyles=self._cellStyles[n:],
                     ident=ident,
                     spaceAfter=getattr(self,'spaceAfter',None),
+                    longTableOptimize=lto,
                     )
             R1._cr_1_0(n,A)
             R1._cr_1_0(n,self._bkgrndcmds)
