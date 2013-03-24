$NetBSD: patch-src_disp-vcd_vcd.h,v 1.1 2013/03/24 16:57:12 joerg Exp $

--- src/disp-vcd/vcd.h.orig	2013-03-23 18:50:47.000000000 +0000
+++ src/disp-vcd/vcd.h
@@ -47,7 +47,7 @@ int vcd_trace_pc( void );
 /* Interface for disp.c */
 int vcd_write_header( void );
 
-inline int vcd_set_clock( unsigned int c );
+int vcd_set_clock( unsigned int c );
 int vcd_write_clock( void );
 
 int vcd_bind_io_reg_shortcut( char *io_reg_name, int io_reg_addr );
