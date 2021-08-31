$NetBSD: patch-synapse_handlers_room.py,v 1.2 2021/08/31 19:57:59 js Exp $

This patch allows changing the default power level for the creator of a new
room. It's useful to set this higher than 100 so that the creator of the room
can give admin to others while still retaining the ability to revoke admin from
someone. In the past, this turned out to be the only thing that could recover a
room in which a bridge with admin permissions went wild and kicked everybody.

--- synapse/handlers/room.py.orig	2021-08-31 12:43:28.000000000 +0000
+++ synapse/handlers/room.py
@@ -933,7 +933,7 @@ class RoomCreationHandler(BaseHandler):
             )
         else:
             power_level_content: JsonDict = {
-                "users": {creator_id: 100},
+                "users": {creator_id: @SYNAPSE_DEFAULT_CREATOR_PL@},
                 "users_default": 0,
                 "events": {
                     EventTypes.Name: 50,
