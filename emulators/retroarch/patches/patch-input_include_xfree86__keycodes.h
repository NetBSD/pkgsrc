$NetBSD: patch-input_include_xfree86__keycodes.h,v 1.1 2019/05/18 14:58:53 nia Exp $

Support non-evdev special keys...

--- input/include/xfree86_keycodes.h.orig	2019-05-08 06:06:23.000000000 +0000
+++ input/include/xfree86_keycodes.h
@@ -101,8 +101,8 @@ enum xfvk_key
    XFVK_LALT           = 64,
    XFVK_LCTL           = 37,
    XFVK_SPCE           = 65,
-   XFVK_RCTL           = 105,
-   XFVK_RALT           = 108,
+   XFVK_RCTL           = 109,
+   XFVK_RALT           = 113,
 
    XFVK_PRSC           = 107,
    /* SYRQ                = 107, */
@@ -110,20 +110,20 @@ enum xfvk_key
    XFVK_PAUS           = 127,
    /* BRK                 = 419, */
 
-   XFVK_INS            = 118,
-   XFVK_HOME           = 110,
-   XFVK_PGUP           = 112,
-   XFVK_DELE           = 119,
-   XFVK_END            = 115,
-   XFVK_PGDN           = 117,
-
-   XFVK_UP             = 111,
-   XFVK_LEFT           = 113,
-   XFVK_DOWN           = 116,
-   XFVK_RGHT           = 114,
+   XFVK_INS            = 106,
+   XFVK_HOME           = 97,
+   XFVK_PGUP           = 99,
+   XFVK_DELE           = 107,
+   XFVK_END            = 103,
+   XFVK_PGDN           = 105,
+
+   XFVK_UP             = 98,
+   XFVK_LEFT           = 100,
+   XFVK_DOWN           = 104,
+   XFVK_RGHT           = 102,
 
    XFVK_NMLK           = 77,
-   XFVK_KPDV           = 106,
+   XFVK_KPDV           = 112,
    XFVK_KPMU           = 63,
    XFVK_KPSU           = 82,
 
@@ -139,26 +139,26 @@ enum xfvk_key
    XFVK_KP1            = 87,
    XFVK_KP2            = 88,
    XFVK_KP3            = 89,
-   XFVK_KPEN           = 104,
+   XFVK_KPEN           = 108,
 
    XFVK_KP0            = 90,
    XFVK_KPDL           = 91,
-   XFVK_KPEQ           = 125,
+   XFVK_KPEQ           = 126,
 
    /* Microsoft keyboard extra keys */
-   XFVK_LWIN           = 133,
-   XFVK_RWIN           = 134,
+   XFVK_LWIN           = 115,
+   XFVK_RWIN           = 116,
    XFVK_COMP           = 135,
-   XFVK_MENU           = XFVK_COMP,
+   XFVK_MENU           = 117,
 
    /* Extended keys */
    XFVK_CALC           = 148,
 
-   XFVK_FK13           = 191,
-   XFVK_FK14           = 192,
-   XFVK_FK15           = 193,
-   XFVK_FK16           = 194,
-   XFVK_FK17           = 195,
+   XFVK_FK13           = 118,
+   XFVK_FK14           = 119,
+   XFVK_FK15           = 120,
+   XFVK_FK16           = 121,
+   XFVK_FK17           = 122,
    XFVK_FK18           = 196,
    XFVK_FK19           = 197,
    XFVK_FK20           = 198,
