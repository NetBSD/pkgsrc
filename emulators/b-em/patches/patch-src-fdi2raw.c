$NetBSD: patch-src-fdi2raw.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/fdi2raw.c.orig	2010-10-17 11:23:56.000000000 +0000
+++ src/fdi2raw.c
@@ -1628,7 +1628,7 @@ static void fdi2_decode (FDI *fdi, uint3
 				randval = rand();
 				if (randval < (RAND_MAX / 2)) {
 					if (randval > (RAND_MAX / 4)) {
-						if (randval <= (3 * RAND_MAX / 8))
+						if (randval <= (3 * (RAND_MAX / 8)))
 							randval = (2 * randval) - (RAND_MAX /4);
 						else
 							randval = (4 * randval) - RAND_MAX;
@@ -1637,7 +1637,7 @@ static void fdi2_decode (FDI *fdi, uint3
 				} else {
 					randval -= RAND_MAX / 2;
 					if (randval > (RAND_MAX / 4)) {
-						if (randval <= (3 * RAND_MAX / 8))
+						if (randval <= (3 * (RAND_MAX / 8)))
 							randval = (2 * randval) - (RAND_MAX /4);
 						else
 							randval = (4 * randval) - RAND_MAX;
@@ -1663,7 +1663,7 @@ static void fdi2_decode (FDI *fdi, uint3
 				randval = rand();
 				if (randval < (RAND_MAX / 2)) {
 					if (randval > (RAND_MAX / 4)) {
-						if (randval <= (3 * RAND_MAX / 8))
+						if (randval <= (3 * (RAND_MAX / 8)))
 							randval = (2 * randval) - (RAND_MAX /4);
 						else
 							randval = (4 * randval) - RAND_MAX;
@@ -1672,7 +1672,7 @@ static void fdi2_decode (FDI *fdi, uint3
 				} else {
 					randval -= RAND_MAX / 2;
 					if (randval > (RAND_MAX / 4)) {
-						if (randval <= (3 * RAND_MAX / 8))
+						if (randval <= (3 * (RAND_MAX / 8)))
 							randval = (2 * randval) - (RAND_MAX /4);
 						else
 							randval = (4 * randval) - RAND_MAX;
