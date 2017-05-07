$NetBSD: patch-src_m_amd64.h,v 1.3 2017/05/07 06:49:23 tsutsui Exp $

amd64 support.

--- src/m/amd64.h.orig	2017-05-06 21:49:54.000000000 +0000
+++ src/m/amd64.h
@@ -0,0 +1,161 @@
+/* machine description file for AMD x86-64.
+   Copyright (C) 2002 Free Software Foundation, Inc.
+
+This file is part of GNU Emacs.
+
+GNU Emacs is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2, or (at your option)
+any later version.
+
+GNU Emacs is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GNU Emacs; see the file COPYING.  If not, write to
+the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+Boston, MA 02111-1307, USA.  */
+
+/* Linux defines these in <values.h>, but they can't be used in #if's */
+#undef SHORTBITS
+#undef INTBITS
+#undef LONGBITS
+  
+#define SHORTBITS 16		/* Number of bits in a short */
+
+#define INTBITS 32L		/* Number of bits in an int */
+
+#define LONGBITS 64L		/* Number of bits in a long */
+
+/* Define LONG_LISP_OBJECT if you define LISP_OBJECT as long. */
+
+#define LONG_LISP_OBJECT
+
+/* Define the number of bits compose Lisp_Object. The default is 32. */
+
+#define LISP_OBJECT_BITS 64
+
+#define PNTR_COMPARISON_TYPE unsigned long
+
+/* The following line tells the configuration script what sort of 
+   operating system this machine is likely to run.
+   USUAL-OPSYS="linux"  */
+
+#define BITS_PER_LONG           64
+#define BITS_PER_EMACS_INT      64
+
+/* Define BIG_ENDIAN iff lowest-numbered byte in a word
+   is the most significant byte.  */
+
+#undef BIG_ENDIAN
+
+/* Define NO_ARG_ARRAY if you cannot take the address of the first of a
+ * group of arguments and treat it as an array of the arguments.  */
+
+#define NO_ARG_ARRAY
+
+/* Define WORD_MACHINE if addresses and such have
+ * to be corrected before they can be used as byte counts.  */
+
+/* #define WORD_MACHINE  */
+
+/* Define how to take a char and sign-extend into an int.
+   On machines where char is signed, this is a no-op.  */
+
+#define SIGN_EXTEND_CHAR(c) ((signed char)(c))
+
+/* Now define a symbol for the cpu type, if your compiler
+   does not define it automatically:
+   Ones defined so far include vax, m68000, ns16000, pyramid,
+   orion, tahoe, APOLLO and many others */
+/* __x86_64 defined automatically.  */
+
+/* Use type int rather than a union, to represent Lisp_Object */
+/* This is desirable for most machines.  */
+
+#define NO_UNION_TYPE
+
+/* Define the type to use.  */
+#define EMACS_INT               long
+#define EMACS_UINT              unsigned long
+#define SPECIAL_EMACS_INT
+
+/* Define EXPLICIT_SIGN_EXTEND if XINT must explicitly sign-extend
+   the 24-bit bit field into an int.  In other words, if bit fields
+   are always unsigned.
+
+   If you use NO_UNION_TYPE, this flag does not matter.  */
+
+#define EXPLICIT_SIGN_EXTEND
+
+/* Data type of load average, as read out of kmem.  */
+
+#define LOAD_AVE_TYPE long
+
+/* Convert that into an integer that is 100 for a load average of 1.0  */
+
+#define LOAD_AVE_CVT(x) (int) (((double) (x)) * 100.0 / FSCALE)
+
+/* Define CANNOT_DUMP on machines where unexec does not work.
+   Then the function dump-emacs will not be defined
+   and temacs will do (load "loadup") automatically unless told otherwise.  */
+
+/* #define CANNOT_DUMP */
+
+/* Define VIRT_ADDR_VARIES if the virtual addresses of
+   pure and impure space as loaded can vary, and even their
+   relative order cannot be relied on.
+
+   Otherwise Emacs assumes that text space precedes data space,
+   numerically.  */
+
+#define VIRT_ADDR_VARIES  /* XXX */
+
+/* Define C_ALLOCA if this machine does not support a true alloca
+   and the one written in C should be used instead.
+   Define HAVE_ALLOCA to say that the system provides a properly
+   working alloca function and it should be used.
+   Define neither one if an assembler-language alloca
+   in the file alloca.s should be used.  */
+
+/* #define C_ALLOCA */      /* XXX */
+#define HAVE_ALLOCA
+
+/* Define NO_REMAP if memory segmentation makes it not work well
+   to change the boundary between the text section and data section
+   when Emacs is dumped.  If you define this, the preloaded Lisp
+   code will not be sharable; but that's better than failing completely.  */
+
+#define NO_REMAP  /* XXX */
+
+#define PNTR_COMPARISON_TYPE unsigned long
+
+#if 0
+/* On the 64 bit architecture, we can use 60 bits for addresses */
+
+#define VALBITS         60
+
+/* This definition of MARKBIT is necessary because of the comparison of
+   ARRAY_MARK_FLAG and MARKBIT in an #if in lisp.h, which cpp doesn't like. */
+
+#define MARKBIT         0x8000000000000000L
+
+/* Define XINT and XUINT so that they can take arguments of type int */
+#define XINT(a)  (((long) (a) << (BITS_PER_LONG - VALBITS)) >> (BITS_PER_LONG - VALBITS))
+#define XUINT(a) ((long) (a) & VALMASK)
+#endif
+
+/* Define XPNTR to avoid or'ing with DATA_SEG_BITS */
+
+#define XPNTR(a) XUINT (a)
+
+/* Define XMARKBIT to avoid a dumb optimization using sign bit */
+#define XMARKBIT(a) ((a) & MARKBIT)
+
+/* #undef START_FILES */ /* XXX */
+/* #define START_FILES pre-crt0.o /usr/lib64/crt1.o /usr/lib64/crti.o */ /* XXX */
+
+/* #undef LIB_STANDARD */                                    /* XXX */
+/* #define LIB_STANDARD -lgcc -lc -lgcc /usr/lib64/crtn.o */ /* XXX */
