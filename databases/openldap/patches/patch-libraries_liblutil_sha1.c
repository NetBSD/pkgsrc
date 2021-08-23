$NetBSD: patch-libraries_liblutil_sha1.c,v 1.1 2021/08/23 09:58:58 adam Exp $

--- libraries/liblutil/sha1.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ libraries/liblutil/sha1.c
@@ -50,10 +50,16 @@
 #define SHA1HANDSOFF		/* Copies data before messing with it. */
 #define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
 
+#if defined(__sparcv9) && \
+    ((__GNUC__ < 3) || (__GNUC__ == 3 && __GNUC_MINOR__ < 3))
+# define SPARC64_GCC_BUG
+#endif
+
 /*
  * blk0() and blk() perform the initial expand.
  * I got the idea of expanding during the round function from SSLeay
  */
+#ifndef SPARC64_GCC_BUG
 #if BYTE_ORDER == LITTLE_ENDIAN
 # define blk0(i) (block[i] = (rol(block[i],24)&0xFF00FF00) \
     |(rol(block[i],8)&0x00FF00FF))
@@ -62,6 +68,16 @@
 #endif
 #define blk(i) (block[i&15] = rol(block[(i+13)&15]^block[(i+8)&15] \
     ^block[(i+2)&15]^block[i&15],1))
+#else
+#if BYTE_ORDER == LITTLE_ENDIAN
+# define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00) \
+    |(rol(block->l[i],8)&0x00FF00FF))
+#else
+# define blk0(i) block->l[i]
+#endif
+#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15] \
+    ^block->l[(i+2)&15]^block->l[i&15],1))
+#endif	/* !SPARC64_GCC_BUG */
 
 /*
  * (R0+R1), R2, R3, R4 are the different operations (rounds) used in SHA1
@@ -72,6 +88,68 @@
 #define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
 #define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);
 
+#ifdef SPARC64_GCC_BUG
+typedef union {
+    u_char c[64];
+    uint32 l[16];
+} CHAR64LONG16;
+
+void do_R01(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16
+*);
+void do_R2(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 
+*);
+void do_R3(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 
+*);
+void do_R4(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 
+*);
+
+#define nR0(v,w,x,y,z,i) R0(*v,*w,*x,*y,*z,i)
+#define nR1(v,w,x,y,z,i) R1(*v,*w,*x,*y,*z,i)
+#define nR2(v,w,x,y,z,i) R2(*v,*w,*x,*y,*z,i)
+#define nR3(v,w,x,y,z,i) R3(*v,*w,*x,*y,*z,i)
+#define nR4(v,w,x,y,z,i) R4(*v,*w,*x,*y,*z,i)
+
+void
+do_R01(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 *block)
+{
+    nR0(a,b,c,d,e, 0); nR0(e,a,b,c,d, 1); nR0(d,e,a,b,c, 2); nR0(c,d,e,a,b, 3);
+    nR0(b,c,d,e,a, 4); nR0(a,b,c,d,e, 5); nR0(e,a,b,c,d, 6); nR0(d,e,a,b,c, 7);
+    nR0(c,d,e,a,b, 8); nR0(b,c,d,e,a, 9); nR0(a,b,c,d,e,10); nR0(e,a,b,c,d,11);
+    nR0(d,e,a,b,c,12); nR0(c,d,e,a,b,13); nR0(b,c,d,e,a,14); nR0(a,b,c,d,e,15);
+    nR1(e,a,b,c,d,16); nR1(d,e,a,b,c,17); nR1(c,d,e,a,b,18); nR1(b,c,d,e,a,19);
+}
+
+void
+do_R2(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 *block)
+{
+    nR2(a,b,c,d,e,20); nR2(e,a,b,c,d,21); nR2(d,e,a,b,c,22); nR2(c,d,e,a,b,23);
+    nR2(b,c,d,e,a,24); nR2(a,b,c,d,e,25); nR2(e,a,b,c,d,26); nR2(d,e,a,b,c,27);
+    nR2(c,d,e,a,b,28); nR2(b,c,d,e,a,29); nR2(a,b,c,d,e,30); nR2(e,a,b,c,d,31);
+    nR2(d,e,a,b,c,32); nR2(c,d,e,a,b,33); nR2(b,c,d,e,a,34); nR2(a,b,c,d,e,35);
+    nR2(e,a,b,c,d,36); nR2(d,e,a,b,c,37); nR2(c,d,e,a,b,38); nR2(b,c,d,e,a,39);
+}
+
+void
+do_R3(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 *block)
+{
+    nR3(a,b,c,d,e,40); nR3(e,a,b,c,d,41); nR3(d,e,a,b,c,42); nR3(c,d,e,a,b,43);
+    nR3(b,c,d,e,a,44); nR3(a,b,c,d,e,45); nR3(e,a,b,c,d,46); nR3(d,e,a,b,c,47);
+    nR3(c,d,e,a,b,48); nR3(b,c,d,e,a,49); nR3(a,b,c,d,e,50); nR3(e,a,b,c,d,51);
+    nR3(d,e,a,b,c,52); nR3(c,d,e,a,b,53); nR3(b,c,d,e,a,54); nR3(a,b,c,d,e,55);
+    nR3(e,a,b,c,d,56); nR3(d,e,a,b,c,57); nR3(c,d,e,a,b,58); nR3(b,c,d,e,a,59);
+}
+
+void
+do_R4(uint32 *a, uint32 *b, uint32 *c, uint32 *d, uint32 *e, CHAR64LONG16 *block)
+{
+    nR4(a,b,c,d,e,60); nR4(e,a,b,c,d,61); nR4(d,e,a,b,c,62); nR4(c,d,e,a,b,63);
+    nR4(b,c,d,e,a,64); nR4(a,b,c,d,e,65); nR4(e,a,b,c,d,66); nR4(d,e,a,b,c,67);
+    nR4(c,d,e,a,b,68); nR4(b,c,d,e,a,69); nR4(a,b,c,d,e,70); nR4(e,a,b,c,d,71);
+    nR4(d,e,a,b,c,72); nR4(c,d,e,a,b,73); nR4(b,c,d,e,a,74); nR4(a,b,c,d,e,75);
+    nR4(e,a,b,c,d,76); nR4(d,e,a,b,c,77); nR4(c,d,e,a,b,78); nR4(b,c,d,e,a,79);
+}
+#endif	/* SPARC64_GCC_BUG */
+
 
 /*
  * Hash a single 512-bit block. This is the core of the algorithm.
@@ -80,13 +158,26 @@ void
 lutil_SHA1Transform( uint32 *state, const unsigned char *buffer )
 {
     uint32 a, b, c, d, e;
+#ifdef SPARC64_GCC_BUG
+    CHAR64LONG16 *block;
+#endif
 
+#ifndef SPARC64_GCC_BUG
 #ifdef SHA1HANDSOFF
     uint32 block[16];
     (void)AC_MEMCPY(block, buffer, 64);
 #else
     uint32 *block = (u_int32 *) buffer;
 #endif
+#else
+#ifdef SHA1HANDSOFF
+    CHAR64LONG16 workspace;
+    block = &workspace;
+    (void)AC_MEMCPY(block, buffer, 64);
+#else
+    block = (CHAR64LONG16 *) (void *) buffer;
+#endif
+#endif	/* !SPARC64_GCC_BUG */
 
     /* Copy context->state[] to working vars */
     a = state[0];
