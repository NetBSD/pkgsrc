$NetBSD: patch-unix_xserver_hw_vnc_InputXKB.cc,v 1.2 2015/07/21 21:51:39 markd Exp $

--- unix/xserver/hw/vnc/InputXKB.c.orig	2015-07-11 13:00:36.000000000 +0000
+++ unix/xserver/hw/vnc/InputXKB.c
@@ -212,7 +212,7 @@ unsigned vncGetKeyboardState(void)
 {
 	DeviceIntPtr master;
 
-	master = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT);
+	master = vncKeyboardDev->master;
 	return XkbStateFieldFromRec(&master->key->xkbInfo->state);
 }
 
@@ -234,7 +234,7 @@ unsigned vncGetLevelThreeMask(void)
 			return 0;
 	}
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 
 	act = XkbKeyActionPtr(xkb, keycode, state);
 	if (act == NULL)
@@ -259,7 +259,7 @@ KeyCode vncPressShift(void)
 	if (state & ShiftMask)
 		return 0;
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 	for (key = xkb->min_key_code; key <= xkb->max_key_code; key++) {
 		XkbAction *act;
 		unsigned char mask;
@@ -299,7 +299,7 @@ size_t vncReleaseShift(KeyCode *keys, si
 
 	count = 0;
 
-	master = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT);
+	master = vncKeyboardDev->master;
 	xkb = master->key->xkbInfo->desc;
 	for (key = xkb->min_key_code; key <= xkb->max_key_code; key++) {
 		XkbAction *act;
@@ -355,7 +355,7 @@ KeyCode vncPressLevelThree(void)
 			return 0;
 	}
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 
 	act = XkbKeyActionPtr(xkb, keycode, state);
 	if (act == NULL)
@@ -386,7 +386,7 @@ size_t vncReleaseLevelThree(KeyCode *key
 
 	count = 0;
 
-	master = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT);
+	master = vncKeyboardDev->master;
 	xkb = master->key->xkbInfo->desc;
 	for (key = xkb->min_key_code; key <= xkb->max_key_code; key++) {
 		XkbAction *act;
@@ -429,7 +429,7 @@ KeyCode vncKeysymToKeycode(KeySym keysym
 	if (new_state != NULL)
 		*new_state = state;
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 	for (key = xkb->min_key_code; key <= xkb->max_key_code; key++) {
 		unsigned int state_out;
 		KeySym dummy;
@@ -486,7 +486,7 @@ int vncIsLockModifier(KeyCode keycode, u
 	XkbDescPtr xkb;
 	XkbAction *act;
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 
 	act = XkbKeyActionPtr(xkb, keycode, state);
 	if (act == NULL)
@@ -524,7 +524,7 @@ int vncIsAffectedByNumLock(KeyCode keyco
 	if (numlock_keycode == 0)
 		return 0;
 
-	xkb = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT)->key->xkbInfo->desc;
+	xkb = vncKeyboardDev->master->key->xkbInfo->desc;
 
 	act = XkbKeyActionPtr(xkb, numlock_keycode, state);
 	if (act == NULL)
@@ -558,7 +558,7 @@ KeyCode vncAddKeysym(KeySym keysym, unsi
 	KeySym *syms;
 	KeySym upper, lower;
 
-	master = GetMaster(vncKeyboardDev, KEYBOARD_OR_FLOAT);
+	master = vncKeyboardDev->master;
 	xkb = master->key->xkbInfo->desc;
 	for (key = xkb->max_key_code; key >= xkb->min_key_code; key--) {
 		if (XkbKeyNumGroups(xkb, key) == 0)
