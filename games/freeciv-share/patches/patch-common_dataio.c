$NetBSD: patch-common_dataio.c,v 1.1 2012/08/17 18:42:44 prlw1 Exp $

Fixes part 2 of http://secunia.com/advisories/40476/
c.f. https://gna.org/bugs/?20003

--- common/dataio.c.orig	2012-03-31 12:35:45.000000000 +0000
+++ common/dataio.c
@@ -408,7 +408,7 @@ void dio_put_worklist(struct data_out *d
  Receive uint8 value to dest. In case of failure, value stored to dest
  will be zero. Note that zero is legal value even when there is no failure.
 **************************************************************************/
-void dio_get_uint8(struct data_in *din, int *dest)
+bool dio_get_uint8(struct data_in *din, int *dest)
 {
   if (enough_data(din, 1)) {
     if (dest) {
@@ -421,14 +421,18 @@ void dio_get_uint8(struct data_in *din, 
     din->current++;
   } else if (dest) {
     *dest = 0;
+
+    return FALSE;
   }
+
+  return TRUE;
 }
 
 /**************************************************************************
  Receive uint16 value to dest. In case of failure, value stored to dest
  will be zero. Note that zero is legal value even when there is no failure.
 **************************************************************************/
-void dio_get_uint16(struct data_in *din, int *dest)
+bool dio_get_uint16(struct data_in *din, int *dest)
 {
   if (enough_data(din, 2)) {
     if (dest) {
@@ -441,14 +445,18 @@ void dio_get_uint16(struct data_in *din,
     din->current += 2;
   } else if (dest) {
     *dest = 0;
+
+    return FALSE;
   }
+
+  return TRUE;
 }
 
 /**************************************************************************
  Receive uint32 value to dest. In case of failure, value stored to dest
  will be zero. Note that zero is legal value even when there is no failure.
 **************************************************************************/
-void dio_get_uint32(struct data_in *din, int *dest)
+bool dio_get_uint32(struct data_in *din, int *dest)
 {
   if (enough_data(din, 4)) {
     if (dest) {
@@ -461,17 +469,22 @@ void dio_get_uint32(struct data_in *din,
     din->current += 4;
   } else if (dest) {
     *dest = 0;
+
+    return FALSE;
   }
+
+  return TRUE;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_bool8(struct data_in *din, bool * dest)
+bool dio_get_bool8(struct data_in *din, bool * dest)
 {
   int ival;
+  bool retval;
 
-  dio_get_uint8(din, &ival);
+  retval = dio_get_uint8(din, &ival);
 
   if (ival != 0 && ival != 1) {
     log_error("Received value isn't boolean: %d", ival);
@@ -479,16 +492,19 @@ void dio_get_bool8(struct data_in *din, 
   }
 
   *dest = (ival != 0);
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_bool32(struct data_in *din, bool * dest)
+bool dio_get_bool32(struct data_in *din, bool * dest)
 {
   int ival = 0;
+  bool retval;
 
-  dio_get_uint32(din, &ival);
+  retval = dio_get_uint32(din, &ival);
 
   if (ival != 0 && ival != 1) {
     log_error("Received value isn't boolean: %d", ival);
@@ -496,57 +512,69 @@ void dio_get_bool32(struct data_in *din,
   }
 
   *dest = (ival != 0);
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_sint8(struct data_in *din, int *dest)
+bool dio_get_sint8(struct data_in *din, int *dest)
 {
   int tmp;
+  bool retval;
 
-  dio_get_uint8(din, &tmp);
+  retval = dio_get_uint8(din, &tmp);
   if (dest) {
     if (tmp > 0x7f) {
       tmp -= 0x100;
     }
     *dest = tmp;
   }
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_sint16(struct data_in *din, int *dest)
+bool dio_get_sint16(struct data_in *din, int *dest)
 {
   int tmp = 0;
+  bool retval;
 
-  dio_get_uint16(din, &tmp);
+  retval = dio_get_uint16(din, &tmp);
   if (dest) {
     if (tmp > 0x7fff) {
       tmp -= 0x10000;
     }
     *dest = tmp;
   }
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_memory(struct data_in *din, void *dest, size_t dest_size)
+bool dio_get_memory(struct data_in *din, void *dest, size_t dest_size)
 {
   if (enough_data(din, dest_size)) {
     if (dest) {
       memcpy(dest, ADD_TO_POINTER(din->src, din->current), dest_size);
     }
     din->current += dest_size;
+  } else {
+    return FALSE;
   }
+
+  return TRUE;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_string(struct data_in *din, char *dest, size_t max_dest_size)
+bool dio_get_string(struct data_in *din, char *dest, size_t max_dest_size)
 {
   char *c;
   size_t ps_len;		/* length in packet, not including null */
@@ -556,7 +584,7 @@ void dio_get_string(struct data_in *din,
 
   if (!enough_data(din, 1)) {
     dest[0] = '\0';
-    return;
+    return FALSE;
   }
 
   remaining = dio_input_remaining(din);
@@ -582,37 +610,40 @@ void dio_get_string(struct data_in *din,
   if (!din->too_short) {
     din->current += (ps_len + 1);	/* past terminator */
   }
+
+  return TRUE;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_bit_string(struct data_in *din, char *dest,
+bool dio_get_bit_string(struct data_in *din, char *dest,
 			size_t max_dest_size)
 {
   int npack = 0;		/* number claimed in packet */
   int i;			/* iterate the bytes */
+  bool retval;
 
   fc_assert(dest != NULL && max_dest_size > 0);
 
   if (!enough_data(din, 1)) {
     dest[0] = '\0';
-    return;
+    return FALSE;
   }
 
-  dio_get_uint16(din, &npack);
+  retval = dio_get_uint16(din, &npack);
   if (npack >= max_dest_size) {
       log_error("Have size for %lu, got %d",
                 (unsigned long) max_dest_size, npack);
     din->bad_bit_string = TRUE;
     dest[0] = '\0';
-    return;
+    return FALSE;
   }
 
   for (i = 0; i < npack;) {
     int bit, byte_value;
 
-    dio_get_uint8(din, &byte_value);
+    retval = dio_get_uint8(din, &byte_value);
     for (bit = 0; bit < 8 && i < npack; bit++, i++) {
       if (TEST_BIT(byte_value, bit)) {
 	dest[i] = '1';
@@ -627,17 +658,20 @@ void dio_get_bit_string(struct data_in *
   if (din->too_short) {
     din->bad_bit_string = TRUE;
   }
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_tech_list(struct data_in *din, int *dest)
+bool dio_get_tech_list(struct data_in *din, int *dest)
 {
   int i;
+  bool retval;
 
   for (i = 0; i < MAX_NUM_TECH_LIST; i++) {
-    dio_get_uint8(din, &dest[i]);
+    retval = dio_get_uint8(din, &dest[i]);
     if (dest[i] == A_LAST) {
       break;
     }
@@ -646,56 +680,66 @@ void dio_get_tech_list(struct data_in *d
   for (; i < MAX_NUM_TECH_LIST; i++) {
     dest[i] = A_LAST;
   }
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_worklist(struct data_in *din, struct worklist *pwl)
+bool dio_get_worklist(struct data_in *din, struct worklist *pwl)
 {
   int i, length;
+  bool retval;
 
   worklist_init(pwl);
 
-  dio_get_uint8(din, &length);
+  retval = dio_get_uint8(din, &length);
   for (i = 0; i < length; i++) {
     int identifier;
     int kind;
 
     dio_get_uint8(din, &kind);
-    dio_get_uint8(din, &identifier);
+    retval = dio_get_uint8(din, &identifier);
 
     worklist_append(pwl, universal_by_number(kind, identifier));
   }
+
+  return retval;
 }
 
 /**************************************************************************
 ...
 **************************************************************************/
-void dio_get_uint8_vec8(struct data_in *din, int **values, int stop_value)
+bool dio_get_uint8_vec8(struct data_in *din, int **values, int stop_value)
 {
   int count, inx;
+  bool retval;
 
-  dio_get_uint8(din, &count);
+  retval = dio_get_uint8(din, &count);
   if (values) {
     *values = fc_calloc((count + 1), sizeof(**values));
   }
   for (inx = 0; inx < count; inx++) {
-    dio_get_uint8(din, values ? &((*values)[inx]) : NULL);
+    retval = dio_get_uint8(din, values ? &((*values)[inx]) : NULL);
   }
   if (values) {
     (*values)[inx] = stop_value;
   }
+
+  return retval;
 }
 
 /**************************************************************************
  Receive vector of uint6 values.
 **************************************************************************/
-void dio_get_uint16_vec8(struct data_in *din, int **values, int stop_value)
+bool dio_get_uint16_vec8(struct data_in *din, int **values, int stop_value)
 {
   int count, inx;
+  bool retval;
+
+  retval = dio_get_uint8(din, &count);
 
-  dio_get_uint8(din, &count);
   if (values) {
     *values = fc_calloc((count + 1), sizeof(**values));
   }
@@ -705,23 +749,28 @@ void dio_get_uint16_vec8(struct data_in 
   if (values) {
     (*values)[inx] = stop_value;
   }
+
+  return retval;
 }
 
 /**************************************************************************
   De-serialize a requirement.
 **************************************************************************/
-void dio_get_requirement(struct data_in *din, struct requirement *preq)
+bool dio_get_requirement(struct data_in *din, struct requirement *preq)
 {
   int type, range, value;
   bool survives, negated;
+  bool retval;
 
   dio_get_uint8(din, &type);
   dio_get_sint32(din, &value);
   dio_get_uint8(din, &range);
   dio_get_bool8(din, &survives);
-  dio_get_bool8(din, &negated);
+  retval = dio_get_bool8(din, &negated);
 
   *preq = req_from_values(type, range, survives, negated, value);
+
+  return retval;
 }
 
 /**************************************************************************