@@ -95,6 +186,7 @@ lutil_SHA1Transform( uint32 *state, cons
     d = state[3];
     e = state[4];
 
+#ifndef SPARC64_GCC_BUG
     /* 4 rounds of 20 operations each. Loop unrolled. */
     R0(a,b,c,d,e, 0); R0(e,a,b,c,d, 1); R0(d,e,a,b,c, 2); R0(c,d,e,a,b, 3);
     R0(b,c,d,e,a, 4); R0(a,b,c,d,e, 5); R0(e,a,b,c,d, 6); R0(d,e,a,b,c, 7);
@@ -116,6 +208,13 @@ lutil_SHA1Transform( uint32 *state, cons
     R4(c,d,e,a,b,68); R4(b,c,d,e,a,69); R4(a,b,c,d,e,70); R4(e,a,b,c,d,71);
     R4(d,e,a,b,c,72); R4(c,d,e,a,b,73); R4(b,c,d,e,a,74); R4(a,b,c,d,e,75);
     R4(e,a,b,c,d,76); R4(d,e,a,b,c,77); R4(c,d,e,a,b,78); R4(b,c,d,e,a,79);
+#else
+    do_R01(&a, &b, &c, &d, &e, block);
+    do_R2(&a, &b, &c, &d, &e, block);
+    do_R3(&a, &b, &c, &d, &e, block);
+    do_R4(&a, &b, &c, &d, &e, block);
+#endif	/* !SPARC64_GCC_BUG */
+
 
     /* Add the working vars back into context.state[] */
     state[0] += a;
