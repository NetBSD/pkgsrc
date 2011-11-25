$NetBSD: patch-files_utils.h,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/utils.h.orig	2011-11-25 17:29:26.000000000 +0000
+++ files/utils.h
@@ -22,6 +22,7 @@
 #ifndef _UTILS_H_
 #define _UTILS_H_
 
+#include <cstdio>
 #include <iostream>
 #include <string>
 #ifndef ALPHA_LINUX_CXX
@@ -70,7 +71,6 @@ inline uint16 Read2
 	return (b0 | (b1 << 8));
 	}
 
-#ifdef BUFSIZ	/* Kludgy, but I don't want to include stdio.h all the time.*/
 /*
  *	Read a 2-byte value from a file.
  */
@@ -85,7 +85,6 @@ inline uint16 Read2
 	std::fread(&b1,sizeof(uint8),1,in);
 	return (b0 | (b1 << 8));
 	}
-#endif
 
 /*
  *	Read a 2-byte value, hsb first.
@@ -113,7 +112,6 @@ inline uint16 Read2high
 	return ((b0 << 8) | b1);
 	}
 
-#ifdef BUFSIZ	/* Kludgy, but I don't want to include stdio.h all the time.*/
 /*
  *	Read a 2-byte value from a file.
  */
@@ -128,7 +126,6 @@ inline uint16 Read2high
 	std::fread(&b1,sizeof(uint8),1,in);
 	return ((b0 << 8) | b1);
 	}
-#endif
 
 /*
  *	Read a 4-byte long value, lsb first.
@@ -160,7 +157,6 @@ inline uint32 Read4
 	return (b0 | (b1<<8) | (b2<<16) | (b3<<24));
 	}
 
-#ifdef BUFSIZ	/* Kludgy, but I don't want to include stdio.h all the time.*/
 /*
  *	Read a 4-byte value from a file.
  */
@@ -177,7 +173,6 @@ inline uint32 Read4
 	std::fread(&b3,sizeof(uint8),1,in);
 	return (b0 | (b1<<8) | (b2<<16) | (b3<<24));
 	}
-#endif
 /*
  *	Read a 4-byte long value, hsb first.
  */
@@ -208,7 +203,6 @@ inline uint32 Read4high
 	return ((b0<<24) | (b1<<16) | (b2<<8) | b3);
 	}
 
-#ifdef BUFSIZ	/* Kludgy, but I don't want to include stdio.h all the time.*/
 /*
  *	Read a 4-byte value from a file.
  */
@@ -225,7 +219,6 @@ inline uint32 Read4high
 	std::fread(&b3,sizeof(uint8),1,in);
 	return ((b0<<24) | (b1<<16) | (b2<<8) | b3);
 	}
-#endif
 
 /*
  *	Write a 1-byte value.
