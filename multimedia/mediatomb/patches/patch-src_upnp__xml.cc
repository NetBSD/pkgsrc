$NetBSD: patch-src_upnp__xml.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

Add SONY Bravia support
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/upnp_xml.cc.orig	2010-03-25 14:58:11.000000000 +0000
+++ src/upnp_xml.cc
@@ -210,6 +210,21 @@ Ref<Element> UpnpXML_RenderDeviceDescrip
     root->appendElementChild(specVersion);
 
     Ref<Element> device(new Element(_("device")));
+
+    Ref<Element> dlnaspec(new Element(_("dlna:X_DLNADOC")));
+    dlnaspec->setAttribute(_("xmlns:dlna"), _("urn:schemas-dlna-org:device-1-0"));
+    dlnaspec->setText(_("DMS-1.50"));
+    device->appendElementChild(dlnaspec);
+
+    Ref<Element> dlnaspec2(new Element(_("dlna:X_DLNADOC")));
+    dlnaspec2->setAttribute(_("xmlns:dlna"), _("urn:schemas-dlna-org:device-1-0"));
+    dlnaspec2->setText(_("M-DMS-1.50"));
+    device->appendElementChild(dlnaspec2);
+
+    Ref<Element> dlnaspec3(new Element(_("dlna:X_DLNACAP")));
+    dlnaspec3->setAttribute(_("xmlns:dlna"), _("urn:schemas-dlna-org:device-1-0"));
+    dlnaspec3->setText(_("av-upload,image-upload,audio-upload"));
+    device->appendElementChild(dlnaspec3);
     
 #ifdef EXTEND_PROTOCOLINFO 
     if (config->getBoolOption(CFG_SERVER_EXTEND_PROTOCOLINFO))
