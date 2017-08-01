$NetBSD: patch-lib_xmltok__impl.c,v 1.1 2017/08/01 10:41:45 nros Exp $
* fix CVE-2009-3720
http://expat.cvs.sourceforge.net/viewvc/expat/expat/lib/xmltok_impl.c?r1=1.13&r2=1.15&view=patch
--- lib/xmltok_impl.c.orig	2017-08-01 09:42:50.000000000 +0000
+++ lib/xmltok_impl.c
@@ -1898,7 +1898,7 @@ static void PREFIX (updatePosition) (con
 				     const char *ptr,
 				     const char *end, POSITION * pos)
 {
-	while (ptr != end)
+	while (ptr < end)
 	{
 		switch (BYTE_TYPE (enc, ptr))
 		{
