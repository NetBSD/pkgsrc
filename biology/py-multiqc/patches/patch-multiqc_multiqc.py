$NetBSD: patch-multiqc_multiqc.py,v 1.2 2024/11/22 21:41:43 bacon Exp $

# Validate env at run time

--- multiqc/multiqc.py.orig	2024-11-20 15:21:45.000000000 +0000
+++ multiqc/multiqc.py
@@ -12,7 +12,13 @@ import time
 import traceback
 from typing import Optional, Tuple
 
-import rich_click as click
+if 'LC_ALL' in os.environ and 'LANG' in os.environ:
+    import rich_click as click
+else:
+    print('multiqc: LC_ALL and LANG must be set to a UTF-8 character set')
+    print('in your environment in order for the click module to function.')
+    print('E.g. export LC_ALL=en_US.UTF-8 or setenv LC_ALL en_US.UTF-8')
+    sys.exit()
 
 from multiqc import config, report, validation
 from multiqc.core import log_and_rich, plugin_hooks
