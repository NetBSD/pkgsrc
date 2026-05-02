$NetBSD: patch-runtime_lua_vim_pack.lua,v 1.1 2026/05/02 21:14:04 leot Exp $

Avoid calling possible unavailable uv.available_parallelism().

At least on NetBSD with libuv-1.52.1 and lua51-luv-1.43.0.0nb1 seems
not available and it can be triggered by using vim.pack.add().

--- runtime/lua/vim/pack.lua.orig	2026-05-02 20:51:52.218912310 +0000
+++ runtime/lua/vim/pack.lua
@@ -507,7 +507,7 @@ end
 local copcall = package.loaded.jit and pcall or require('coxpcall').pcall
 
 local function async_join_run_wait(funs)
-  local n_threads = 2 * (uv.available_parallelism() or 1)
+  local n_threads = 2 * ((uv.available_parallelism and uv.available_parallelism()) or 1)
   --- @async
   local function joined_f()
     async.join(n_threads, funs)
