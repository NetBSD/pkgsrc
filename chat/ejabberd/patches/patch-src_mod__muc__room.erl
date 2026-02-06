$NetBSD: patch-src_mod__muc__room.erl,v 1.1 2026/02/06 17:02:06 gdt Exp $

Sync one function with git master, pulling up what I think is several
bugfixes.

--- src/mod_muc_room.erl.orig	2025-10-28 12:56:01.000000000 +0000
+++ src/mod_muc_room.erl
@@ -5370,13 +5370,17 @@ add_presence_hats(JID, Pres, StateData) 
                     Pres;
                 _ ->
                     Items =
-                        lists:map(fun(URI) ->
-                                     {URI, Title, Hue} = get_hat_details(URI, StateData),
-                                     #muc_hat{uri = URI,
-                                              title = Title,
-                                              hue = Hue}
-                                  end,
-                                  UserHats),
+                        lists:filtermap(fun(URI) ->
+                                           case get_hat_details(URI, StateData) of
+                                               false ->
+                                                   false;
+                                               {URI, Title, Hue} ->
+                                                   {true,
+                                                    #muc_hat{uri = URI,
+                                                             title = Title}}
+                                           end
+                                        end,
+                                        UserHats),
                     xmpp:set_subtag(Pres, #muc_hats{hats = Items})
             end;
         false ->
