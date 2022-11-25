$NetBSD: patch-hscommon_gui_selectable__list.py,v 1.1 2022/11/25 08:35:17 wiz Exp $

Support python 3.10.

--- hscommon/gui/selectable_list.py.orig	2018-11-27 17:30:37.000000000 +0000
+++ hscommon/gui/selectable_list.py
@@ -6,7 +6,7 @@
 # which should be included with this package. The terms are also available at 
 # http://www.gnu.org/licenses/gpl-3.0.html
 
-from collections import Sequence, MutableSequence
+from collections.abc import Sequence, MutableSequence
 
 from .base import GUIObject
 
