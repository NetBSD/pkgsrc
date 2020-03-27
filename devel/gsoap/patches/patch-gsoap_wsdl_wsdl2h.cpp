$NetBSD: patch-gsoap_wsdl_wsdl2h.cpp,v 1.1 2020/03/27 20:53:32 joerg Exp $

--- gsoap/wsdl/wsdl2h.cpp.orig	2020-03-27 20:14:53.062513186 +0000
+++ gsoap/wsdl/wsdl2h.cpp
@@ -115,7 +115,7 @@ const char serviceformat[]       = "//gs
 const char paraformat[]          = "    %-35s%s%s%s";
 const char anonformat[]          = "    %-35s%s_%s%s";
 
-const char copyrightnotice[] = "\n**  The gSOAP WSDL/Schema processor for C and C++, wsdl2h release "VERSION"\n**  Copyright (C) 2000-2010 Robert van Engelen, Genivia Inc.\n**  All Rights Reserved. This product is provided \"as is\", without any warranty.\n**  The wsdl2h tool is released under one of the following two licenses:\n**  GPL or the commercial license by Genivia Inc. Use option -l for more info.\n\n";
+const char copyrightnotice[] = "\n**  The gSOAP WSDL/Schema processor for C and C++, wsdl2h release " VERSION "\n**  Copyright (C) 2000-2010 Robert van Engelen, Genivia Inc.\n**  All Rights Reserved. This product is provided \"as is\", without any warranty.\n**  The wsdl2h tool is released under one of the following two licenses:\n**  GPL or the commercial license by Genivia Inc. Use option -l for more info.\n\n";
 
 const char licensenotice[]   = "\
 --------------------------------------------------------------------------------\n\
