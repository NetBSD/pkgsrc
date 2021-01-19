$NetBSD: patch-src_wallet_walletutil.cpp,v 1.2 2021/01/19 10:17:00 adam Exp $

--- src/wallet/walletutil.cpp.orig	2021-01-13 21:52:34.000000000 +0000
+++ src/wallet/walletutil.cpp
@@ -58,7 +58,7 @@ std::vector<fs::path> ListWalletDir()
                 (ExistsBerkeleyDatabase(it->path()) || ExistsSQLiteDatabase(it->path()))) {
                 // Found a directory which contains wallet.dat btree file, add it as a wallet.
                 paths.emplace_back(path);
-            } else if (it.level() == 0 && it->symlink_status().type() == fs::regular_file && ExistsBerkeleyDatabase(it->path())) {
+            } else if (it.depth() == 0 && it->symlink_status().type() == fs::regular_file && ExistsBerkeleyDatabase(it->path())) {
                 if (it->path().filename() == "wallet.dat") {
                     // Found top-level wallet.dat btree file, add top level directory ""
                     // as a wallet.
