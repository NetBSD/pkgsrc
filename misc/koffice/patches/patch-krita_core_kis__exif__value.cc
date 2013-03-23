$NetBSD: patch-krita_core_kis__exif__value.cc,v 1.1 2013/03/23 10:15:26 joerg Exp $

--- krita/core/kis_exif_value.cc.orig	2013-02-28 15:55:48.000000000 +0000
+++ krita/core/kis_exif_value.cc
@@ -24,16 +24,16 @@
 #include <kmdcodec.h>
 
 namespace {
-void set16Bit (unsigned char *data, ExifValue::ByteOrder order, const Q_UINT16* value)
+void set16Bit (unsigned char *data, ExifValue::ByteOrder order, Q_UINT16 value)
 {
     switch (order) {
         case ExifValue::BYTE_ORDER_MOTOROLA:
-            data[0] = (unsigned char) (*value >> 8);
-            data[1] = (unsigned char) *value;
+            data[0] = (unsigned char) (value >> 8);
+            data[1] = (unsigned char) value;
             break;
         case ExifValue::BYTE_ORDER_INTEL:
-            data[0] = (unsigned char) *value;
-            data[1] = (unsigned char) (*value >> 8);
+            data[0] = (unsigned char) value;
+            data[1] = (unsigned char) (value >> 8);
             break;
     }
 }
@@ -61,20 +61,20 @@ void get32Bit (const unsigned char *data
     }
 }
 
-void set32Bit(unsigned char *data, ExifValue::ByteOrder order, const Q_UINT32* value)
+void set32Bit(unsigned char *data, ExifValue::ByteOrder order, Q_UINT32 value)
 {
     switch (order) {
         case ExifValue::BYTE_ORDER_MOTOROLA:
-            data[0] = (unsigned char) (*value >> 24);
-            data[1] = (unsigned char) (*value >> 16);
-            data[2] = (unsigned char) (*value >> 8);
-            data[3] = (unsigned char) *value;
+            data[0] = (unsigned char) (value >> 24);
+            data[1] = (unsigned char) (value >> 16);
+            data[2] = (unsigned char) (value >> 8);
+            data[3] = (unsigned char) value;
             break;
         case ExifValue::BYTE_ORDER_INTEL:
-            data[3] = (unsigned char) (*value >> 24);
-            data[2] = (unsigned char) (*value >> 16);
-            data[1] = (unsigned char) (*value >> 8);
-            data[0] = (unsigned char) *value;
+            data[3] = (unsigned char) (value >> 24);
+            data[2] = (unsigned char) (value >> 16);
+            data[1] = (unsigned char) (value >> 8);
+            data[0] = (unsigned char) value;
             break;
     }
 }
@@ -90,28 +90,28 @@ void get64Bit (const unsigned char *data
     }
 }
 
-void set64Bit(unsigned char *data, ExifValue::ByteOrder order, const Q_UINT64* value)
+void set64Bit(unsigned char *data, ExifValue::ByteOrder order, Q_UINT64 value)
 {
     switch (order) {
         case ExifValue::BYTE_ORDER_MOTOROLA:
-            data[0] = (unsigned char) (*value >> 56);
-            data[1] = (unsigned char) (*value >> 48);
-            data[2] = (unsigned char) (*value >> 40);
-            data[3] = (unsigned char) (*value >> 32);
-            data[4] = (unsigned char) (*value >> 24);
-            data[5] = (unsigned char) (*value >> 16);
-            data[6] = (unsigned char) (*value >> 8);
-            data[7] = (unsigned char) *value;
+            data[0] = (unsigned char) (value >> 56);
+            data[1] = (unsigned char) (value >> 48);
+            data[2] = (unsigned char) (value >> 40);
+            data[3] = (unsigned char) (value >> 32);
+            data[4] = (unsigned char) (value >> 24);
+            data[5] = (unsigned char) (value >> 16);
+            data[6] = (unsigned char) (value >> 8);
+            data[7] = (unsigned char) value;
             break;
         case ExifValue::BYTE_ORDER_INTEL:
-            data[7] = (unsigned char) (*value >> 56);
-            data[6] = (unsigned char) (*value >> 48);
-            data[5] = (unsigned char) (*value >> 40);
-            data[4] = (unsigned char) (*value >> 32);
-            data[3] = (unsigned char) (*value >> 24);
-            data[2] = (unsigned char) (*value >> 16);
-            data[1] = (unsigned char) (*value >> 8);
-            data[0] = (unsigned char) *value;
+            data[7] = (unsigned char) (value >> 56);
+            data[6] = (unsigned char) (value >> 48);
+            data[5] = (unsigned char) (value >> 40);
+            data[4] = (unsigned char) (value >> 32);
+            data[3] = (unsigned char) (value >> 24);
+            data[2] = (unsigned char) (value >> 16);
+            data[1] = (unsigned char) (value >> 8);
+            data[0] = (unsigned char) value;
             break;
     }
 }
