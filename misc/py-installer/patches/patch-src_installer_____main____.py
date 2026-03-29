$NetBSD: patch-src_installer_____main____.py,v 1.2 2026/03/29 17:21:35 wiz Exp $

Add `--executable' option.
https://github.com/pypa/installer/issues/257
https://github.com/pypa/installer/pull/258

applied and then reverted:
https://github.com/pypa/installer/pull/263

see some discussion in
https://github.com/pypa/installer/issues/107

--- src/installer/__main__.py.orig	2026-03-28 15:38:56.048486000 +0000
+++ src/installer/__main__.py
@@ -31,6 +31,13 @@ def _get_main_parser() -> argparse.ArgumentParser:
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
@@ -102,7 +109,7 @@ def _main(cli_args: Sequence[str], program: str | None
                 source.validate_record(validate_contents=args.validate_record == "all")
             destination = SchemeDictionaryDestination(
                 scheme_dict=_get_scheme_dict(source.distribution, prefix=args.prefix),
-                interpreter=sys.executable,
+                interpreter=args.executable,
                 script_kind=get_launcher_kind(),
                 bytecode_optimization_levels=bytecode_levels,
                 destdir=args.destdir,
