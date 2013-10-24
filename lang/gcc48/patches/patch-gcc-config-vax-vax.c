$NetBSD: patch-gcc-config-vax-vax.c,v 1.1 2013/10/24 18:31:12 martin Exp $

Part of upstream change rev. 202796

--- gcc/config/vax/vax.c.orig	2013-01-10 21:38:27.000000000 +0100
+++ gcc/config/vax/vax.c	2013-09-18 14:33:37.000000000 +0200
@@ -1187,7 +1187,7 @@
 		{
 		  operands[1] = GEN_INT (lval);
 		  operands[2] = GEN_INT (n);
-		  return "ashq %2,%1,%0";
+		  return "ashq %2,%D1,%0";
 		}
 #if HOST_BITS_PER_WIDE_INT == 32
 	    }
@@ -1199,7 +1199,7 @@
 	    {
 	      operands[1] = GEN_INT (hval >> n);
 	      operands[2] = GEN_INT (n + 32);
-	      return "ashq %2,%1,%0";
+	      return "ashq %2,%D1,%0";
 #endif
 	    }
 	}
