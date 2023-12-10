$NetBSD: patch-statsmodels_tsa_exponential__smoothing___ets__smooth.pyx,v 1.1 2023/12/10 09:41:36 wiz Exp $

Cython 3 compatibility.
https://github.com/statsmodels/statsmodels/pull/8961/

--- statsmodels/tsa/exponential_smoothing/_ets_smooth.pyx.orig	2021-10-06 09:51:52.000000000 +0000
+++ statsmodels/tsa/exponential_smoothing/_ets_smooth.pyx
@@ -1,5 +1,5 @@
 #!python
-#cython: wraparound=False, boundscheck=False, cdivision=True
+#cython: wraparound=False, boundscheck=False, cdivision=True, cpow=True
 
 from cpython cimport bool
 import numpy as np
