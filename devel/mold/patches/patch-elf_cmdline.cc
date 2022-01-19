$NetBSD: patch-elf_cmdline.cc,v 1.1 2022/01/19 02:52:24 pho Exp $

Ignore -dc and -dp for now. The base GCC for NetBSD 9 passes them to linker but
mold currently doesn't support them.

PR sent to the upstream:
https://github.com/rui314/mold/pull/278

--- elf/cmdline.cc.orig	2022-01-18 17:54:53.408218316 +0000
+++ elf/cmdline.cc
@@ -60,10 +60,12 @@ Options:
   --color-diagnostics         Alias for --color-diagnostics=always
   --compress-debug-sections [none,zlib,zlib-gabi,zlib-gnu]
                               Compress .debug_* sections
+  --dc                        Ignored
   --defsym=SYMBOL=VALUE       Define a symbol alias
   --demangle                  Demangle C++ symbols in log messages (default)
     --no-demangle
   --disable-new-dtags         Ignored
+  --dp                        Ignored
   --dynamic-list              Read a list of dynamic symbols
   --eh-frame-hdr              Create .eh_frame_hdr section
     --no-eh-frame-hdr
@@ -796,6 +798,8 @@ void parse_nonpositional_args(Context<E>
     } else if (read_flag(args, "no-undefined-version")) {
     } else if (read_arg(ctx, args, arg, "sort-section")) {
     } else if (read_flag(args, "sort-common")) {
+    } else if (read_flag(args, "dc")) {
+    } else if (read_flag(args, "dp")) {
     } else if (read_flag(args, "fix-cortex-a53-843419")) {
     } else if (read_flag(args, "EL")) {
     } else if (read_flag(args, "warn-once")) {
