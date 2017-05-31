$NetBSD: patch-src__vcdecoder_test.cc,v 1.1 2017/05/31 22:32:52 agc Exp $

avoid compiler errors by casting.

--- src/vcdecoder_test.cc	2017/05/31 22:19:10	1.1
+++ src/vcdecoder_test.cc	2017/05/31 22:22:27
@@ -25,17 +25,17 @@
 namespace open_vcdiff {
 
 const char VCDiffDecoderTest::kStandardFileHeader[] = {
-    0xD6,  // 'V' | 0x80
-    0xC3,  // 'C' | 0x80
-    0xC4,  // 'D' | 0x80
-    0x00,  // Draft standard version number
+    (char)0xD6,  // 'V' | 0x80
+    (char)0xC3,  // 'C' | 0x80
+    (char)0xC4,  // 'D' | 0x80
+    (char)0x00,  // Draft standard version number
     0x00   // Hdr_Indicator: no custom code table, no compression
   };
 
 const char VCDiffDecoderTest::kInterleavedFileHeader[] = {
-    0xD6,  // 'V' | 0x80
-    0xC3,  // 'C' | 0x80
-    0xC4,  // 'D' | 0x80
+    (char)0xD6,  // 'V' | 0x80
+    (char)0xC3,  // 'C' | 0x80
+    (char)0xC4,  // 'D' | 0x80
     'S',   // SDCH version code
     0x00   // Hdr_Indicator: no custom code table, no compression
   };
@@ -102,7 +102,7 @@
 // (0x7FFFFFFF) at the given offset in the delta window.
 void VCDiffDecoderTest::WriteMaxVarintAtOffset(int offset,
                                                int bytes_to_replace) {
-  static const char kMaxVarint[] = { 0x87, 0xFF, 0xFF, 0xFF, 0x7F };
+  static const char kMaxVarint[] = { (char)0x87, (char)0xFF, (char)0xFF, (char)0xFF, (char)0x7F };
   delta_file_.replace(delta_file_header_.size() + offset,
                       bytes_to_replace,
                       kMaxVarint,
@@ -113,7 +113,7 @@
 // in the delta window.
 void VCDiffDecoderTest::WriteNegativeVarintAtOffset(int offset,
                                                     int bytes_to_replace) {
-  static const char kNegativeVarint[] = { 0x88, 0x80, 0x80, 0x80, 0x00 };
+  static const char kNegativeVarint[] = { (char)0x88, (char)0x80, (char)0x80, (char)0x80, 0x00 };
   delta_file_.replace(delta_file_header_.size() + offset,
                       bytes_to_replace,
                       kNegativeVarint,
@@ -124,7 +124,7 @@
 // at the given offset in the delta window.
 void VCDiffDecoderTest::WriteInvalidVarintAtOffset(int offset,
                                                    int bytes_to_replace) {
-  static const char kInvalidVarint[] = { 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F };
+  static const char kInvalidVarint[] = { (char)0x87, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0x7F };
   delta_file_.replace(delta_file_header_.size() + offset,
                       bytes_to_replace,
                       kInvalidVarint,
@@ -137,12 +137,12 @@
     char _or;
     char _xor;
   } fuzzers[] = {
-    { 0xff, 0x80, 0x00 },
-    { 0xff, 0xff, 0x00 },
-    { 0xff, 0x00, 0x80 },
-    { 0xff, 0x00, 0xff },
-    { 0xff, 0x01, 0x00 },
-    { 0x7f, 0x00, 0x00 },
+    { (char)0xff, (char)0x80, 0x00 },
+    { (char)0xff, (char)0xff, 0x00 },
+    { (char)0xff, (char)0x00, (char)0x80 },
+    { (char)0xff, (char)0x00, (char)0xff },
+    { (char)0xff, (char)0x01, 0x00 },
+    { (char)0x7f, 0x00, 0x00 },
   };
 
   for (; fuzzer_ < (sizeof(fuzzers) / sizeof(fuzzers[0])); ++fuzzer_) {
@@ -197,22 +197,22 @@
     't', 'h', 'r', 'e', 'e', ' ', 't', 'i', 'm', 'e', 's', ' ', 'i', 's', ' ',
     't', 'r', 'u', 'e', '.', '\"', '\n',
     // Instructions and sizes (length 13)
-    0x13,  // VCD_COPY mode VCD_SELF, size 0
-    0x1C,  // Size of COPY (28)
-    0x01,  // VCD_ADD size 0
-    0x3D,  // Size of ADD (61)
-    0x23,  // VCD_COPY mode VCD_HERE, size 0
-    0x2C,  // Size of COPY (44)
-    0xCB,  // VCD_ADD size 2 + VCD_COPY mode NEAR(1), size 5
-    0x0A,  // VCD_ADD size 9
-    0x00,  // VCD_RUN size 0
-    0x02,  // Size of RUN (2)
-    0x01,  // VCD_ADD size 0
-    0x1B,  // Size of ADD (27)
+    (char)0x13,  // VCD_COPY mode VCD_SELF, size 0
+    (char)0x1C,  // Size of COPY (28)
+    (char)0x01,  // VCD_ADD size 0
+    (char)0x3D,  // Size of ADD (61)
+    (char)0x23,  // VCD_COPY mode VCD_HERE, size 0
+    (char)0x2C,  // Size of COPY (44)
+    (char)0xCB,  // VCD_ADD size 2 + VCD_COPY mode NEAR(1), size 5
+    (char)0x0A,  // VCD_ADD size 9
+    (char)0x00,  // VCD_RUN size 0
+    (char)0x02,  // Size of RUN (2)
+    (char)0x01,  // VCD_ADD size 0
+    (char)0x1B,  // Size of ADD (27)
     // Addresses for COPYs (length 3)
-    0x00,  // Start of dictionary
-    0x58,  // HERE mode address for 2nd copy (27+61 back from here_address)
-    0x2D   // NEAR(1) mode address for 2nd copy (45 after prior address)
+    (char)0x00,  // Start of dictionary
+    (char)0x58,  // HERE mode address for 2nd copy (27+61 back from here_address)
+    (char)0x2D   // NEAR(1) mode address for 2nd copy (45 after prior address)
   };
 
 VCDiffStandardDecoderTest::VCDiffStandardDecoderTest() {
@@ -231,16 +231,16 @@
     SecondByteOfStringLength(kExpectedTarget),
     0x00,  // Delta_indicator (no compression)
     0x00,  // length of data for ADDs and RUNs (unused)
-    0x73,  // length of interleaved section
+    (char)0x73,  // length of interleaved section
     0x00  // length of addresses for COPYs (unused)
   };
 
 const char VCDiffInterleavedDecoderTest::kWindowBody[] = {
-    0x13,  // VCD_COPY mode VCD_SELF, size 0
-    0x1C,  // Size of COPY (28)
+    (char)0x13,  // VCD_COPY mode VCD_SELF, size 0
+    (char)0x1C,  // Size of COPY (28)
     0x00,  // Address of COPY: Start of dictionary
-    0x01,  // VCD_ADD size 0
-    0x3D,  // Size of ADD (61)
+    (char)0x01,  // VCD_ADD size 0
+    (char)0x3D,  // Size of ADD (61)
     // Data for ADD (length 61)
     ' ', 'I', ' ', 'h', 'a', 'v', 'e', ' ', 's', 'a', 'i', 'd', ' ',
     'i', 't', ' ', 't', 'w', 'i', 'c', 'e', ':', '\n',
@@ -248,23 +248,23 @@
     'a', 'l', 'o', 'n', 'e', ' ', 's', 'h', 'o', 'u', 'l', 'd', ' ',
     'e', 'n', 'c', 'o', 'u', 'r', 'a', 'g', 'e', ' ',
     't', 'h', 'e', ' ', 'c', 'r', 'e', 'w', '.', '\n',
-    0x23,  // VCD_COPY mode VCD_HERE, size 0
-    0x2C,  // Size of COPY (44)
-    0x58,  // HERE mode address (27+61 back from here_address)
-    0xCB,  // VCD_ADD size 2 + VCD_COPY mode NEAR(1), size 5
+    (char)0x23,  // VCD_COPY mode VCD_HERE, size 0
+    (char)0x2C,  // Size of COPY (44)
+    (char)0x58,  // HERE mode address (27+61 back from here_address)
+    (char)0xCB,  // VCD_ADD size 2 + VCD_COPY mode NEAR(1), size 5
     // Data for ADDs: 2nd section (length 2)
     'h', 'r',
-    0x2D,  // NEAR(1) mode address (45 after prior address)
-    0x0A,  // VCD_ADD size 9
+    (char)0x2D,  // NEAR(1) mode address (45 after prior address)
+    (char)0x0A,  // VCD_ADD size 9
     // Data for ADDs: 3rd section (length 9)
     'W', 'h', 'a', 't', ' ',
     'I', ' ', 't', 'e',
-    0x00,  // VCD_RUN size 0
-    0x02,  // Size of RUN (2)
+    (char)0x00,  // VCD_RUN size 0
+    (char)0x02,  // Size of RUN (2)
     // Data for RUN: 4th section (length 1)
     'l',
-    0x01,  // VCD_ADD size 0
-    0x1B,  // Size of ADD (27)
+    (char)0x01,  // VCD_ADD size 0
+    (char)0x1B,  // Size of ADD (27)
     // Data for ADD: 4th section (length 27)
     ' ', 'y', 'o', 'u', ' ',
     't', 'h', 'r', 'e', 'e', ' ', 't', 'i', 'm', 'e', 's', ' ', 'i', 's', ' ',
