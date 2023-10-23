$NetBSD: patch-hadrian_bootstrap_bootstrap.py,v 1.1 2023/10/23 08:06:48 pho Exp $

bootstrap.py assumes that GHC always has a threaded RTS but our bootkits
don't. It is debatable at least as to whether this should be upstreamed.

The hack to shake.cabal can be removed when [1] gets merged and GHC adopts
it in hadrian/bootstrap/*.json.

[1]: https://github.com/ndmitchell/shake/pull/836

--- hadrian/bootstrap/bootstrap.py.orig	2023-09-21 11:30:31.000000000 +0000
+++ hadrian/bootstrap/bootstrap.py
@@ -185,7 +185,27 @@ def install_dep(dep: BootstrapDep, ghc: 
 
     sdist_dir = resolve_dep(dep)
 
-    install_sdist(dist_dir, sdist_dir, ghc, dep.flags)
+    # Some packages are going to be built with threaded RTS, which is
+    # impossible in our case.
+    flags = [flag.replace("+threaded", "-threaded") for flag in dep.flags]
+
+    # "shake" is worse. It tries to build an unneeded executable with
+    # hard-coded "-thread". The only way to disable it is to modify its
+    # .cabal file here.
+    # https://github.com/ndmitchell/shake/pull/836
+    if dep.package == "shake":
+        with open(sdist_dir / f'{dep.package}.cabal', 'r') as cabal_file:
+            cabal = cabal_file.read()
+        cabal = cabal.replace("executable shake\n", "executable shake\n    buildable: False\n")
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
@@ -481,6 +501,7 @@ Alternatively, you could use `bootstrap.
           fetch_from_plan(plan, TARBALLS)
 
         bootstrap(info, ghc)
+        return # Don't waste time by creating an archive.
         hadrian_path = (BINDIR / 'hadrian').resolve()
 
         print(dedent(f'''
