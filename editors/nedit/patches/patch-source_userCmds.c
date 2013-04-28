$NetBSD: patch-source_userCmds.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc warnings about unsafe pointer casts.
Call <ctype.h> functions correctly.

--- source/userCmds.c~	2004-09-02 08:50:38.000000000 +0000
+++ source/userCmds.c
@@ -1116,7 +1116,7 @@ static void dimSelDepItemsInMenu(Widget 
 	    	XtVaGetValues(items[n], XmNsubMenuId, &subMenu, NULL);
 		dimSelDepItemsInMenu(subMenu, menuList, nMenuItems, sensitive);
 	    } else {
-		index = (int)userData - 10;
+		index = (intptr_t)userData - 10;
 		if (index <0 || index >= nMenuItems)
     		    return;
 		if (menuList[index]->input == FROM_SELECTION)
@@ -2864,7 +2864,7 @@ static void generateAcceleratorString(ch
     /* for a consistent look to the accelerator names in the menus,
        capitalize the first letter of the keysym */
     strcpy(keyName, XKeysymToString(keysym));
-    *keyName = toupper(*keyName);
+    *keyName = toupper((unsigned char)*keyName);
     
     /* concatenate the strings together */
     sprintf(text, "%s%s%s%s%s%s%s%s", shiftStr, ctrlStr, altStr, 
@@ -2946,7 +2946,7 @@ static int parseAcceleratorString(const 
        of the keysyms are "prettied up" by generateAcceleratorString */
     *keysym = XStringToKeysym(fields[nFields-1]);
     if (*keysym == NoSymbol) {
-    	*fields[nFields-1] = tolower(*fields[nFields-1]);
+    	*fields[nFields-1] = tolower((unsigned char)*fields[nFields-1]);
     	*keysym = XStringToKeysym(fields[nFields-1]);
     	if (*keysym == NoSymbol)
     	    return False;
