$NetBSD: patch-hadrian_bootstrap_bootstrap.py,v 1.2 2023/01/21 18:24:42 pho Exp $

bootstrap.py assumes that GHC always has a threaded RTS but our bootkits
don't. It is debatable at least as to whether this should be upstreamed.

At least the hack to shake.cabal can be removed when [1] gets merged and
GHC adopts it in hadrian/bootstrap/*.json.

[1]: https://github.com/ndmitchell/shake/pull/836

--- hadrian/bootstrap/bootstrap.py.orig	2022-12-23 16:19:02.000000000 +0000
+++ hadrian/bootstrap/bootstrap.py
@@ -180,7 +180,44 @@ def install_dep(dep: BootstrapDep, ghc: 
 
     sdist_dir = resolve_dep(dep)
 
-    install_sdist(dist_dir, sdist_dir, ghc, dep.flags)
+    # Some packages are going to be built with threaded RTS, which is
+    # impossible in our case.
+    flags = [flag.replace("+threaded", "-threaded") for flag in dep.flags]
+
+    # "shake" is worse. It tries to build an unneeded executable with
+    # hard-coded "-thread". The only way to disable it is to modify its
+    # .cabal file here.
+    if dep.package == "shake":
+        with open(sdist_dir / f'{dep.package}.cabal', 'r') as cabal_file:
+            cabal = cabal_file.read()
+        cabal = cabal.replace("executable shake\n", "executable shake\n    buildable: False\n")
+        with open(sdist_dir / f'{dep.package}.cabal', 'w') as cabal_file:
+            cabal_file.write(cabal)
+
+    # This is a temporary workaround for aarch64 codegen bug in 9.2.1. Once
+    # we update our bootkit for aarch64 we can remove
+    # this. https://gitlab.haskell.org/ghc/ghc/-/issues/20594
+    if dep.package == "QuickCheck":
+        with open(sdist_dir / f'{dep.package}.cabal', 'r') as cabal_file:
+            cabal = cabal_file.read()
+        cabal = cabal.replace("ö", "o")
+        with open(sdist_dir / f'{dep.package}.cabal', 'w') as cabal_file:
+            cabal_file.write(cabal)
+
+    # Same as above
+    if dep.package == "clock":
+        with open(sdist_dir / f'{dep.package}.cabal', 'r') as cabal_file:
+            cabal = cabal_file.read()
+        cabal = cabal.replace("©", "(c)")
+        with open(sdist_dir / f'{dep.package}.cabal', 'w') as cabal_file:
+            cabal_file.write(cabal)
+
+    # If it's from Hackage and we've already installed it, don't do it
+    # twice. That only wastes time.
+    stamp = sdist_dir / 'bootstrap-done'
+    if dep.source == PackageSource.LOCAL or not stamp.exists():
+        install_sdist(dist_dir, sdist_dir, ghc, flags)
+        stamp.touch()
 
 def install_sdist(dist_dir: Path, sdist_dir: Path, ghc: Compiler, flags: List[str]):
     prefix = PSEUDOSTORE.resolve()
@@ -459,6 +496,7 @@ Alternatively, you could use `bootstrap.
           fetch_from_plan(plan, TARBALLS)
 
         bootstrap(info, ghc)
+        return # Don't waste time by creating an archive.
         hadrian_path = (BINDIR / 'hadrian').resolve()
 
         archive = make_archive(hadrian_path)
