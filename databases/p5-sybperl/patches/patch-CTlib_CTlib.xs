$NetBSD: patch-CTlib_CTlib.xs,v 1.1 2017/09/27 19:51:03 wiz Exp $

--- CTlib/CTlib.xs.orig	2010-03-28 11:27:37.000000000 +0000
+++ CTlib/CTlib.xs
@@ -654,8 +654,10 @@ static void * alloc_datatype(CS_INT data
 		case CS_BIGINT_TYPE:
 		case CS_UBIGINT_TYPE: bytes = sizeof(CS_BIGINT); break;
 #endif
-#if defined(CS_BIGTIME_TYPE)
-		case CS_BIGTIME_TYPE:
+#if defined(CS_BIGTIME_TYPE) && defined(CS_BIGDATETIME)
+		case CS_BIGTIME_TYPE: bytes = sizeof(CS_BIGDATETIME); break;
+#endif
+#if defined(CS_BIGDATETIME_TYPE) && defined(CS_BIGDATETIME)
 		case CS_BIGDATETIME_TYPE: bytes = sizeof(CS_BIGDATETIME); break;
 #endif
 	default:
