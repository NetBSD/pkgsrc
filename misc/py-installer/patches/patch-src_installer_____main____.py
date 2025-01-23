$NetBSD: patch-src_installer_____main____.py,v 1.1 2025/01/23 19:31:09 riastradh Exp $

Add `--executable' option.
https://github.com/pypa/installer/issues/257
https://github.com/pypa/installer/pull/258

--- src/installer/__main__.py.orig	2022-12-07 02:28:06.839389000 +0000
+++ src/installer/__main__.py
@@ -31,6 +31,13 @@ def _get_main_parser() -> argparse.Argum
         help="override prefix to install packages to",
     )
     parser.add_argument(
+        "--executable",
+        metavar="path",
+        default=sys.executable,
+        type=str,
+        help="#! executable to install scripts with (default=sys.executable)",
+    )
+    parser.add_argument(
         "--compile-bytecode",
         action="append",
         metavar="level",
@@ -86,7 +93,7 @@ def _main(cli_args: Sequence[str], progr
     with WheelFile.open(args.wheel) as source:
         destination = SchemeDictionaryDestination(
             scheme_dict=_get_scheme_dict(source.distribution, prefix=args.prefix),
-            interpreter=sys.executable,
+            interpreter=args.executable,
             script_kind=get_launcher_kind(),
             bytecode_optimization_levels=bytecode_levels,
             destdir=args.destdir,
