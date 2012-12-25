$NetBSD: patch-source_core_NstMemory.hpp,v 1.1 2012/12/25 21:10:29 joerg Exp $

--- source/core/NstMemory.hpp.orig	2012-12-25 16:47:49.000000000 +0000
+++ source/core/NstMemory.hpp
@@ -763,7 +763,7 @@ namespace Nes
 				for (uint i=0; i < MEM_NUM_PAGES; ++i)
 				{
 					if (pageData[i*3+0] < NUM_SOURCES)
-						Source( pageData[i*3+0] ).SwapBank<MEM_PAGE_SIZE>( i * MEM_PAGE_SIZE, pageData[i*3+1] | uint(pageData[i*3+2]) << 8 );
+						SwapBank<MEM_PAGE_SIZE>( i * MEM_PAGE_SIZE, pageData[i*3+1] | uint(pageData[i*3+2]) << 8 );
 					else
 						throw RESULT_ERR_CORRUPT_FILE;
 				}
