$NetBSD: patch-protobufgen.sh,v 1.1 2020/01/20 17:25:10 adam Exp $

Portability fix.

--- protobufgen.sh.orig	2020-01-17 21:22:08.000000000 +0000
+++ protobufgen.sh
@@ -42,8 +42,8 @@ if [ "x$PROTOC_LEGACY" = "xyes" ]; then
 	sed -i 's/PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC/PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC/g' packets.pb-c.c
 	sed -i 's/PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC/PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC/g' packets.pb-c.c
 else
-	sed -i 's/<protobuf-c\/protobuf-c.h>/"protobuf.h"/g' packets.pb-c.h
+	sed 's/<protobuf-c\/protobuf-c.h>/"protobuf.h"/g' packets.pb-c.h > include/packets.pb-c.h
 fi
 
-mv packets.pb-c.h include
+rm packets.pb-c.h
 mv packets.pb-c.c src
