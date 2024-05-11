$NetBSD: patch-hadrian_bootstrap_bootstrap.py,v 1.3 2024/05/11 14:55:51 pho Exp $

Hunk #0, #1:
    bootstrap.py assumes that GHC always has a threaded RTS but our
    bootkits don't. It is debatable at least as to whether this should be
    upstreamed.

    We also need to patch some packages to bootstrap hadrian. Those patch
    files are in ${FILESDIR}.

Hunk #1-#7:
    Support --jobs=N for parallel compilation. This makes bootstrapping
    hadrian a lot faster.
    https://gitlab.haskell.org/ghc/ghc/-/merge_requests/12610

--- hadrian/bootstrap/bootstrap.py.orig	2024-02-22 20:59:45.000000000 +0000
+++ hadrian/bootstrap/bootstrap.py
@@ -25,6 +25,7 @@ import sys
 from textwrap import dedent
 from typing import Optional, Dict, List, Tuple, \
                    NewType, BinaryIO, NamedTuple
+import os
 
 #logging.basicConfig(level=logging.INFO)
 
@@ -180,24 +181,42 @@ def resolve_dep(dep : BootstrapDep) -> P
     return sdist_dir
 
 
-def install_dep(dep: BootstrapDep, ghc: Compiler) -> None:
+def install_dep(dep: BootstrapDep, ghc: Compiler, jobs: int) -> None:
     dist_dir = (DISTDIR / f'{dep.package}-{dep.version}').resolve()
 
     sdist_dir = resolve_dep(dep)
 
-    install_sdist(dist_dir, sdist_dir, ghc, dep.flags)
+    # Some packages are going to be built with threaded RTS, which is
+    # impossible in our case.
+    flags = [flag.replace("+threaded", "-threaded") for flag in dep.flags]
+
+    # pkgsrc has local patches that need to be applied for bootstrapping
+    # hadrian.
+    patch_path = Path(os.environ['FILESDIR']) / f'hadrian-{dep.package}.patch'
+    if patch_path.is_file():
+        with open(patch_path) as patch_file:
+            patch = patch_file.read()
+        subprocess_run(
+            ['patch', '-p1', '-b'], cwd=sdist_dir, input=patch, check=True, encoding='UTF-8')
+
+    # If it's from Hackage and we've already installed it, don't do it
+    # twice. That only wastes time.
+    stamp = sdist_dir / 'bootstrap-done'
+    if dep.source == PackageSource.LOCAL or not stamp.exists():
+        install_sdist(dist_dir, sdist_dir, ghc, flags, jobs)
+        stamp.touch()
 
-def install_sdist(dist_dir: Path, sdist_dir: Path, ghc: Compiler, flags: List[str]):
+def install_sdist(dist_dir: Path, sdist_dir: Path, ghc: Compiler, flags: List[str], jobs: int):
     prefix = PSEUDOSTORE.resolve()
     flags_option = ' '.join(flags)
     setup_dist_dir = dist_dir / 'setup'
     setup = setup_dist_dir / 'Setup'
 
-    build_args = [
+    common_args = [
         f'--builddir={dist_dir}',
     ]
 
-    configure_args = build_args + [
+    configure_args = common_args + [
         f'--package-db={PKG_DB.resolve()}',
         f'--prefix={prefix}',
         f'--bindir={BINDIR.resolve()}',
@@ -207,6 +226,12 @@ def install_sdist(dist_dir: Path, sdist_
         f'--flags={flags_option}',
     ]
 
+    build_args = common_args + [
+        f'--jobs={jobs}',
+    ]
+
+    install_args = common_args
+
     def check_call(args: List[str]) -> None:
         subprocess_run(args, cwd=sdist_dir, check=True)
 
@@ -223,7 +248,7 @@ def install_sdist(dist_dir: Path, sdist_
     check_call([str(ghc.ghc_path), '--make', '-package-env=-', '-i', f'-odir={setup_dist_dir}', f'-hidir={setup_dist_dir}', '-o', setup, 'Setup'])
     check_call([setup, 'configure'] + configure_args)
     check_call([setup, 'build'] + build_args)
-    check_call([setup, 'install'] + build_args)
+    check_call([setup, 'install'] + install_args)
 
 def hash_file(h, f: BinaryIO) -> SHA256Hash:
     while True:
@@ -238,7 +263,7 @@ def hash_file(h, f: BinaryIO) -> SHA256H
 UnitId = NewType('UnitId', str)
 PlanUnit = NewType('PlanUnit', dict)
 
-def bootstrap(info: BootstrapInfo, ghc: Compiler) -> None:
+def bootstrap(info: BootstrapInfo, ghc: Compiler, jobs: int) -> None:
     if not PKG_DB.exists():
         print(f'Creating package database {PKG_DB}')
         PKG_DB.parent.mkdir(parents=True, exist_ok=True)
@@ -248,7 +273,7 @@ def bootstrap(info: BootstrapInfo, ghc: 
         check_builtin(dep, ghc)
 
     for dep in info.dependencies:
-        install_dep(dep, ghc)
+        install_dep(dep, ghc, jobs)
 
 # Steps
 #######################################################################
@@ -374,6 +399,8 @@ def main() -> None:
                        help='produce a Hadrian distribution archive (default)')
     parser.add_argument('--no-archive', dest='want_archive', action='store_false',
                        help='do not produce a Hadrian distribution archive')
+    parser.add_argument('-j', '--jobs', type=int,
+                        help='the number of jobs to run simultaneously')
     parser.set_defaults(want_archive=True)
 
     subparsers = parser.add_subparsers(dest="command")
@@ -480,7 +507,8 @@ Alternatively, you could use `bootstrap.
           plan = gen_fetch_plan(info)
           fetch_from_plan(plan, TARBALLS)
 
-        bootstrap(info, ghc)
+        bootstrap(info, ghc, args.jobs)
+        return # Don't waste time by creating an archive.
         hadrian_path = (BINDIR / 'hadrian').resolve()
 
         print(dedent(f'''
