$NetBSD: patch-php__ext_ming.c,v 1.5 2021/03/07 09:38:58 taca Exp $

Fix build problem if php56 is built with maintainer-zts PKG_OPTION.

--- php_ext/ming.c.orig	2017-04-07 08:12:56.000000000 +0000
+++ php_ext/ming.c
@@ -415,7 +415,7 @@ static SWFInput getInput_fromFileResourc
 	zend_register_resource(input, le_swfinputp);
 #else
 	zend_list_addref(Z_LVAL_P(zfile));
-	zend_list_addref(zend_list_insert(input, le_swfinputp));
+	zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 	return input;
 }
@@ -465,7 +465,7 @@ PHP_METHOD(swfinput, __construct)
 	add_property_resource(getThis(), "input", ret);
 #else
 	object_init_ex(getThis(), input_class_entry_ptr);
-	ret = zend_list_insert(input, le_swfinputp);
+	ret = zend_list_insert(input, le_swfinputp TSRMLS_CC);
 	add_property_resource(getThis(), "input", ret);
 	zend_list_addref(ret);
 #endif
@@ -513,7 +513,7 @@ PHP_METHOD(swffontcollection, __construc
 		add_property_resource(getThis(), "fontcollection", ret);
 #else
 		object_init_ex(getThis(), fontcollection_class_entry_ptr);
-		ret = zend_list_insert(fc, le_swffontcollectionp);
+		ret = zend_list_insert(fc, le_swffontcollectionp TSRMLS_CC);
 		add_property_resource(getThis(), "fontcollection", ret);
 		zend_list_addref(ret);
 #endif
@@ -553,7 +553,7 @@ PHP_METHOD(swffontcollection, getFont)
 		add_property_resource(return_value, "font", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(font, le_swffontp);
+		ret = zend_list_insert(font, le_swffontp TSRMLS_CC);
 		add_property_resource(return_value, "font", ret);
 		zend_list_addref(ret);
 #endif
@@ -614,7 +614,7 @@ PHP_METHOD(swfbrowserfont, __construct)
 		add_property_resource(getThis(), "browserfont", ret);
 #else
 		object_init_ex(getThis(), browserfont_class_entry_ptr);
-		ret = zend_list_insert(font, le_swfbrowserfontp);
+		ret = zend_list_insert(font, le_swfbrowserfontp TSRMLS_CC);
 		add_property_resource(getThis(), "browserfont", ret);
 		zend_list_addref(ret);
 #endif
@@ -673,7 +673,7 @@ PHP_METHOD(swfcxform, __construct)
 	add_property_resource(getThis(), "cx", ret);
 #else
 	object_init_ex(getThis(), cxform_class_entry_ptr);
-	ret = zend_list_insert(cx, le_swfcxformp);
+	ret = zend_list_insert(cx, le_swfcxformp TSRMLS_CC);
 	add_property_resource(getThis(), "cx", ret);
 	zend_list_addref(ret);
 #endif
@@ -856,7 +856,7 @@ PHP_METHOD(swfinitaction, __construct)
 		init = newSWFInitAction_withId(getAction(zaction TSRMLS_CC), id);
 	}
 
-	ret = zend_list_insert(init, le_swfinitactionp);
+	ret = zend_list_insert(init, le_swfinitactionp TSRMLS_CC);
 	object_init_ex(getThis(), initaction_class_entry_ptr);
 	add_property_resource(getThis(), "initaction", ret);
 	zend_list_addref(ret);
@@ -914,7 +914,7 @@ PHP_METHOD(swfaction, __construct)
 	ret = zend_register_resource(action, le_swfactionp);
 	add_property_resource(getThis(), "action", ret);
 #else
-	ret = zend_list_insert(action, le_swfactionp);
+	ret = zend_list_insert(action, le_swfactionp TSRMLS_CC);
 
 	object_init_ex(getThis(), action_class_entry_ptr);
 	add_property_resource(getThis(), "action", ret);
@@ -1000,7 +1000,7 @@ PHP_METHOD(swfbitmap, __construct)
 #if PHP_VERSION_ID >= 70000
 		zend_register_resource(input, le_swfinputp);
 #else
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 		break;
 
@@ -1025,7 +1025,7 @@ PHP_METHOD(swfbitmap, __construct)
 #if PHP_VERSION_ID >= 70000
 			zend_register_resource(maskinput, le_swfinputp);
 #else
-			zend_list_addref(zend_list_insert(maskinput, le_swfinputp));
+			zend_list_addref(zend_list_insert(maskinput, le_swfinputp TSRMLS_CC));
 #endif
 			break;
 
@@ -1042,7 +1042,7 @@ PHP_METHOD(swfbitmap, __construct)
 			add_property_resource(getThis(), "bitmap", ret);
 #else
 			object_init_ex(getThis(), bitmap_class_entry_ptr);
-			ret = zend_list_insert(bitmap_alpha, le_swfbitmapp);
+			ret = zend_list_insert(bitmap_alpha, le_swfbitmapp TSRMLS_CC);
 			add_property_resource(getThis(), "bitmap", ret);
 			zend_list_addref(ret);
 #endif
@@ -1055,7 +1055,7 @@ PHP_METHOD(swfbitmap, __construct)
 			add_property_resource(getThis(), "bitmap", ret);
 #else
 			object_init_ex(getThis(), bitmap_class_entry_ptr);
-			ret = zend_list_insert(bitmap, le_swfbitmapp);
+			ret = zend_list_insert(bitmap, le_swfbitmapp TSRMLS_CC);
 			add_property_resource(getThis(), "bitmap", ret);
 			zend_list_addref(ret);
 #endif
@@ -1325,7 +1325,7 @@ PHP_METHOD(swfbutton, __construct)
 	ret = zend_register_resource(button, le_swfbuttonp);
 	add_property_resource(getThis(), "button", ret);
 #else
-	int ret = zend_list_insert(button, le_swfbuttonp);
+	int ret = zend_list_insert(button, le_swfbuttonp TSRMLS_CC);
 	object_init_ex(getThis(), button_class_entry_ptr);
 	add_property_resource(getThis(), "button", ret);
 	zend_list_addref(ret);
@@ -1472,7 +1472,7 @@ PHP_METHOD(swfbutton, addCharacter)
 		add_property_resource(return_value, "buttonrecord", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(record, le_swfbuttonrecordp);
+		ret = zend_list_insert(record, le_swfbuttonrecordp TSRMLS_CC);
 		add_property_resource(return_value, "buttonrecord", ret);
 		zend_list_addref(ret);
 #endif
@@ -1569,7 +1569,7 @@ PHP_METHOD(swfbutton, addSound)
 		add_property_resource(return_value, "soundinstance", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
 #endif
@@ -2167,7 +2167,7 @@ PHP_METHOD(swfdisplayitem, getMatrix)
 		add_property_resource(return_value, "matrix", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(m, le_swfmatrixp);
+		ret = zend_list_insert(m, le_swfmatrixp TSRMLS_CC);
 		add_property_resource(return_value, "matrix", ret);
 		zend_list_addref(ret);
 #endif
@@ -2198,7 +2198,7 @@ PHP_METHOD(swfdisplayitem, getCharacter)
 		add_property_resource(return_value, "character", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(c, le_swfcharacterp);
+		ret = zend_list_insert(c, le_swfcharacterp TSRMLS_CC);
 		add_property_resource(return_value, "character", ret);
 		zend_list_addref(ret);
 #endif
@@ -2585,7 +2585,7 @@ PHP_METHOD(swffont, __construct)
 		add_property_resource(getThis(), "font", ret);
 #else
 		object_init_ex(getThis(), font_class_entry_ptr);
-		ret = zend_list_insert(font, le_swffontp);
+		ret = zend_list_insert(font, le_swffontp TSRMLS_CC);
 		add_property_resource(getThis(), "font", ret);
 		zend_list_addref(ret);
 #endif
@@ -2795,7 +2795,7 @@ PHP_METHOD(swffiltermatrix, __construct)
 	add_property_resource(getThis(), "filtermatrix", ret);
 #else
 	object_init_ex(getThis(), filtermatrix_class_entry_ptr);
-	ret = zend_list_insert(matrix, le_swffiltermatrixp);
+	ret = zend_list_insert(matrix, le_swffiltermatrixp TSRMLS_CC);
 	add_property_resource(getThis(), "filtermatrix", ret);
 	zend_list_addref(ret);
 #endif
@@ -2853,7 +2853,7 @@ PHP_METHOD(swfshadow, __construct)
 	add_property_resource(getThis(), "shadow", ret);
 #else
 	object_init_ex(getThis(), shadow_class_entry_ptr);
-	ret = zend_list_insert(shadow, le_swfshadowp);
+	ret = zend_list_insert(shadow, le_swfshadowp TSRMLS_CC);
 	add_property_resource(getThis(), "shadow", ret);
 	zend_list_addref(ret);
 #endif
@@ -2912,7 +2912,7 @@ PHP_METHOD(swfblur, __construct)
 	add_property_resource(getThis(), "blur", ret);
 #else
 	object_init_ex(getThis(), blur_class_entry_ptr);
-	ret = zend_list_insert(blur, le_swfblurp);
+	ret = zend_list_insert(blur, le_swfblurp TSRMLS_CC);
 	add_property_resource(getThis(), "blur", ret);
 	zend_list_addref(ret);
 #endif
@@ -2957,7 +2957,7 @@ PHP_METHOD(swfgradient, __construct)
 	zend_resource *ret = zend_register_resource(gradient, le_swfgradientp);
 	add_property_resource(getThis(), "gradient", ret);
 #else
-	int ret = zend_list_insert(gradient, le_swfgradientp);
+	int ret = zend_list_insert(gradient, le_swfgradientp TSRMLS_CC);
 	object_init_ex(getThis(), gradient_class_entry_ptr);
 	add_property_resource(getThis(), "gradient", ret);
 	zend_list_addref(ret);
@@ -3544,7 +3544,7 @@ PHP_METHOD(swffilter, __construct)
 		php_error_docref(NULL TSRMLS_CC, E_ERROR, "new SWFFilter: unknown type");
 	}
 	object_init_ex(getThis(), filter_class_entry_ptr);
-	ret = zend_list_insert(filter, le_swffilterp);
+	ret = zend_list_insert(filter, le_swffilterp TSRMLS_CC);
 	add_property_resource(getThis(), "filter", ret);
 	zend_list_addref(ret);
 #endif
@@ -3591,7 +3591,7 @@ PHP_METHOD(swfmorph, __construct)
 	zend_resource *ret = zend_register_resource(morph, le_swfmorphp);
 	add_property_resource(getThis(), "morph", ret);
 #else
-	int ret = zend_list_insert(morph, le_swfmorphp);
+	int ret = zend_list_insert(morph, le_swfmorphp TSRMLS_CC);
 	object_init_ex(getThis(), morph_class_entry_ptr);
 	add_property_resource(getThis(), "morph", ret);
 	zend_list_addref(ret);
@@ -3635,7 +3635,7 @@ PHP_METHOD(swfmorph, getShape1)
 #else
 	SWFMorph morph = getMorph(getThis() TSRMLS_CC);
 	SWFShape shape = SWFMorph_getShape1(morph);
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 	object_init_ex(return_value, shape_class_entry_ptr);
 	add_property_resource(return_value, "shape", ret);
 	zend_list_addref(ret);
@@ -3657,7 +3657,7 @@ PHP_METHOD(swfmorph, getShape2)
 #else
 	SWFMorph morph = getMorph(getThis() TSRMLS_CC);
 	SWFShape shape = SWFMorph_getShape2(morph);
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 	object_init_ex(return_value, shape_class_entry_ptr);
 	add_property_resource(return_value, "shape", ret);
 	zend_list_addref(ret);
@@ -3708,7 +3708,7 @@ PHP_METHOD(swfsoundstream, __construct)
 #if PHP_VERSION_ID >= 70000
 		zend_register_resource(input, le_swfinputp);
 #else
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 		break;
 
@@ -3725,7 +3725,7 @@ PHP_METHOD(swfsoundstream, __construct)
 		add_property_resource(getThis(), "soundstream", ret);
 #else
 		object_init_ex(getThis(), soundstream_class_entry_ptr);
-		ret = zend_list_insert(sound, le_swfsoundstreamp);
+		ret = zend_list_insert(sound, le_swfsoundstreamp TSRMLS_CC);
 		add_property_resource(getThis(), "soundstream", ret);
 		zend_list_addref(ret);
 #endif
@@ -3851,7 +3851,7 @@ PHP_METHOD(swfsound, __construct)
 #if PHP_VERSION_ID >= 70000
 			zend_register_resource(input, le_swfinputp);
 #else
-			zend_list_addref(zend_list_insert(input, le_swfinputp));
+			zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 			break;
 
@@ -3869,7 +3869,7 @@ PHP_METHOD(swfsound, __construct)
 		add_property_resource(getThis(), "sound", ret);
 #else
 		object_init_ex(getThis(), sound_class_entry_ptr);
-		ret = zend_list_insert(sound, le_swfsoundp);
+		ret = zend_list_insert(sound, le_swfsoundp TSRMLS_CC);
 		add_property_resource(getThis(), "sound", ret);
 		zend_list_addref(ret);
 #endif
@@ -4016,7 +4016,7 @@ PHP_METHOD(swfvideostream, __construct)
 #if PHP_VERSION_ID >= 70000
 			zend_register_resource(input, le_swfinputp);
 #else
-			zend_list_addref(zend_list_insert(input, le_swfinputp));
+			zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 			break;
 
@@ -4039,7 +4039,7 @@ PHP_METHOD(swfvideostream, __construct)
 		add_property_resource(getThis(), "videostream", ret);
 #else
 		object_init_ex(getThis(), videostream_class_entry_ptr);
-		ret = zend_list_insert(stream, le_swfvideostreamp);
+		ret = zend_list_insert(stream, le_swfvideostreamp TSRMLS_CC);
 		add_property_resource(getThis(), "videostream", ret);
 		zend_list_addref(ret);
 #endif
@@ -4202,7 +4202,7 @@ PHP_METHOD(swfbinarydata, __construct)
 		add_property_resource(getThis(), "binarydata", ret);
 #else
 		object_init_ex(getThis(), binarydata_class_entry_ptr);
-		ret = zend_list_insert(bd, le_swfbinarydatap);
+		ret = zend_list_insert(bd, le_swfbinarydatap TSRMLS_CC);
 		add_property_resource(getThis(), "binarydata", ret);
 		zend_list_addref(ret);
 #endif
@@ -4271,7 +4271,7 @@ PHP_METHOD(swfprebuiltclip, __construct)
 #if PHP_VERSION_ID >= 70000
 		zend_register_resource(input, le_swfinputp);
 #else
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 		break;
 
@@ -4288,7 +4288,7 @@ PHP_METHOD(swfprebuiltclip, __construct)
 		add_property_resource(getThis(), "prebuiltclip", ret);
 #else
 		object_init_ex(getThis(), prebuiltclip_class_entry_ptr);
-		ret = zend_list_insert(clip, le_swfprebuiltclipp);
+		ret = zend_list_insert(clip, le_swfprebuiltclipp TSRMLS_CC);
 		add_property_resource(getThis(), "prebuiltclip", ret);
 		zend_list_addref(ret);
 #endif
@@ -4354,7 +4354,7 @@ PHP_METHOD(swfmovie, __construct)
 	add_property_resource(getThis(), "movie", ret);
 #else
 	object_init_ex(getThis(), movie_class_entry_ptr);
-	ret = zend_list_insert(movie, le_swfmoviep);
+	ret = zend_list_insert(movie, le_swfmoviep TSRMLS_CC);
 
 	add_property_resource(getThis(), "movie", ret);
 	zend_list_addref(ret);
@@ -4480,7 +4480,7 @@ PHP_METHOD(swfmovie, add)
 		add_property_resource(return_value, "displayitem", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(item, le_swfdisplayitemp);
+		ret = zend_list_insert(item, le_swfdisplayitemp TSRMLS_CC);
 		add_property_resource(return_value, "displayitem", ret);
 		zend_list_addref(ret);
 #endif
@@ -4863,7 +4863,7 @@ PHP_METHOD(swfmovie, streamMP3)
 #if PHP_VERSION_ID >= 70000
 		zend_register_resource(input, le_swfinputp);
 #else
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 		break;
 
@@ -4958,7 +4958,7 @@ PHP_METHOD(swfmovie, startSound)
 		add_property_resource(return_value, "soundinstance", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
 #endif
@@ -5010,7 +5010,7 @@ PHP_METHOD(swfmovie, importChar)
 		add_property_resource(return_value, "character", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(character, le_swfcharacterp);
+		ret = zend_list_insert(character, le_swfcharacterp TSRMLS_CC);
 		add_property_resource(return_value, "character", ret);
 		zend_list_addref(ret);
 #endif
@@ -5048,7 +5048,7 @@ PHP_METHOD(swfmovie, importFont)
 		add_property_resource(return_value, "fontcharacter", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(res, le_swffontcharp);
+		ret = zend_list_insert(res, le_swffontcharp TSRMLS_CC);
 		add_property_resource(return_value, "fontcharacter", ret);
 		zend_list_addref(ret);
 #endif
@@ -5085,7 +5085,7 @@ PHP_METHOD(swfmovie, addFont)
 		add_property_resource(return_value, "fontcharacter", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(res, le_swffontcharp);
+		ret = zend_list_insert(res, le_swffontcharp TSRMLS_CC);
 		add_property_resource(return_value, "fontcharacter", ret);
 		zend_list_addref(ret);
 #endif
@@ -5174,7 +5174,7 @@ PHP_METHOD(swfshape, __construct)
 	zend_resource *ret = zend_register_resource(shape, le_swfshapep);
 	add_property_resource(getThis(), "shape", ret);
 #else
-	int ret = zend_list_insert(shape, le_swfshapep);
+	int ret = zend_list_insert(shape, le_swfshapep TSRMLS_CC);
 	object_init_ex(getThis(), shape_class_entry_ptr);
 	add_property_resource(getThis(), "shape", ret);
 	zend_list_addref(ret);
@@ -5254,7 +5254,7 @@ PHP_METHOD(swfshape, addSolidFill)
 	add_property_resource(return_value, "fill", ret);
 	ret->gc.refcount++;
 #else
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
 #endif
@@ -5307,7 +5307,7 @@ PHP_METHOD(swfshape, addBitmapFill)
 	add_property_resource(return_value, "fill", ret);
 	ret->gc.refcount++;
 #else
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
 #endif
@@ -5363,7 +5363,7 @@ PHP_METHOD(swfshape, addGradientFill)
 	add_property_resource(return_value, "fill", ret);
 	ret->gc.refcount++;
 #else
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
 #endif
@@ -5428,7 +5428,7 @@ PHP_METHOD(swfshape, addFill)
 	add_property_resource(return_value, "fill", ret);
 	ret->gc.refcount++;
 #else
-	ret = zend_list_insert(fill, le_swffillp);
+	ret = zend_list_insert(fill, le_swffillp TSRMLS_CC);
 	add_property_resource(return_value, "fill", ret);
 	zend_list_addref(ret);
 #endif
@@ -5927,7 +5927,7 @@ PHP_METHOD(swfsprite, __construct)
 
 	add_property_resource(getThis(), "sprite", ret);
 #else
-	int ret = zend_list_insert(sprite, le_swfspritep);
+	int ret = zend_list_insert(sprite, le_swfspritep TSRMLS_CC);
 
 	object_init_ex(getThis(), sprite_class_entry_ptr);
 	add_property_resource(getThis(), "sprite", ret);
@@ -5992,7 +5992,7 @@ PHP_METHOD(swfsprite, add)
 		add_property_resource(return_value, "displayitem", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(item, le_swfdisplayitemp);
+		ret = zend_list_insert(item, le_swfdisplayitemp TSRMLS_CC);
 		add_property_resource(return_value, "displayitem", ret);
 		zend_list_addref(ret);
 #endif
@@ -6085,7 +6085,7 @@ PHP_METHOD(swfsprite, startSound)
 		add_property_resource(return_value, "soundinstance", ret);
 		ret->gc.refcount++;
 #else
-		ret = zend_list_insert(item, le_swfsoundinstancep);
+		ret = zend_list_insert(item, le_swfsoundinstancep TSRMLS_CC);
 		add_property_resource(return_value, "soundinstance", ret);
 		zend_list_addref(ret);
 #endif
@@ -6146,7 +6146,7 @@ PHP_METHOD(swfsprite, setSoundStream)
 #if PHP_VERSION_ID >= 70000
 		zend_register_resource(input, le_swfinputp);
 #else
-		zend_list_addref(zend_list_insert(input, le_swfinputp));
+		zend_list_addref(zend_list_insert(input, le_swfinputp TSRMLS_CC));
 #endif
 		break;
 
@@ -6272,7 +6272,7 @@ PHP_METHOD(swftext, __construct)
 	zend_resource *ret = zend_register_resource(text, le_swftextp);
 	add_property_resource(getThis(), "text", ret);
 #else
-	int ret = zend_list_insert(text, le_swftextp);
+	int ret = zend_list_insert(text, le_swftextp TSRMLS_CC);
 	object_init_ex(getThis(), text_class_entry_ptr);
 	add_property_resource(getThis(), "text", ret);
 	zend_list_addref(ret);
@@ -6555,7 +6555,7 @@ PHP_METHOD(swftextfield, __construct)
 
 	add_property_resource(getThis(), "textfield", ret);
 #else
-	int ret = zend_list_insert(field, le_swftextfieldp);
+	int ret = zend_list_insert(field, le_swftextfieldp TSRMLS_CC);
 
 	object_init_ex(getThis(), textfield_class_entry_ptr);
 	add_property_resource(getThis(), "textfield", ret);
