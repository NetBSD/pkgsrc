$NetBSD: patch-setup.py,v 1.1 2017/07/03 11:54:52 wiedi Exp $

support PKGLOCALEDIR
--- setup.py.orig	2003-11-02 03:41:32.000000000 +0000
+++ setup.py
@@ -19,7 +19,7 @@ for mo in mo_dirs:
 	p, lang = os.path.split(mo)
 	if lang == "nicotine.pot":
 		continue
-	translations.append((os.path.join(sys.prefix, "share", "locale", lang, "LC_MESSAGES"), [os.path.join(mo, "nicotine.mo")]))
+	translations.append((os.path.join(sys.prefix, os.environ.get("PKGLOCALEDIR", "share"), "locale", lang, "LC_MESSAGES"), [os.path.join(mo, "nicotine.mo")]))
 	
 if sys.platform.startswith("win"):
   try:
