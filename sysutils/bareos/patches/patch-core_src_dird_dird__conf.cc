$NetBSD: patch-core_src_dird_dird__conf.cc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	add dumping of Honor No Dump Flag

--- core/src/dird/dird_conf.cc.orig	2021-01-22 16:02:33.229527262 +0000
+++ core/src/dird/dird_conf.cc
@@ -1981,6 +1981,9 @@ void FilesetResource::PrintConfigInclude
       case 'M': /* MD5 */
         send.KeyQuotedString("Signature", "MD5");
         break;
+      case 'N': /* honor nodump flag */
+        send.KeyBool("HonornoDumpFlag", true);
+        break;
       case 'n':
         send.KeyQuotedString("Replace", "Never");
         break;
