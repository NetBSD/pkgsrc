$NetBSD: patch-scripts_toolchain.lua,v 1.6 2023/03/31 20:39:45 wiz Exp $

Not for upstream.
android toolchain value is not used in pkgsrc so this is good enough for now.
https://github.com/mamedev/mame/issues/11049

--- scripts/toolchain.lua.orig	2023-03-29 14:05:56.000000000 +0000
+++ scripts/toolchain.lua
@@ -60,7 +60,8 @@ function androidToolchainRoot()
 		local hostTags = {
 			windows = "windows-x86_64",
 			linux   = "linux-x86_64",
-			macosx  = "darwin-x86_64"
+			macosx  = "darwin-x86_64",
+			bsd  = "netbsd-x86_64"
 		}
 		android.toolchainRoot = (os.getenv("ANDROID_NDK_HOME") or "") .. "/toolchains/llvm/prebuilt/" .. hostTags[os.get()]
 	end
