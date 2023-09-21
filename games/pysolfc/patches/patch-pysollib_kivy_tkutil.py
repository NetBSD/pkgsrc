$NetBSD: patch-pysollib_kivy_tkutil.py,v 1.1 2023/09/21 08:12:35 dholland Exp $

Update names of py-Pillow constants for version 10.x.

--- pysollib/kivy/tkutil.py~	2021-06-13 03:25:14.000000000 +0000
+++ pysollib/kivy/tkutil.py
@@ -489,7 +489,7 @@ def createBottom(image, color='white', b
     size = (w - th * 2, h - th * 2)
     tmp = Image.new('RGBA', size, color)
     tmp.putalpha(60)
-    mask = out.resize(size, Image.ANTIALIAS)
+    mask = out.resize(size, Image.Resampling.LANCZOS)
     out.paste(tmp, (th, th), mask)
     if backfile:
         back = Image.open(backfile).convert('RGBA')
@@ -498,7 +498,7 @@ def createBottom(image, color='white', b
         a = min(float(w1) / w0, float(h1) / h0)
         a = a * 0.9
         w0, h0 = int(w0 * a), int(h0 * a)
-        back = back.resize((w0, h0), Image.ANTIALIAS)
+        back = back.resize((w0, h0), Image.Resampling.LANCZOS)
         x, y = (w1 - w0) / 2, (h1 - h0) / 2
         out.paste(back, (x, y), back)
     return PIL_Image(image=out)
