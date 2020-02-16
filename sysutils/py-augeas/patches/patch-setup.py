$NetBSD: patch-setup.py,v 1.1 2020/02/16 20:21:55 adam Exp $

Do not install tests.

--- setup.py.orig	2020-02-16 20:11:31.000000000 +0000
+++ setup.py
@@ -18,7 +18,7 @@ setup(name=name,
       author="Harald Hoyer",
       author_email="augeas-devel@redhat.com",
       description="""Python bindings for Augeas""",
-      packages=find_packages(exclude=('test')),
+      packages=find_packages(exclude=('test',)),
       setup_requires=["cffi>=1.0.0"],
       cffi_modules=["augeas/ffi.py:ffi"],
       install_requires=["cffi>=1.0.0"],
