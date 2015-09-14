$NetBSD: patch-crypto_math_datatypes.c,v 1.1 2015/09/14 13:30:03 joerg Exp $

--- crypto/math/datatypes.c.orig	2015-09-13 19:22:57.000000000 +0000
+++ crypto/math/datatypes.c
@@ -124,7 +124,7 @@ octet_string_hex_string(const void *s, i
   return bit_string;
 }
 
-inline int
+static inline int
 hex_char_to_nibble(uint8_t c) {
   switch(c) {
   case ('0'): return 0x0;
