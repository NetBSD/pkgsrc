$NetBSD: patch-ext_ext.c,v 1.1 2017/04/14 21:35:34 minskim Exp $

--- ext/ext.c.orig	2007-03-23 11:21:39.000000000 +0000
+++ ext/ext.c
@@ -334,7 +334,7 @@ c_write (int argc, VALUE *argv, VALUE se
 	cbuf = StringValuePtr (buf);
 
 	n = eet_write (*ef, ckey,
-	               cbuf, RSTRING (buf)->len,
+	               cbuf, RSTRING_LENINT(buf),
 	               comp == Qtrue);
 	if (!n)
 		rb_raise (rb_eIOError, "couldn't write to file");
@@ -445,7 +445,7 @@ c_write_image (int argc, VALUE *argv, VA
 			quality = FIX2INT (tmp);
 	}
 
-	if (!RSTRING (buf)->len)
+	if (!RSTRING_LEN(buf))
 		return INT2FIX (0);
 
 	n = eet_data_image_write (*ef, ckey, cbuf,
@@ -472,8 +472,8 @@ chunk_init (VALUE self, VALUE tag, VALUE
 	/* libeet uses a signed 32bit integer to store the
 	 * chunk size, so make sure we don't overflow it
 	 */
-	tag_len = RSTRING (tag)->len;
-	data_len = RSTRING (data)->len;
+	tag_len = RSTRING_LEN(tag);
+	data_len = RSTRING_LEN(data);
 	tmp = tag_len + 1 + data_len;
 
 	if (tmp < tag_len || tmp < data_len || tmp < 1 || tmp >= 2147483647L)
@@ -499,26 +499,25 @@ chunk_to_s (VALUE self)
 	tmp = rb_ivar_get (self, id_data);
 	data = RSTRING (tmp);
 
-	buf_len = 9 + tag->len + data->len;
+	buf_len = 9 + RSTRING_LENINT(tag) + RSTRING_LENINT(data);
 	ret = rb_str_buf_new (buf_len);
 
-	buf = (unsigned char *) RSTRING (ret)->ptr;
-	RSTRING (ret)->len = buf_len;
+	buf = (unsigned char *) RSTRING_PTR(ret);
 
 	memcpy (buf, "CHnK", 4);
 	buf += 4;
 
-	size = tag->len + data->len + 1;
+	size = RSTRING_LENINT(tag) + RSTRING_LENINT(data) + 1;
 	size = BSWAP32 (size);
 	memcpy (buf, &size, 4);
 	buf += 4;
 
-	memcpy (buf, tag->ptr, tag->len);
-	buf += tag->len;
+	memcpy (buf, RSTRING_PTR(tag), RSTRING_LEN(tag));
+	buf += RSTRING_LEN(tag);
 
 	*buf++ = 0;
 
-	memcpy (buf, data->ptr, data->len);
+	memcpy (buf, RSTRING_PTR(data), RSTRING_LEN(data));
 
 	return ret;
 }
@@ -561,13 +560,13 @@ c_to_eet (VALUE self)
 	props = rb_funcall (self, id_to_eet_properties, 0);
 
 	if (rb_obj_is_kind_of (props, rb_cHash) == Qfalse ||
-	    !RHASH (props)->tbl->num_entries)
+	    !RHASH_TBL(props)->num_entries)
 		rb_raise (ePropError, "invalid EET properties");
 
 	name = rb_funcall (self, id_to_eet_name, 0);
 	StringValue (name);
 
-	if (!RSTRING (name)->len ||
+	if (!RSTRING_LEN(name) ||
 	    rb_funcall (name, id_include, 1, INT2FIX (0)))
 		rb_raise (eNameError, "invalid EET name");
 
@@ -578,9 +577,9 @@ c_to_eet (VALUE self)
 #else
 	keys = RARRAY (rb_funcall (props, id_keys, 0));
 
-	for (i = 0; i < keys->len; i++)
-		for_each_prop (keys->ptr[i],
-		               rb_hash_aref (props, keys->ptr[i]),
+	for (i = 0; i < RARRAY_LENINT(keys); i++)
+		for_each_prop (RARRAY_PTR(keys)[i],
+		               rb_hash_aref (props, RARRAY_PTR(keys)[i]),
 		               stream);
 #endif
 
