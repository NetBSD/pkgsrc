$NetBSD: patch-spectrumctl_spectrum_env.py,v 1.1.1.1 2011/02/07 06:31:22 schnoebe Exp $

#
# allow the spectrum user to be substituted in.
#

--- spectrumctl/spectrum/env.py.orig	2010-07-13 17:38:39.000000000 +0000
+++ spectrumctl/spectrum/env.py
@@ -18,7 +18,7 @@ def get_uid():
 		username = os.environ['SPECTRUM_USER']
 	except KeyError:
 		# otherwise we default to spectrum:
-		username = 'spectrum'
+		username = '@SPECTRUM_USER@'
 	try:
 		return pwd.getpwnam( username ).pw_uid
 	except KeyError:
