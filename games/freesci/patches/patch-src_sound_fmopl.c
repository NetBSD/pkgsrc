$NetBSD: patch-src_sound_fmopl.c,v 1.1 2012/07/03 18:41:58 joerg Exp $

--- src/sound/fmopl.c.orig	2012-07-03 15:42:31.000000000 +0000
+++ src/sound/fmopl.c
@@ -380,7 +380,7 @@ INLINE void CALC_FCSLOT(OPL_CH *CH, OPL_
 }
 
 /* set multi,am,vib,EG-TYP,KSR,mul */
-INLINE void set_mul(FM_OPL *OPL, int slot, int v) {
+static INLINE void set_mul(FM_OPL *OPL, int slot, int v) {
 	OPL_CH   *CH   = &OPL->P_CH[slot / 2];
 	OPL_SLOT *SLOT = &CH->SLOT[slot & 1];
 
@@ -443,7 +443,7 @@ INLINE void set_sl_rr(FM_OPL *OPL, int s
 /* operator output calcrator */
 #define OP_OUT(slot,env,con)   slot->wavetable[((slot->Cnt + con) / (0x1000000 / SIN_ENT)) & (SIN_ENT-1)][env]
 /* ---------- calcrate one of channel ---------- */
-INLINE void OPL_CALC_CH(OPL_CH *CH) {
+static INLINE void OPL_CALC_CH(OPL_CH *CH) {
 	guint32 env_out;
 	OPL_SLOT *SLOT;
 
@@ -486,7 +486,7 @@ INLINE void OPL_CALC_CH(OPL_CH *CH) {
 
 /* ---------- calcrate rythm block ---------- */
 #define WHITE_NOISE_db 6.0
-INLINE void OPL_CALC_RH(OPL_CH *CH) {
+static INLINE void OPL_CALC_RH(OPL_CH *CH) {
 	guint32 env_tam, env_sd, env_top, env_hh;
 	int whitenoise = (int)((rand()&1) * (WHITE_NOISE_db / EG_STEP));
 	int tone8;
