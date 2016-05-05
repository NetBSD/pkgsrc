$NetBSD: patch-src_netstring_netasn1.ml,v 1.1 2016/05/05 16:04:21 jaapb Exp $

Temporary patch for ocaml 4.03 (from package's git repository)
--- src/netstring/netasn1.ml.orig	2016-02-29 12:24:17.000000000 +0000
+++ src/netstring/netasn1.ml
@@ -437,7 +437,7 @@ module Value = struct
                let hour = int_of_string (Netstring_str.matched_group m 4 s) in
                let minute = int_of_string (Netstring_str.matched_group m 5 s) in
                let second = int_of_string (Netstring_str.matched_group m 6 s) in
-               let zonestr = Netstring_str.matched_group m 8s in
+               let zonestr = Netstring_str.matched_group m 8 s in
                let zone = get_zone zonestr in
                if month = 0 || month > 12 || day = 0 || day > 31 ||
                     hour > 23 || minute > 59 || second > 59 
