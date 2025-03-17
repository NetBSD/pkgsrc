$NetBSD$

--- flake.nix.orig	2025-03-17 06:46:13.327127011 +0000
+++ flake.nix
@@ -10,13 +10,9 @@
       gitignore.inputs.nixpkgs.follows = "nixpkgs";
 
       flake-utils.url = "github:numtide/flake-utils";
-
-      # llvm: fix @wasmMemory{Size,Grow} for wasm64
-      langref.url = "https://raw.githubusercontent.com/ziglang/zig/0fb2015fd3422fc1df364995f9782dfe7255eccd/doc/langref.html.in";
-      langref.flake = false;
     };
 
-  outputs = { self, nixpkgs, zig-overlay, gitignore, flake-utils, langref }:
+  outputs = { self, nixpkgs, zig-overlay, gitignore, flake-utils }:
     flake-utils.lib.eachDefaultSystem (system:
       let
         pkgs = nixpkgs.legacyPackages.${system};
@@ -34,14 +30,13 @@
           dontConfigure = true;
           dontInstall = true;
           doCheck = true;
-          langref = langref;
           buildPhase = ''
             mkdir -p .cache
             ln -s ${pkgs.callPackage ./deps.nix { zig = zig; }} .cache/p
-            zig build install --cache-dir $(pwd)/.zig-cache --global-cache-dir $(pwd)/.cache -Dversion_data_path=$langref -Dcpu=baseline -Doptimize=ReleaseSafe --prefix $out
+            zig build install --cache-dir $(pwd)/.zig-cache --global-cache-dir $(pwd)/.cache -Dcpu=baseline -Doptimize=ReleaseSafe --prefix $out
           '';
           checkPhase = ''
-            zig build test --cache-dir $(pwd)/.zig-cache --global-cache-dir $(pwd)/.cache -Dversion_data_path=$langref -Dcpu=baseline
+            zig build test --cache-dir $(pwd)/.zig-cache --global-cache-dir $(pwd)/.cache -Dcpu=baseline
           '';
         };
       }
