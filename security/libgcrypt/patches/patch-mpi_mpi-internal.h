$NetBSD: patch-mpi_mpi-internal.h,v 1.1 2011/07/13 21:21:52 adam Exp $

Change inline functions to static, which fixes building with Clang.

--- mpi/mpi-internal.h.orig	2011-07-13 21:13:23.000000000 +0000
+++ mpi/mpi-internal.h
@@ -183,23 +183,23 @@ void _gcry_mpi_lshift_limbs( gcry_mpi_t 
 
 
 /*-- mpih-add.c --*/
-mpi_limb_t _gcry_mpih_add_1(mpi_ptr_t res_ptr,  mpi_ptr_t s1_ptr,
+static mpi_limb_t _gcry_mpih_add_1(mpi_ptr_t res_ptr,  mpi_ptr_t s1_ptr,
 			 mpi_size_t s1_size, mpi_limb_t s2_limb );
 mpi_limb_t _gcry_mpih_add_n( mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr,
 			  mpi_ptr_t s2_ptr,  mpi_size_t size);
-mpi_limb_t _gcry_mpih_add(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr, mpi_size_t s1_size,
+static mpi_limb_t _gcry_mpih_add(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr, mpi_size_t s1_size,
 		       mpi_ptr_t s2_ptr, mpi_size_t s2_size);
 
 /*-- mpih-sub.c --*/
-mpi_limb_t _gcry_mpih_sub_1( mpi_ptr_t res_ptr,  mpi_ptr_t s1_ptr,
+static mpi_limb_t _gcry_mpih_sub_1( mpi_ptr_t res_ptr,  mpi_ptr_t s1_ptr,
 			  mpi_size_t s1_size, mpi_limb_t s2_limb );
 mpi_limb_t _gcry_mpih_sub_n( mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr,
 			  mpi_ptr_t s2_ptr, mpi_size_t size);
-mpi_limb_t _gcry_mpih_sub(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr, mpi_size_t s1_size,
+static mpi_limb_t _gcry_mpih_sub(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr, mpi_size_t s1_size,
 		       mpi_ptr_t s2_ptr, mpi_size_t s2_size);
 
 /*-- mpih-cmp.c --*/
-int _gcry_mpih_cmp( mpi_ptr_t op1_ptr, mpi_ptr_t op2_ptr, mpi_size_t size );
+static int _gcry_mpih_cmp( mpi_ptr_t op1_ptr, mpi_ptr_t op2_ptr, mpi_size_t size );
 
 /*-- mpih-mul.c --*/
 
