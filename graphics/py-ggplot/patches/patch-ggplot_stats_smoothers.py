$NetBSD: patch-ggplot_stats_smoothers.py,v 1.1 2019/06/17 20:27:16 adam Exp $

Fix for newer Pandas.

--- ggplot/stats/smoothers.py.orig	2019-06-17 20:04:57.000000000 +0000
+++ ggplot/stats/smoothers.py
@@ -1,7 +1,6 @@
 from __future__ import (absolute_import, division, print_function,
                         unicode_literals)
 import numpy as np
-from pandas.lib import Timestamp
 import pandas as pd
 import statsmodels.api as sm
 from statsmodels.nonparametric.smoothers_lowess import lowess as smlowess
@@ -11,7 +10,7 @@ import scipy.stats as stats
 import datetime
 
 date_types = (
-    pd.tslib.Timestamp,
+    pd.Timestamp,
     pd.DatetimeIndex,
     pd.Period,
     pd.PeriodIndex,