@@ -532,7 +532,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set16Bit( (*data) + 2 * i, order, &asExifNumber(i).m_short);
+                set16Bit( (*data) + 2 * i, order, asExifNumber(i).m_short);
             }
             return;
         }
@@ -542,7 +542,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set32Bit( (*data) + 4 * i, order, &asExifNumber(i).m_long);
+                set32Bit( (*data) + 4 * i, order, asExifNumber(i).m_long);
             }
             return;
         }
@@ -552,8 +552,8 @@ void ExifValue::convertToData(unsigned c
             for(uint i = 0; i < components(); i++)
             {
                 ExifNumber n = asExifNumber(i);
-                set32Bit( (*data) + 8 * i, order, &n.m_rational.numerator);
-                set32Bit( (*data) + 8 * i + 4, order, &n.m_rational.denominator);
+                set32Bit( (*data) + 8 * i, order, n.m_rational.numerator);
+                set32Bit( (*data) + 8 * i + 4, order, n.m_rational.denominator);
             }
             return;
         case EXIF_TYPE_SBYTE:
@@ -577,7 +577,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set16Bit( (*data) + 2 * i, order, (Q_UINT16*)&asExifNumber(i).m_sshort);
+                set16Bit( (*data) + 2 * i, order, asExifNumber(i).m_sshort);
             }
             return;
         case EXIF_TYPE_SLONG:
@@ -585,7 +585,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set32Bit( (*data) + 4 * i, order, (Q_UINT32*)&asExifNumber(i).m_slong);
+                set32Bit( (*data) + 4 * i, order, asExifNumber(i).m_slong);
             }
             return;
         case EXIF_TYPE_SRATIONAL:
@@ -594,8 +594,8 @@ void ExifValue::convertToData(unsigned c
             for(uint i = 0; i < components(); i++)
             {
                 ExifNumber n = asExifNumber(i);
-                set32Bit( (*data) + 4 * i, order, (Q_UINT32*)&asExifNumber(i).m_srational.numerator);
-                set32Bit( (*data) + 4 * i + 4, order, (Q_UINT32*)&asExifNumber(i).m_srational.denominator);
+                set32Bit( (*data) + 4 * i, order, asExifNumber(i).m_srational.numerator);
+                set32Bit( (*data) + 4 * i + 4, order, asExifNumber(i).m_srational.denominator);
             }
             return;
         case EXIF_TYPE_FLOAT:
@@ -603,7 +603,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set32Bit( (*data) + 4 * i, order, (Q_UINT32*)&asExifNumber(i).m_float);
+                set32Bit( (*data) + 4 * i, order, asExifNumber(i).m_float);
             }
             return;
         case EXIF_TYPE_DOUBLE:
@@ -611,7 +611,7 @@ void ExifValue::convertToData(unsigned c
             *data = new uchar[*size];
             for(uint i = 0; i < components(); i++)
             {
-                set64Bit( (*data) + 4 * i, order, (Q_UINT64*)&asExifNumber(i).m_double);
+                set64Bit( (*data) + 4 * i, order, asExifNumber(i).m_double);
             }
             return;
         case EXIF_TYPE_UNKNOW:
