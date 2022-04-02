$NetBSD: patch-libstark_src_protocols_common_CryptoCommitment_MerkleCommitment.hpp,v 1.1 2022/04/02 11:31:54 nia Exp $

Add missing include.

--- libstark/src/protocols/common/CryptoCommitment/MerkleCommitment.hpp.orig	2018-12-11 08:57:02.000000000 +0000
+++ libstark/src/protocols/common/CryptoCommitment/MerkleCommitment.hpp
@@ -6,6 +6,7 @@
 #include <cstring>
 #include <map>
 #include <set>
+#include <string>
 
 namespace libstark{
 namespace Protocols{
