$NetBSD: patch-src_prng.h,v 1.1 2012/11/01 19:42:01 joerg Exp $

--- src/prng.h.orig	2001-11-06 20:04:41.000000000 +0000
+++ src/prng.h
@@ -405,8 +405,7 @@ struct prng *prng_external_init(struct p
 
 /* INLINE fnk def. for mult_mod, I don't know if this works for non-GCC */
 
-#ifdef __GNUC__
-extern __inline__ prng_num mult_mod(prng_num s,struct mult_mod_struct *mm)
+static __inline__ prng_num mult_mod(prng_num s,struct mult_mod_struct *mm)
 {
 s_prng_num s_tmp;
 
@@ -437,8 +436,5 @@ switch(mm->algorithm)
 /* not reached */
 return(0);
 }
-#else	/* rely on function in support.h */
-prng_num mult_mod(prng_num s,struct mult_mod_struct *mm); 
-#endif
 
 #endif /* __PRNG_H__ */
