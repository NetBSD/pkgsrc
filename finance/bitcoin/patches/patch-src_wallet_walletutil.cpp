$NetBSD: patch-src_wallet_walletutil.cpp,v 1.1 2020/03/29 01:00:01 joerg Exp $

--- src/wallet/walletutil.cpp.orig	2020-03-28 23:09:25.601811010 +0000
+++ src/wallet/walletutil.cpp
@@ -74,7 +74,7 @@ std::vector<fs::path> ListWalletDir()
         if (it->status().type() == fs::directory_file && IsBerkeleyBtree(it->path() / "wallet.dat")) {
             // Found a directory which contains wallet.dat btree file, add it as a wallet.
             paths.emplace_back(path);
-        } else if (it.level() == 0 && it->symlink_status().type() == fs::regular_file && IsBerkeleyBtree(it->path())) {
+        } else if (it.depth() == 0 && it->symlink_status().type() == fs::regular_file && IsBerkeleyBtree(it->path())) {
             if (it->path().filename() == "wallet.dat") {
                 // Found top-level wallet.dat btree file, add top level directory ""
                 // as a wallet.
