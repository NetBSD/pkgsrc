$NetBSD: patch-pysollib_ui_tktile_tkutil.py,v 1.1 2023/09/21 08:12:35 dholland Exp $

Update names of py-Pillow constants for version 10.x.

--- pysollib/ui/tktile/tkutil.py~	2021-06-13 03:25:15.000000000 +0000
+++ pysollib/ui/tktile/tkutil.py
@@ -268,7 +268,7 @@ if Image:
         def resize(self, xf, yf):
             w, h = self._pil_image_orig.size
             w0, h0 = int(w*xf), int(h*yf)
-            im = self._pil_image_orig.resize((w0, h0), Image.ANTIALIAS)
+            im = self._pil_image_orig.resize((w0, h0), Image.Resampling.LANCZOS)
             return PIL_Image(image=im, pil_image_orig=self._pil_image_orig)
 
 
@@ -381,7 +381,7 @@ def _createBottomImage(image, color='whi
     size = (w-th*2, h-th*2)
     tmp = Image.new('RGBA', size, color)
     tmp.putalpha(60)
-    mask = out.resize(size, Image.ANTIALIAS)
+    mask = out.resize(size, Image.Resampling.LANCZOS)
     out.paste(tmp, (th, th), mask)
     if backfile:
         back = Image.open(backfile).convert('RGBA')
@@ -390,7 +390,7 @@ def _createBottomImage(image, color='whi
         a = min(float(w1)/w0, float(h1)/h0)
         a = a*0.9
         w0, h0 = int(w0*a), int(h0*a)
-        back = back.resize((w0, h0), Image.ANTIALIAS)
+        back = back.resize((w0, h0), Image.Resampling.LANCZOS)
         x, y = (w1 - w0) // 2, (h1 - h0) // 2
         out.paste(back, (x, y), back)
     return out
