$NetBSD: patch-synapse_handlers_room.py,v 1.5 2024/08/11 15:01:32 js Exp $

This patch allows changing the default power level for the creator of a new
room. It's useful to set this higher than 100 so that the creator of the room
can give admin to others while still retaining the ability to revoke admin from
someone. In the past, this turned out to be the only thing that could recover a
room in which a bridge with admin permissions went wild and kicked everybody.

--- synapse/handlers/room.py.orig	2024-07-30 16:24:09.000000000 +0000
+++ synapse/handlers/room.py
@@ -1191,7 +1191,7 @@ class RoomCreationHandler:
             # Please update the docs for `default_power_level_content_override` when
             # updating the `events` dict below
             power_level_content: JsonDict = {
-                "users": {creator_id: 100},
+                "users": {creator_id: @SYNAPSE_DEFAULT_CREATOR_PL@},
                 "users_default": 0,
                 "events": {
                     EventTypes.Name: 50,
