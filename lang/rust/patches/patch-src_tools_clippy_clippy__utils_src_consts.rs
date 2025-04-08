$NetBSD: patch-src_tools_clippy_clippy__utils_src_consts.rs,v 1.1 2025/04/08 09:31:07 wiz Exp $

Following on from https://github.com/rust-lang/rust/issues/137630
apply patch gracefully supplied in
https://github.com/beetrees/rust/commit/21f8bda79b2904c827b9d8d769a1307acfd855a1.patch

Fixes cross-build for 32-bit mips on NetBSD which
does not (yet?) support the f16 data type.

--- src/tools/clippy/clippy_utils/src/consts.rs.orig	2025-02-17 18:17:27.000000000 +0000
+++ src/tools/clippy/clippy_utils/src/consts.rs
@@ -41,14 +41,16 @@ pub enum Constant<'tcx> {
     Char(char),
     /// An integer's bit representation.
     Int(u128),
-    /// An `f16`.
-    F16(f16),
+    /// An `f16` bitcast to a `u16`.
+    // FIXME(f16_f128): use `f16` once builtins are available on all host tools platforms.
+    F16(u16),
     /// An `f32`.
     F32(f32),
     /// An `f64`.
     F64(f64),
-    /// An `f128`.
-    F128(f128),
+    /// An `f128` bitcast to a `u128`.
+    // FIXME(f16_f128): use `f128` once builtins are available on all host tools platforms.
+    F128(u128),
     /// `true` or `false`.
     Bool(bool),
     /// An array of constants.
@@ -175,7 +177,7 @@ impl Hash for Constant<'_> {
             },
             Self::F16(f) => {
                 // FIXME(f16_f128): once conversions to/from `f128` are available on all platforms,
-                f.to_bits().hash(state);
+                f.hash(state);
             },
             Self::F32(f) => {
                 f64::from(f).to_bits().hash(state);
@@ -184,7 +186,7 @@ impl Hash for Constant<'_> {
                 f.to_bits().hash(state);
             },
             Self::F128(f) => {
-                f.to_bits().hash(state);
+                f.hash(state);
             },
             Self::Bool(b) => {
                 b.hash(state);
@@ -290,12 +292,12 @@ impl Constant<'_> {
 
     fn parse_f16(s: &str) -> Self {
         let f: Half = s.parse().unwrap();
-        Self::F16(f16::from_bits(f.to_bits().try_into().unwrap()))
+        Self::F16(f.to_bits().try_into().unwrap())
     }
 
     fn parse_f128(s: &str) -> Self {
         let f: Quad = s.parse().unwrap();
-        Self::F128(f128::from_bits(f.to_bits()))
+        Self::F128(f.to_bits())
     }
 }
 
@@ -851,10 +853,10 @@ pub fn mir_to_const<'tcx>(tcx: TyCtxt<'t
             ty::Adt(adt_def, _) if adt_def.is_struct() => Some(Constant::Adt(result)),
             ty::Bool => Some(Constant::Bool(int == ScalarInt::TRUE)),
             ty::Uint(_) | ty::Int(_) => Some(Constant::Int(int.to_bits(int.size()))),
-            ty::Float(FloatTy::F16) => Some(Constant::F16(f16::from_bits(int.into()))),
+            ty::Float(FloatTy::F16) => Some(Constant::F16(int.into())),
             ty::Float(FloatTy::F32) => Some(Constant::F32(f32::from_bits(int.into()))),
             ty::Float(FloatTy::F64) => Some(Constant::F64(f64::from_bits(int.into()))),
-            ty::Float(FloatTy::F128) => Some(Constant::F128(f128::from_bits(int.into()))),
+            ty::Float(FloatTy::F128) => Some(Constant::F128(int.into())),
             ty::RawPtr(_, _) => Some(Constant::RawPtr(int.to_bits(int.size()))),
             _ => None,
         },
@@ -875,10 +877,10 @@ pub fn mir_to_const<'tcx>(tcx: TyCtxt<'t
                 let range = alloc_range(offset + size * idx, size);
                 let val = alloc.read_scalar(&tcx, range, /* read_provenance */ false).ok()?;
                 res.push(match flt {
-                    FloatTy::F16 => Constant::F16(f16::from_bits(val.to_u16().discard_err()?)),
+                    FloatTy::F16 => Constant::F16(val.to_u16().discard_err()?),
                     FloatTy::F32 => Constant::F32(f32::from_bits(val.to_u32().discard_err()?)),
                     FloatTy::F64 => Constant::F64(f64::from_bits(val.to_u64().discard_err()?)),
-                    FloatTy::F128 => Constant::F128(f128::from_bits(val.to_u128().discard_err()?)),
+                    FloatTy::F128 => Constant::F128(val.to_u128().discard_err()?),
                 });
             }
             Some(Constant::Vec(res))
