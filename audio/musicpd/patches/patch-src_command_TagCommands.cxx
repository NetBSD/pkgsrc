$NetBSD: patch-src_command_TagCommands.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10. Remove after 0.23.13.

--- src/command/TagCommands.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/command/TagCommands.cxx
@@ -36,7 +36,7 @@ handle_addtagid(Client &client, Request 
 	const TagType tag_type = tag_name_parse_i(tag_name);
 	if (tag_type == TAG_NUM_OF_ITEM_TYPES) {
 		r.FmtError(ACK_ERROR_ARG, FMT_STRING("Unknown tag type: {}"),
-			   tag_name);
+			   std::string(tag_name));
 		return CommandResult::ERROR;
 	}
 
@@ -58,7 +58,7 @@ handle_cleartagid(Client &client, Reques
 		if (tag_type == TAG_NUM_OF_ITEM_TYPES) {
 			r.FmtError(ACK_ERROR_ARG,
 				   FMT_STRING("Unknown tag type: {}"),
-				   tag_name);
+				   std::string(tag_name));
 			return CommandResult::ERROR;
 		}
 	}
