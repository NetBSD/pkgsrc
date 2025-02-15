$NetBSD: patch-.._vendor_half-2.3.1_src_binary16_arch.rs,v 1.1 2025/02/15 23:41:45 he Exp $

Try to use neon only on little-endian aarch64.

--- ../vendor/half-2.3.1/src/binary16/arch.rs.orig	2024-10-02 18:19:08.769858146 +0000
+++ ../vendor/half-2.3.1/src/binary16/arch.rs
@@ -5,7 +5,7 @@ use core::mem;
 #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
 mod x86;
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64;
 
 macro_rules! convert_fn {
@@ -22,6 +22,7 @@ macro_rules! convert_fn {
             }
             else if #[cfg(all(
                 target_arch = "aarch64",
+                target_endian = "little",
                 target_feature = "fp16"
             ))] {
                 $aarch64
@@ -43,6 +44,7 @@ macro_rules! convert_fn {
             else if #[cfg(all(
                 feature = "std",
                 target_arch = "aarch64",
+                target_endian = "little",
             ))] {
                 use std::arch::is_aarch64_feature_detected;
                 if is_aarch64_feature_detected!("fp16") {
@@ -299,6 +301,7 @@ macro_rules! math_fn {
             // Use intrinsics directly when a compile target or using no_std
             if #[cfg(all(
                 target_arch = "aarch64",
+                target_endian = "little",
                 target_feature = "fp16"
             ))] {
                 $aarch64
@@ -308,6 +311,7 @@ macro_rules! math_fn {
             else if #[cfg(all(
                 feature = "std",
                 target_arch = "aarch64",
+                target_endian = "little",
                 not(target_feature = "fp16")
             ))] {
                 use std::arch::is_aarch64_feature_detected;
