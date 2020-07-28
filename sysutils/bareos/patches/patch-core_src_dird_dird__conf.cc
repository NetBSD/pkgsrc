$NetBSD: patch-core_src_dird_dird__conf.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Add dumping of Honor No Dump Flag

--- core/src/dird/dird_conf.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/dird_conf.cc
@@ -2006,6 +2006,9 @@ bool FilesetResource::PrintConfig(PoolMe
           case 'M': /* MD5 */
             IndentConfigItem(cfg_str, 3, "Signature = MD5\n");
             break;
+          case 'N': /* Honor No Dump Flag  */
+            IndentConfigItem(cfg_str, 3, "Honor No Dump Flag = Yes\n");
+            break;
           case 'n':
             IndentConfigItem(cfg_str, 3, "Replace = Never\n");
             break;
