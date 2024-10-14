$NetBSD: patch-src_tootstream_toot.py,v 1.4 2024/10/14 08:24:43 nia Exp $

underlined may not be supported by the target terminal, e.g.
tmux running in xterm on netbsd

--- src/tootstream/toot.py.orig	2024-10-14 08:23:05.679872648 +0000
+++ src/tootstream/toot.py
@@ -1040,7 +1040,7 @@ def help(mastodon, rest):
             if new_section:
                 cprint(
                     "{section}:".format(section=section),
-                    fg("white") + attr("bold") + attr("underlined"),
+                    fg("white") + attr("bold"),
                 )
                 new_section = False
 
@@ -1091,11 +1091,11 @@ def toot(mastodon, rest):
             cprint("You tooted: ", fg("white") + attr("bold"), end="\n")
             if resp["sensitive"]:
                 cprint("CW: " + resp["spoiler_text"], fg("red"))
-            cprint(text, fg("magenta") + attr("bold") + attr("underlined"))
+            cprint(text, fg("magenta") + attr("bold"))
             posted = True
         except Exception as e:
             cprint("Received error: ", fg("red") + attr("bold"), end="")
-            cprint(e, fg("magenta") + attr("bold") + attr("underlined"))
+            cprint(e, fg("magenta") + attr("bold"))
 
         # If we're streaming then we can't edit the toot, so assume that we posted.
         if is_streaming is True:
@@ -1267,7 +1267,7 @@ def boost(mastodon, rest):
         cprint(msg, attr("dim"))
     except Exception as e:
         cprint("Received error: ", fg("red") + attr("bold"), end="")
-        cprint(e, fg("magenta") + attr("bold") + attr("underlined"))
+        cprint(e, fg("magenta") + attr("bold"))
 
 
 @command("<id>", "Toots")
