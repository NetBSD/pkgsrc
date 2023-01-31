$NetBSD: patch-vendor_sabre_dav_lib_CardDAV_Xml_Request_AddressBookMultiGetReport.php,v 1.1 2023/01/31 07:38:20 wiz Exp $

Fix deprecation with php 8.2.
https://github.com/sabre-io/dav/pull/1446

--- vendor/sabre/dav/lib/CardDAV/Xml/Request/AddressBookMultiGetReport.php.orig	2022-01-20 13:59:29.000000000 +0000
+++ vendor/sabre/dav/lib/CardDAV/Xml/Request/AddressBookMultiGetReport.php
@@ -38,7 +38,7 @@ class AddressBookMultiGetReport implemen
     public $hrefs;
 
     /**
-     * The mimetype of the content that should be returend. Usually
+     * The mimetype of the content that should be returned. Usually
      * text/vcard.
      *
      * @var string
@@ -54,6 +54,13 @@ class AddressBookMultiGetReport implemen
     public $version = null;
 
     /**
+     * An array with requested vcard properties.
+     *
+     * @var array
+     */
+    public $addressDataProperties;
+
+    /**
      * The deserialize method is called during xml parsing.
      *
      * This method is called statically, this is because in theory this method
