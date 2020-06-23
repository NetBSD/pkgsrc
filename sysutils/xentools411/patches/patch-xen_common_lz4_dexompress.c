--- ./xen/common/lz4/decompress.c.orig	2020-06-23 03:41:56.777396819 +0200
+++ ./xen/common/lz4/decompress.c	2020-06-23 03:42:40.735064865 +0200
@@ -146,9 +146,9 @@
 			if (op == oend)
 				goto _output_error;
 			continue;
 		}
-		if (unlikely((unsigned long)cpy < (unsigned long)op))
+		if (unlikely((unsigned long)cpy < (unsigned long)op - (STEPSIZE - 4)))
 			goto _output_error;
 		LZ4_SECURECOPY(ref, op, cpy);
 		op = cpy; /* correction */
 	}
@@ -278,9 +278,9 @@
 			if (op == oend)
 				goto _output_error;
 			continue;
 		}
-		if (unlikely((unsigned long)cpy < (unsigned long)op))
+		if (unlikely((unsigned long)cpy < (unsigned long)op - (STEPSIZE - 4)))
 			goto _output_error;
 		LZ4_SECURECOPY(ref, op, cpy);
 		op = cpy; /* correction */
 	}
