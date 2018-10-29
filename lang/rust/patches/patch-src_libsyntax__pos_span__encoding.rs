$NetBSD: patch-src_libsyntax__pos_span__encoding.rs,v 1.1 2018/10/29 22:24:11 he Exp $

Workaround for compiler bug hitting sparc64 causing unaligned accesses.

--- src/libsyntax_pos/span_encoding.rs.orig	2018-10-24 20:00:01.000000000 +0000
+++ src/libsyntax_pos/span_encoding.rs
@@ -26,7 +26,9 @@ use std::hash::{Hash, Hasher};
 /// The primary goal of `Span` is to be as small as possible and fit into other structures
 /// (that's why it uses `packed` as well). Decoding speed is the second priority.
 /// See `SpanData` for the info on span fields in decoded representation.
-#[repr(packed)]
+
+/// Workaround for compiler bug: https://github.com/rust-lang/rust/issues/53181
+#[cfg_attr(not(any(target_arch = "sparc64", target_arch = "sparcv9")), repr(packed))]
 pub struct Span(u32);
 
 impl Copy for Span {}
