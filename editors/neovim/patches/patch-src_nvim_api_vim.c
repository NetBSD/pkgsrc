$NetBSD: patch-src_nvim_api_vim.c,v 1.1 2024/08/17 15:43:33 bsiegert Exp $

- avoid conflict with NetBSD's popcount(3)

--- src/nvim/api/vim.c.orig	2024-05-27 21:57:03.208807367 +0000
+++ src/nvim/api/vim.c
@@ -2384,8 +2384,8 @@ void nvim__redraw(Dict(redraw) *opts, Er
     }
   }

-  int count = (win != NULL) + (buf != NULL);
-  VALIDATE(popcount(opts->is_set__redraw_) > count, "%s", "at least one action required", {
+  unsigned count = (win != NULL) + (buf != NULL);
+  VALIDATE(xpopcount(opts->is_set__redraw_) > count, "%s", "at least one action required", {
     return;
   });

