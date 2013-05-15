$NetBSD: patch-python_xen_xm_create.py,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- python/xen/xm/create.py.orig	2010-04-07 16:12:05.000000000 +0000
+++ python/xen/xm/create.py
@@ -426,7 +426,7 @@ gopts.var('vtpm', val="instance=INSTANCE
           preferred instance number. The hotplug script will determine
           which instance number will actually be assigned to the domain.
           The associtation between virtual machine and the TPM instance
-          number can be found in /etc/xen/vtpm.db. Use the backend in the
+          number can be found in @XENDCONFDIR@/vtpm.db. Use the backend in the
           given domain.
           The type parameter can be used to select a specific driver type
           that the VM can use. To prevent a fully virtualized domain (HVM)
