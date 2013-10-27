$NetBSD: patch-src_celengine_command.cpp,v 1.1 2013/10/27 21:21:26 dholland Exp $

Fix build with lua switched off.
(This is probably not the right place to switch it off, but it does
build this way.)

--- src/celengine/command.cpp~	2013-10-27 20:32:16.000000000 +0000
+++ src/celengine/command.cpp
@@ -11,7 +11,9 @@
 #include <celutil/util.h>
 #include <celestia/celestiacore.h>
 #include <celestia/imagecapture.h>
+#ifdef CELX
 #include <celestia/celx_internal.h>
+#endif
 #include "astro.h"
 #include "command.h"
 #include "execution.h"
@@ -773,6 +775,7 @@ CommandSplitView::CommandSplitView(unsig
 
 void CommandSplitView::process(ExecutionEnvironment& env)
 {
+#ifdef CELX
     vector<Observer*> observer_list;
     getObservers(env.getCelestiaCore(), observer_list);
 
@@ -785,6 +786,7 @@ void CommandSplitView::process(Execution
         View::Type type = (compareIgnoringCase(splitType, "h") == 0) ? View::HorizontalSplit : View::VerticalSplit;
         env.getCelestiaCore()->splitView(type, view, (float)splitPos);
     }
+#endif
 }
 
 
@@ -796,6 +800,7 @@ CommandDeleteView::CommandDeleteView(uns
 
 void CommandDeleteView::process(ExecutionEnvironment& env)
 {
+#ifdef CELX
     vector<Observer*> observer_list;
     getObservers(env.getCelestiaCore(), observer_list);
 
@@ -807,6 +810,7 @@ void CommandDeleteView::process(Executio
         View* view = getViewByObserver(env.getCelestiaCore(), obs);
         env.getCelestiaCore()->deleteView(view);
     }
+#endif
 }
 
 
@@ -817,8 +823,10 @@ CommandSingleView::CommandSingleView()
 
 void CommandSingleView::process(ExecutionEnvironment& env)
 {
+#ifdef CELX
     View* view = getViewByObserver(env.getCelestiaCore(), env.getSimulation()->getActiveObserver());
     env.getCelestiaCore()->singleView(view);
+#endif
 }
 
 
@@ -834,6 +840,7 @@ CommandSetActiveView::CommandSetActiveVi
 
 void CommandSetActiveView::process(ExecutionEnvironment& env)
 {
+#ifdef CELX
     vector<Observer*> observer_list;
     getObservers(env.getCelestiaCore(), observer_list);
 
@@ -843,6 +850,7 @@ void CommandSetActiveView::process(Execu
         View* view = getViewByObserver(env.getCelestiaCore(), obs);
         env.getCelestiaCore()->setActiveView(view);
     }
+#endif
 }
 
 
@@ -892,6 +900,7 @@ CommandSetLineColor::CommandSetLineColor
 
 void CommandSetLineColor::process(ExecutionEnvironment& /* env */)
 {
+#ifdef CELX
     if (CelxLua::LineColorMap.count(item) == 0)
     {
         cerr << "Unknown line style: " << item << "\n";
@@ -900,6 +909,7 @@ void CommandSetLineColor::process(Execut
     {
         *CelxLua::LineColorMap[item] = color;
     }
+#endif
 }
 
 
@@ -914,6 +924,7 @@ CommandSetLabelColor::CommandSetLabelCol
 
 void CommandSetLabelColor::process(ExecutionEnvironment& /* env */)
 {
+#ifdef CELX
     if (CelxLua::LabelColorMap.count(item) == 0)
     {
         cerr << "Unknown label style: " << item << "\n";
@@ -922,6 +933,7 @@ void CommandSetLabelColor::process(Execu
     {
         *CelxLua::LabelColorMap[item] = color;
     }
+#endif
 }
 
 
