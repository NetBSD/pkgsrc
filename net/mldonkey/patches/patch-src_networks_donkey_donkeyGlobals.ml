$NetBSD: patch-src_networks_donkey_donkeyGlobals.ml,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/networks/donkey/donkeyGlobals.ml.orig	2011-10-25 17:33:21.000000000 +0000
+++ src/networks/donkey/donkeyGlobals.ml
@@ -781,7 +781,6 @@ let set_client_name c name md4 =
       c.client_md4 <- md4;
     end
 
-exception ClientFound of client
 let find_client_by_name name =
   try
     H.iter (fun c ->
