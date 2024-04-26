$NetBSD: patch-frontend_menu.c,v 1.1 2024/04/26 09:10:10 nia Exp $

NetBSD support.

--- frontend/menu.c.orig	2024-04-16 09:44:07.524301796 +0000
+++ frontend/menu.c
@@ -29,7 +29,6 @@
 #include "cspace.h"
 #include "libpicofe/plat.h"
 #include "libpicofe/input.h"
-#include "libpicofe/linux/in_evdev.h"
 #include "libpicofe/plat.h"
 #include "../libpcsxcore/misc.h"
 #include "../libpcsxcore/cdrom.h"
@@ -42,6 +41,10 @@
 #include "arm_features.h"
 #include "revision.h"
 
+#ifndef __linux
+#define stat64 stat
+#endif
+
 #define REARMED_BIRTHDAY_TIME 1293306830	/* 25 Dec 2010 */
 
 #define array_size(x) (sizeof(x) / sizeof(x[0]))
@@ -317,10 +320,6 @@ static void menu_sync_config(void)
 	case 2:  in_type2 = PSE_PAD_TYPE_GUNCON;    break;
 	default: in_type2 = PSE_PAD_TYPE_STANDARD;
 	}
-	if (in_evdev_allow_abs_only != allow_abs_only_old) {
-		in_probe();
-		allow_abs_only_old = in_evdev_allow_abs_only;
-	}
 
 	spu_config.iVolume = 768 + 128 * volume_boost;
 	pl_rearmed_cbs.frameskip = frameskip - 1;
@@ -346,7 +345,6 @@ static void menu_set_defconfig(void)
 
 	region = 0;
 	in_type_sel1 = in_type_sel2 = 0;
-	in_evdev_allow_abs_only = 0;
 
 	menu_sync_config();
 }
@@ -457,7 +455,6 @@ static const struct {
 	CE_INTVAL(spu_config.iTempo),
 	CE_INTVAL(spu_config.iUseThread),
 	CE_INTVAL(config_save_counter),
-	CE_INTVAL(in_evdev_allow_abs_only),
 	CE_INTVAL(volume_boost),
 	CE_INTVAL(psx_clock),
 	CE_INTVAL(new_dynarec_hacks),
@@ -1215,7 +1212,6 @@ static menu_entry e_menu_keyconfig[] =
 	mee_label     (""),
 	mee_enum      ("Port 1 device",     0, in_type_sel1,    men_in_type_sel),
 	mee_enum      ("Port 2 device",     0, in_type_sel2,    men_in_type_sel),
-	mee_onoff_h   ("Nubs as buttons",   MA_CTRL_NUBS_BTNS,  in_evdev_allow_abs_only, 1, h_nub_btns),
 	mee_onoff_h   ("Vibration",         MA_CTRL_VIBRATION,  in_enable_vibration, 1, h_vibration),
 	mee_range     ("Analog deadzone",   MA_CTRL_DEADZONE,   analog_deadzone, 1, 99),
 	mee_onoff_h   ("No TS Gun trigger", 0, g_opts, OPT_TSGUN_NOTRIGGER, h_notsgun),
