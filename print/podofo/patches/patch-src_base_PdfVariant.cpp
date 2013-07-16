$NetBSD: patch-src_base_PdfVariant.cpp,v 1.1 2013/07/16 21:28:43 joerg Exp $

--- src/base/PdfVariant.cpp.orig	2011-04-19 17:34:25.000000000 +0000
+++ src/base/PdfVariant.cpp
@@ -267,8 +267,24 @@ void PdfVariant::Write( PdfOutputDevice*
             std::ostringstream oss;
             PdfLocaleImbue(oss);
             oss << std::fixed << m_Data.dNumber;
+            size_t len = oss.str().size();
 
-            pDevice->Write( oss.str().c_str(), oss.str().size() );
+            if( (eWriteMode & ePdfWriteMode_Compact) == ePdfWriteMode_Compact && 
+                oss.str().find('.') != string::npos )
+            {
+                const char *str = oss.str().c_str();
+                while( str[len - 1] == '0' )
+                    --len;
+                if( str[len - 1] == '.' )
+                    --len;
+                if( len == 0 )
+                {
+                    pDevice->Write( "0", 1 );
+                    break;
+                }
+            }
+
+            pDevice->Write( oss.str().c_str(), len );
             break;
         }
         case ePdfDataType_HexString:
