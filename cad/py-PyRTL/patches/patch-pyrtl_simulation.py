$NetBSD: patch-pyrtl_simulation.py,v 1.1 2025/12/27 16:31:08 ryoon Exp $

--- pyrtl/simulation.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ pyrtl/simulation.py
@@ -1773,6 +1773,16 @@ class SimulationTrace:
             display(html_elem)
             # print(htmlstring)
             js_stuff = """
+            function fetchAndRunScript(uri) {
+              return fetch(uri)
+                .then(resp => resp.text())
+                .then(scrtext => {
+                  const scrfunc = new Function(scrtext);
+                  scrfunc();
+                })
+                .catch(err => console.error('Cannot load script:', err));
+            }
+            fetchAndRunScript("https://cdnjs.cloudflare.com/ajax/libs/jquery/3.7.1/jquery.min.js").then(() => {
             $.when(
             $.getScript("https://cdnjs.cloudflare.com/ajax/libs/wavedrom/1.6.2/skins/default.js"),
             $.getScript("https://cdnjs.cloudflare.com/ajax/libs/wavedrom/1.6.2/wavedrom.min.js"),
@@ -1780,7 +1790,7 @@ class SimulationTrace:
                 $( deferred.resolve );
             })).done(function(){
                 WaveDrom.ProcessAll();
-            });"""
+            });});"""
             display(Javascript(js_stuff))
         else:
             self.render_trace_to_text(
