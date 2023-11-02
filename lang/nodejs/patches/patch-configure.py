$NetBSD: patch-configure.py,v 1.3 2023/11/02 13:18:41 adam Exp $

Use packaging instead of deprecated distutils.

--- configure.py.orig	2023-11-02 12:01:17.555637132 +0000
+++ configure.py
@@ -14,7 +14,7 @@ import bz2
 import io
 from pathlib import Path
 
-from distutils.version import StrictVersion
+from packaging.version import Version
 
 # If not run from node/, cd to node/.
 os.chdir(Path(__file__).parent)
@@ -1565,10 +1565,10 @@ def configure_openssl(o):
     # supported asm compiler for AVX2. See https://github.com/openssl/openssl/
     # blob/OpenSSL_1_1_0-stable/crypto/modes/asm/aesni-gcm-x86_64.pl#L52-L69
     openssl110_asm_supported = \
-      ('gas_version' in variables and StrictVersion(variables['gas_version']) >= StrictVersion('2.23')) or \
-      ('xcode_version' in variables and StrictVersion(variables['xcode_version']) >= StrictVersion('5.0')) or \
-      ('llvm_version' in variables and StrictVersion(variables['llvm_version']) >= StrictVersion('3.3')) or \
-      ('nasm_version' in variables and StrictVersion(variables['nasm_version']) >= StrictVersion('2.10'))
+      ('gas_version' in variables and Version(variables['gas_version']) >= Version('2.23')) or \
+      ('xcode_version' in variables and Version(variables['xcode_version']) >= Version('5.0')) or \
+      ('llvm_version' in variables and Version(variables['llvm_version']) >= Version('3.3')) or \
+      ('nasm_version' in variables and Version(variables['nasm_version']) >= Version('2.10'))
 
     if is_x86 and not openssl110_asm_supported:
       error('''Did not find a new enough assembler, install one or build with
