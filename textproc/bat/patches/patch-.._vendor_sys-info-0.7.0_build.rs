$NetBSD: patch-.._vendor_sys-info-0.7.0_build.rs,v 1.1 2021/03/11 19:25:04 fox Exp $

Adds NetBSD support for sys-info crate.

This patch has been upstreamed. And will be removed once it is merged.

Upstream PR: https://github.com/FillZpp/sys-info-rs/pull/91

--- ../vendor/sys-info-0.7.0/build.rs.orig	2021-03-10 06:17:23.462005386 +0000
+++ ../vendor/sys-info-0.7.0/build.rs
@@ -22,6 +22,10 @@ fn main() {
             println!("cargo:rustc-flags=-l pthread");
             builder.file("c/freebsd.c")
         },
+	"netbsd" => {
+            println!("cargo:rustc-flags=-l pthread");
+            builder.file("c/netbsd.c")
+        },
         _ => panic!("unsupported system: {}", target_os)
     };
     builder.compile("info");
