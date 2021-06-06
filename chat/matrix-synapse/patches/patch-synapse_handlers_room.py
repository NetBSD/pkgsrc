$NetBSD: patch-synapse_handlers_room.py,v 1.1 2021/06/06 09:40:34 js Exp $

This patch allows changing the default power level for the creator of a new
room. It's useful to set this higher than 100 so that the creator of the room
can give admin to others while still retaining the ability to revoke admin from
someone. In the past, this turned out to be the only thing that could recover a
room in which a bridge with admin permissions went wild and kicked everybody.

--- synapse/handlers/room.py.orig	2021-06-03 12:24:19.000000000 +0000
+++ synapse/handlers/room.py
@@ -936,7 +936,7 @@ class RoomCreationHandler(BaseHandler):
             )
         else:
             power_level_content = {
-                "users": {creator_id: 100},
+                "users": {creator_id: @SYNAPSE_DEFAULT_CREATOR_PL@},
                 "users_default": 0,
                 "events": {
                     EventTypes.Name: 50,
