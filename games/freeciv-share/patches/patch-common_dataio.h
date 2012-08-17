$NetBSD: patch-common_dataio.h,v 1.1 2012/08/17 18:42:44 prlw1 Exp $

Fixes part 2 of http://secunia.com/advisories/40476/
c.f. https://gna.org/bugs/?20003

--- common/dataio.h.orig	2012-03-31 12:35:45.000000000 +0000
+++ common/dataio.h
@@ -53,27 +53,27 @@ size_t dio_input_remaining(struct data_i
 
 /* gets */
 
-void dio_get_uint8(struct data_in *din, int *dest);
-void dio_get_uint16(struct data_in *din, int *dest);
-void dio_get_uint32(struct data_in *din, int *dest);
+bool dio_get_uint8(struct data_in *din, int *dest);
+bool dio_get_uint16(struct data_in *din, int *dest);
+bool dio_get_uint32(struct data_in *din, int *dest);
 
-void dio_get_sint8(struct data_in *din, int *dest);
-void dio_get_sint16(struct data_in *din, int *dest);
+bool dio_get_sint8(struct data_in *din, int *dest);
+bool dio_get_sint16(struct data_in *din, int *dest);
 #define dio_get_sint32(d,v) dio_get_uint32(d,v)
 
 
-void dio_get_bool8(struct data_in *din, bool *dest);
-void dio_get_bool32(struct data_in *din, bool *dest);
-void dio_get_memory(struct data_in *din, void *dest, size_t dest_size);
-void dio_get_string(struct data_in *din, char *dest, size_t max_dest_size);
-void dio_get_bit_string(struct data_in *din, char *dest,
+bool dio_get_bool8(struct data_in *din, bool *dest);
+bool dio_get_bool32(struct data_in *din, bool *dest);
+bool dio_get_memory(struct data_in *din, void *dest, size_t dest_size);
+bool dio_get_string(struct data_in *din, char *dest, size_t max_dest_size);
+bool dio_get_bit_string(struct data_in *din, char *dest,
 			size_t max_dest_size);
-void dio_get_tech_list(struct data_in *din, int *dest);
-void dio_get_worklist(struct data_in *din, struct worklist *pwl);
-void dio_get_requirement(struct data_in *din, struct requirement *preq);
+bool dio_get_tech_list(struct data_in *din, int *dest);
+bool dio_get_worklist(struct data_in *din, struct worklist *pwl);
+bool dio_get_requirement(struct data_in *din, struct requirement *preq);
 
-void dio_get_uint8_vec8(struct data_in *din, int **values, int stop_value);
-void dio_get_uint16_vec8(struct data_in *din, int **values, int stop_value);
+bool dio_get_uint8_vec8(struct data_in *din, int **values, int stop_value);
+bool dio_get_uint16_vec8(struct data_in *din, int **values, int stop_value);
 
 /* Should be a function but we need some macro magic. */
 #define DIO_BV_GET(pdin, bv) \
