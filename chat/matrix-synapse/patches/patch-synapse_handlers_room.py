$NetBSD: patch-synapse_handlers_room.py,v 1.3 2022/10/29 00:56:40 gdt Exp $

This patch allows changing the default power level for the creator of a new
room. It's useful to set this higher than 100 so that the creator of the room
can give admin to others while still retaining the ability to revoke admin from
someone. In the past, this turned out to be the only thing that could recover a
room in which a bridge with admin permissions went wild and kicked everybody.

--- synapse/handlers/room.py.orig	2022-10-17 10:31:15.000000000 +0000
+++ synapse/handlers/room.py
@@ -1170,7 +1170,7 @@ class RoomCreationHandler:
             await send(power_event, power_context, creator)
         else:
             power_level_content: JsonDict = {
-                "users": {creator_id: 100},
+                "users": {creator_id: @SYNAPSE_DEFAULT_CREATOR_PL@},
                 "users_default": 0,
                 "events": {
                     EventTypes.Name: 50,
