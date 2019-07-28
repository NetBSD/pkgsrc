$NetBSD: patch-Source_inv.cpp,v 1.1 2019/07/28 10:26:43 nia Exp $

[PATCH] Clean up CheckInvPaste (bin exact) (#1205)
Fixes some item duplication.
https://github.com/diasurgical/devilutionX/commit/a549d5ebc461e757065c4536cb351969dcf60fe9.patch

--- Source/inv.cpp.orig	2019-05-19 17:06:45.000000000 +0000
+++ Source/inv.cpp
@@ -686,562 +686,408 @@ int SwapItem(ItemStruct *a, ItemStruct *
 
 void CheckInvPaste(int pnum, int mx, int my)
 {
-	int v3;              // ebx
-	int v4;              // edi
-	int v5;              // eax
-	int v6;              // esi
-	signed int v7;       // edi
-	int v8;              // edx
-	int v9;              // edx
-	signed int v10;      // edi
-	char v11;            // al
-	signed int v12;      // ecx
-	int v13;             // eax
-	int v14;             // eax
-	char *v15;           // edi
-	int v16;             // esi
-	int v17;             // ecx
-	int v18;             // edx
-	int v21;             // esi
-	ItemStruct *v22;     // edi
-	ItemStruct *v23;     // ecx
-	int v24;             // eax
-	int v25;             // eax
-	int v26;             // edx
-	ItemStruct *v27;     // esi
-	int v28;             // eax
-	int v29;             // ecx
-	int v30;             // esi
-	int v31;             // eax
-	int v32;             // eax
-	int v33;             // ecx
-	int v34;             // eax
-	int v35;             // ecx
-	char *v36;           // eax
-	int v37;             // edx
-	int v38;             // ecx
-	int v39;             // edi
-	int v40;             // esi
-	int v41;             // ebx
-	int v42;             // edx
-	int v43;             // eax
-	int v44;             // eax
-	signed int v45;      // ecx
-	int v46;             // edx
-	char *v47;           // eax
-	int v48;             // edi
-	int v49;             // eax
-	int v50;             // ecx
-	char *v51;           // esi
-	char v52;            // cl
-	int v53;             // ecx
-	int v54;             // eax
-	int v55;             // edi
-	int v56;             // edx
-	int v57;             // esi
-	int v58;             // ebx
-	int v59;             // eax
-	int v60;             // esi
-	ItemStruct tempitem; // [esp+Ch] [ebp-190h]
-	int v62;             // [esp+17Ch] [ebp-20h]
-	int p;               // [esp+180h] [ebp-1Ch]
-	int v64;             // [esp+184h] [ebp-18h]
-	int v65;             // [esp+188h] [ebp-14h]
-	int v66;             // [esp+18Ch] [ebp-10h]
-	int v67;             // [esp+190h] [ebp-Ch]
-	int v68;             // [esp+194h] [ebp-8h]
-	int v69;             // [esp+198h] [ebp-4h]
-	int cursor_id;       // [esp+1A4h] [ebp+8h]
-	int cursor_ida;      // [esp+1A4h] [ebp+8h]
-
-	p = pnum;
-	v3 = pnum;
-	v4 = mx;
+	int r, sx, sy;
+	int i, j, xx, yy, ii;
+	BOOL done, done2h;
+	int il, cn, it, iv, ig, gt;
+	ItemStruct tempitem;
+
 	SetICursor(plr[pnum].HoldItem._iCurs + CURSOR_FIRSTITEM);
-	v5 = my + (icursH >> 1);
-	v6 = v4 + (icursW >> 1);
-	v64 = icursW28;
-	v7 = 0;
-	v67 = icursH28;
-	v68 = 0;
-	do {
-		if (v7)
-			goto LABEL_18;
-		v8 = InvRect[v68].X;
-		if (v6 >= v8 && v6 < v8 + 28) {
-			v9 = InvRect[v68].Y;
-			if (v5 >= v9 - 29 && v5 < v9) {
-				v7 = 1;
-				--v68;
-			}
-		}
-		if (v68 != 24)
-			goto LABEL_13;
-		if (!(v64 & 1))
-			v6 -= 14;
-		if (!(v67 & 1)) {
-			v5 -= 14;
-		LABEL_13:
-			if (v68 == 64 && !(v67 & 1))
-				v5 += 14;
-		}
-		++v68;
-	} while ((unsigned int)v68 < 0x49);
-	if (!v7)
+	i = mx + (icursW >> 1);
+	j = my + (icursH >> 1);
+	sx = icursW28;
+	sy = icursH28;
+	done = FALSE;
+	for (r = 0; r < sizeof(InvRect) / sizeof(InvRect[0]) && !done; r++) {
+		if (i >= InvRect[r].X && i < InvRect[r].X + INV_SLOT_SIZE_PX) {
+			if (j >= InvRect[r].Y - INV_SLOT_SIZE_PX - 1 && j < InvRect[r].Y) {
+				done = TRUE;
+				r--;
+			}
+		}
+		if (r == 24) {
+			if ((sx & 1) == 0)
+				i -= 14;
+			if ((sy & 1) == 0) {
+				j -= 14;
+			}
+		}
+		if (r == 64 && (sy & 1) == 0)
+			j += 14;
+	}
+	if (!done)
 		return;
-LABEL_18:
-	v10 = v68;
-	v69 = ILOC_UNEQUIPABLE;
-	if (v68 >= 0 && v68 <= ILOC_ARMOR)
-		v69 = ILOC_HELM;
-	if (v68 >= ILOC_HELM && v68 <= ILOC_RING)
-		v69 = ILOC_RING;
-	if (v68 == ILOC_AMULET)
-		v69 = ILOC_AMULET;
-	if (v68 >= ILOC_UNEQUIPABLE && v68 <= 18)
-		v69 = ILOC_ONEHAND;
-	if (v68 >= 19 && v68 <= 24)
-		v69 = ILOC_ARMOR;
-	if (v68 >= 65 && v68 <= 72)
-		v69 = ILOC_BELT;
-	v11 = plr[v3].HoldItem._iLoc;
-	v12 = 0;
-	if ((char)v11 == v69)
-		v12 = 1;
-	if (v69 == 1 && v11 == ILOC_TWOHAND) {
-		v69 = ILOC_TWOHAND;
-		v12 = 1;
-	}
-	if (v11 != 7 || v69 != ILOC_BELT) {
-	LABEL_50:
-		if (v69 != ILOC_UNEQUIPABLE)
-			goto LABEL_81;
-		v66 = 0;
-		cursor_id = 1;
-		v13 = (v68 - 25) / 10;
-		if (plr[v3].HoldItem._itype == ITYPE_GOLD) {
-			_LOBYTE(v13) = plr[0].InvGrid[10 * v13 + v3 * 21720 + (v68 - 25) % 10];
-			if (!(_BYTE)v13)
-				goto LABEL_93;
-			v13 = (char)v13;
-			if ((char)v13 <= 0) {
-				v13 = -v13;
-			} else if (*(int *)((char *)&plr[0].InvBody[v13 + 6]._itype + v3 * 21720) == ITYPE_GOLD) {
-				goto LABEL_93;
-			}
-			v66 = v13;
-		LABEL_93:
-			v21 = p;
-			if (p == myplr) {
-				PlaySFX(ItemInvSnds[ItemCAnimTbl[plr[v3].HoldItem._iCurs]]);
-				v10 = v68;
-			}
-			cursor_ida = 1;
-			switch (v69) {
-			case ILOC_ONEHAND:
-				if (v10 > 12) {
-					if (plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_NONE) {
-						v25 = plr[v3].InvBody[INVLOC_HAND_LEFT]._itype;
-						if (v25 == ITYPE_NONE)
-							goto LABEL_232;
-						if (plr[v3].InvBody[INVLOC_HAND_LEFT]._iLoc == ILOC_TWOHAND) {
-							NetSendCmdDelItem(FALSE, 4u);
-							NetSendCmdChItem(FALSE, 5u);
-							SwapItem(&plr[v3].InvBody[INVLOC_HAND_RIGHT], &plr[v3].InvBody[INVLOC_HAND_LEFT]);
-							v23 = &plr[v3].InvBody[INVLOC_HAND_RIGHT];
-						LABEL_99:
-							v24 = SwapItem(v23, &plr[v3].HoldItem);
-						LABEL_172:
-							cursor_ida = v24;
-							goto LABEL_226;
-						}
-						if (v25 == ITYPE_NONE || plr[v3].InvBody[INVLOC_HAND_LEFT]._iClass != plr[v3].HoldItem._iClass) {
-						LABEL_232:
-							NetSendCmdChItem(FALSE, 5u);
-							v22 = &plr[v3].InvBody[INVLOC_HAND_RIGHT];
-						LABEL_158:
-							qmemcpy(v22, &plr[v3].HoldItem, sizeof(ItemStruct));
-							goto LABEL_226;
-						}
-					} else if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE
-					    || plr[v3].InvBody[INVLOC_HAND_LEFT]._iClass != plr[v3].HoldItem._iClass) {
-						goto LABEL_114;
+	il = ILOC_UNEQUIPABLE;
+	if (r >= 0 && r <= 3)
+		il = ILOC_HELM;
+	if (r >= 4 && r <= 5)
+		il = ILOC_RING;
+	if (r == 6)
+		il = ILOC_AMULET;
+	if (r >= 7 && r <= 18)
+		il = ILOC_ONEHAND;
+	if (r >= 19 && r <= 24)
+		il = ILOC_ARMOR;
+	if (r >= 65 && r <= 72)
+		il = ILOC_BELT;
+	done = FALSE;
+	if (plr[pnum].HoldItem._iLoc == il)
+		done = TRUE;
+	if (il == ILOC_ONEHAND && plr[pnum].HoldItem._iLoc == ILOC_TWOHAND) {
+		il = ILOC_TWOHAND;
+		done = TRUE;
+	}
+	if (plr[pnum].HoldItem._iLoc == ILOC_UNEQUIPABLE && il == ILOC_BELT) {
+		if (sx == 1 && sy == 1) {
+			done = TRUE;
+			if (!AllItemsList[plr[pnum].HoldItem.IDidx].iUsable)
+				done = FALSE;
+			if (!plr[pnum].HoldItem._iStatFlag)
+				done = FALSE;
+			if (plr[pnum].HoldItem._itype == ITYPE_GOLD)
+				done = FALSE;
+		}
+	}
+
+	if (il == ILOC_UNEQUIPABLE) {
+		done = TRUE;
+		it = 0;
+		ii = r - 25;
+		if (plr[pnum].HoldItem._itype == ITYPE_GOLD) {
+			yy = 10 * (ii / 10);
+			xx = ii % 10;
+			if (plr[pnum].InvGrid[xx + yy] != 0) {
+				iv = plr[pnum].InvGrid[xx + yy];
+				if (iv > 0) {
+					if (plr[pnum].InvList[iv - 1]._itype != ITYPE_GOLD) {
+						it = iv;
 					}
 				} else {
-					if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE) {
-						if (plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype != ITYPE_NONE
-						    && plr[v3].InvBody[INVLOC_HAND_RIGHT]._iClass == plr[v3].HoldItem._iClass) {
-						LABEL_114:
-							NetSendCmdChItem(FALSE, 5u);
-							v23 = &plr[v3].InvBody[INVLOC_HAND_RIGHT];
-							goto LABEL_99;
+					it = -iv;
+				}
+			}
+		} else {
+			yy = 10 * ((ii / 10) - ((sy - 1) >> 1));
+			if (yy < 0)
+				yy = 0;
+			for (j = 0; j < sy && done; j++) {
+				if (yy >= NUM_INV_GRID_ELEM)
+					done = FALSE;
+				xx = (ii % 10) - ((sx - 1) >> 1);
+				if (xx < 0)
+					xx = 0;
+				for (i = 0; i < sx && done; i++) {
+					if (xx >= 10) {
+						done = FALSE;
+					} else {
+						if (plr[pnum].InvGrid[xx + yy] != 0) {
+							iv = plr[pnum].InvGrid[xx + yy];
+							if (iv < 0)
+								iv = -iv;
+							if (it != 0) {
+								if (it != iv)
+									done = FALSE;
+							} else
+								it = iv;
 						}
-						NetSendCmdChItem(FALSE, 4u);
-						v22 = &plr[v3].InvBody[INVLOC_HAND_LEFT];
-						goto LABEL_158;
-					}
-					if (plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype != ITYPE_NONE
-					    && plr[v3].InvBody[INVLOC_HAND_RIGHT]._iClass == plr[v3].HoldItem._iClass) {
-						goto LABEL_114;
 					}
+					xx++;
 				}
-				NetSendCmdChItem(FALSE, 4u);
-				v23 = &plr[v3].InvBody[INVLOC_HAND_LEFT];
-				goto LABEL_99;
-			case ILOC_TWOHAND:
-				NetSendCmdDelItem(FALSE, 5u);
-				if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE)
-					goto LABEL_147;
-				v26 = plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype;
-				if (v26 == -1)
-					goto LABEL_146;
-				qmemcpy(&tempitem, &plr[v3].HoldItem, sizeof(tempitem));
-				v27 = &plr[v3].InvBody[INVLOC_HAND_RIGHT];
-				if (v26 != ITYPE_SHIELD)
-					v27 = &plr[v3].InvBody[INVLOC_HAND_LEFT];
-				v28 = p;
-				qmemcpy(&plr[v3].HoldItem, v27, sizeof(plr[v3].HoldItem));
-				v29 = plr[v3].HoldItem._iCurs + CURSOR_FIRSTITEM;
-				if (v28 == myplr)
-					SetCursor_(v29);
-				else
-					SetICursor(v29);
-				v67 = 0;
-				v30 = 0;
-				do {
-					if (v67)
-						break;
-					v31 = AutoPlace(p, v30++, icursW28, icursH28, 1);
-					v67 = v31;
-				} while (v30 < 40);
-				v32 = p;
-				qmemcpy(&plr[v3].HoldItem, &tempitem, sizeof(plr[v3].HoldItem));
-				v33 = plr[v3].HoldItem._iCurs + CURSOR_FIRSTITEM;
-				if (v32 == myplr)
-					SetCursor_(v33);
-				else
-					SetICursor(v33);
-				if (!v67)
-					return;
-				if (plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_SHIELD)
-					plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype = ITYPE_NONE;
-				else
-					plr[v3].InvBody[INVLOC_HAND_LEFT]._itype = ITYPE_NONE;
-			LABEL_146:
-				if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype != ITYPE_NONE)
-					goto LABEL_149;
-			LABEL_147:
-				if (plr[v3].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_NONE) {
-					NetSendCmdChItem(FALSE, 4u);
-					qmemcpy(&plr[v3].InvBody[INVLOC_HAND_LEFT], &plr[v3].HoldItem, sizeof(plr[v3].InvBody[INVLOC_HAND_LEFT]));
+				yy += 10;
+			}
+		}
+	}
+
+	if (!done)
+		return;
+
+	if (il != ILOC_UNEQUIPABLE && il != ILOC_BELT && !plr[pnum].HoldItem._iStatFlag) {
+		done = FALSE;
+		if (plr[pnum]._pClass == PC_WARRIOR)
+			PlaySFX(PS_WARR13);
+		else if (plr[pnum]._pClass == PC_ROGUE)
+			PlaySFX(PS_ROGUE13);
+		else if (plr[pnum]._pClass == PC_SORCERER)
+			PlaySFX(PS_MAGE13);
+	}
+
+	if (!done)
+		return;
+
+	if (pnum == myplr)
+		PlaySFX(ItemInvSnds[ItemCAnimTbl[plr[pnum].HoldItem._iCurs]]);
+
+	cn = CURSOR_HAND;
+	switch (il) {
+	case ILOC_HELM:
+		NetSendCmdChItem(FALSE, INVLOC_HEAD);
+		if (plr[pnum].InvBody[INVLOC_HEAD]._itype == ITYPE_NONE)
+			plr[pnum].InvBody[INVLOC_HEAD] = plr[pnum].HoldItem;
+		else
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_HEAD], &plr[pnum].HoldItem);
+		break;
+	case ILOC_RING:
+		if (r == 4) {
+			NetSendCmdChItem(FALSE, INVLOC_RING_LEFT);
+			if (plr[pnum].InvBody[INVLOC_RING_LEFT]._itype == ITYPE_NONE)
+				plr[pnum].InvBody[INVLOC_RING_LEFT] = plr[pnum].HoldItem;
+			else
+				cn = SwapItem(&plr[pnum].InvBody[INVLOC_RING_LEFT], &plr[pnum].HoldItem);
+		} else {
+			NetSendCmdChItem(FALSE, INVLOC_RING_RIGHT);
+			if (plr[pnum].InvBody[INVLOC_RING_RIGHT]._itype == ITYPE_NONE)
+				plr[pnum].InvBody[INVLOC_RING_RIGHT] = plr[pnum].HoldItem;
+			else
+				cn = SwapItem(&plr[pnum].InvBody[INVLOC_RING_RIGHT], &plr[pnum].HoldItem);
+		}
+		break;
+	case ILOC_AMULET:
+		NetSendCmdChItem(0, INVLOC_AMULET);
+		if (plr[pnum].InvBody[INVLOC_AMULET]._itype == ITYPE_NONE)
+			plr[pnum].InvBody[INVLOC_AMULET] = plr[pnum].HoldItem;
+		else
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_AMULET], &plr[pnum].HoldItem);
+		break;
+	case ILOC_ONEHAND:
+		if (r <= 12) {
+			if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE) {
+				if (plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_NONE || plr[pnum].InvBody[INVLOC_HAND_RIGHT]._iClass != plr[pnum].HoldItem._iClass) {
+					NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+					plr[pnum].InvBody[INVLOC_HAND_LEFT] = plr[pnum].HoldItem;
 				} else {
-				LABEL_149:
-					NetSendCmdChItem(FALSE, 4u);
-					if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE)
-						SwapItem(&plr[v3].InvBody[INVLOC_HAND_LEFT], &plr[v3].InvBody[INVLOC_HAND_RIGHT]);
-					cursor_ida = SwapItem(&plr[v3].InvBody[INVLOC_HAND_LEFT], &plr[v3].HoldItem);
-				}
-				if (plr[v3].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_STAFF) {
-					v34 = plr[v3].InvBody[INVLOC_HAND_LEFT]._iSpell;
-					if (v34) {
-						if (plr[v3].InvBody[INVLOC_HAND_LEFT]._iCharges > 0) {
-							plr[v3]._pRSpell = v34;
-							_LOBYTE(plr[v3]._pRSplType) = RSPLTYPE_CHARGES;
-							drawpanflag = 255;
-						}
-					}
+					NetSendCmdChItem(FALSE, INVLOC_HAND_RIGHT);
+					cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_RIGHT], &plr[pnum].HoldItem);
 				}
-				goto LABEL_226;
-			case ILOC_ARMOR:
-				NetSendCmdChItem(FALSE, 6u);
-				if (plr[v3].InvBody[INVLOC_CHEST]._itype == ITYPE_NONE) {
-					v22 = &plr[v3].InvBody[INVLOC_CHEST];
-					goto LABEL_158;
-				}
-				v23 = &plr[v3].InvBody[INVLOC_CHEST];
-				goto LABEL_99;
-			case ILOC_HELM:
-				NetSendCmdChItem(FALSE, 0);
-				if (plr[v3].InvBody[INVLOC_HEAD]._itype == ITYPE_NONE) {
-					v22 = plr[v3].InvBody;
-					goto LABEL_158;
-				}
-				v23 = plr[v3].InvBody;
-				goto LABEL_99;
-			case ILOC_RING:
-				if (v10 == 4) {
-					NetSendCmdChItem(FALSE, 1u);
-					if (plr[v3].InvBody[INVLOC_RING_LEFT]._itype == ITYPE_NONE) {
-						v22 = &plr[v3].InvBody[INVLOC_RING_LEFT];
-						goto LABEL_158;
-					}
-					v23 = &plr[v3].InvBody[INVLOC_RING_LEFT];
+				break;
+			}
+			if (plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_NONE || plr[pnum].InvBody[INVLOC_HAND_RIGHT]._iClass != plr[pnum].HoldItem._iClass) {
+				NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+				cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_LEFT], &plr[pnum].HoldItem);
+				break;
+			}
+
+			NetSendCmdChItem(FALSE, INVLOC_HAND_RIGHT);
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_RIGHT], &plr[pnum].HoldItem);
+			break;
+		}
+		if (plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_NONE) {
+			if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE || plr[pnum].InvBody[INVLOC_HAND_LEFT]._iLoc != ILOC_TWOHAND) {
+				if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE || plr[pnum].InvBody[INVLOC_HAND_LEFT]._iClass != plr[pnum].HoldItem._iClass) {
+					NetSendCmdChItem(FALSE, INVLOC_HAND_RIGHT);
+					plr[pnum].InvBody[INVLOC_HAND_RIGHT] = plr[pnum].HoldItem;
+					break;
+				}
+				NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+				cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_LEFT], &plr[pnum].HoldItem);
+				break;
+			}
+			NetSendCmdDelItem(FALSE, INVLOC_HAND_LEFT);
+			NetSendCmdChItem(FALSE, INVLOC_HAND_RIGHT);
+			SwapItem(&plr[pnum].InvBody[INVLOC_HAND_RIGHT], &plr[pnum].InvBody[INVLOC_HAND_LEFT]);
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_RIGHT], &plr[pnum].HoldItem);
+			break;
+		}
+
+		if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype != ITYPE_NONE && plr[pnum].InvBody[INVLOC_HAND_LEFT]._iClass == plr[pnum].HoldItem._iClass) {
+			NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_LEFT], &plr[pnum].HoldItem);
+			break;
+		}
+		NetSendCmdChItem(FALSE, INVLOC_HAND_RIGHT);
+		cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_RIGHT], &plr[pnum].HoldItem);
+		break;
+	case ILOC_TWOHAND:
+		NetSendCmdDelItem(FALSE, INVLOC_HAND_RIGHT);
+		if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype != ITYPE_NONE && plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype != ITYPE_NONE) {
+			tempitem = plr[pnum].HoldItem;
+			if (plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_SHIELD)
+				plr[pnum].HoldItem = plr[pnum].InvBody[INVLOC_HAND_RIGHT];
+			else
+				plr[pnum].HoldItem = plr[pnum].InvBody[INVLOC_HAND_LEFT];
+			if (pnum == myplr)
+				SetCursor_(plr[pnum].HoldItem._iCurs + CURSOR_FIRSTITEM);
+			else
+				SetICursor(plr[pnum].HoldItem._iCurs + CURSOR_FIRSTITEM);
+			done2h = FALSE;
+			for (i = 0; i < NUM_INV_GRID_ELEM && !done2h; i++)
+				done2h = AutoPlace(pnum, i, icursW28, icursH28, TRUE);
+			plr[pnum].HoldItem = tempitem;
+			if (pnum == myplr)
+				SetCursor_(plr[pnum].HoldItem._iCurs + CURSOR_FIRSTITEM);
+			else
+				SetICursor(plr[pnum].HoldItem._iCurs + CURSOR_FIRSTITEM);
+			if (!done2h)
+				return;
+
+			if (plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype == ITYPE_SHIELD)
+				plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype = ITYPE_NONE;
+			else
+				plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype = ITYPE_NONE;
+		}
+
+		if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype != ITYPE_NONE || plr[pnum].InvBody[INVLOC_HAND_RIGHT]._itype != ITYPE_NONE) {
+			NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+			if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_NONE)
+				SwapItem(&plr[pnum].InvBody[INVLOC_HAND_LEFT], &plr[pnum].InvBody[INVLOC_HAND_RIGHT]);
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_HAND_LEFT], &plr[pnum].HoldItem);
+		} else {
+			NetSendCmdChItem(FALSE, INVLOC_HAND_LEFT);
+			plr[pnum].InvBody[INVLOC_HAND_LEFT] = plr[pnum].HoldItem;
+		}
+		if (plr[pnum].InvBody[INVLOC_HAND_LEFT]._itype == ITYPE_STAFF && plr[pnum].InvBody[INVLOC_HAND_LEFT]._iSpell != 0 && plr[pnum].InvBody[INVLOC_HAND_LEFT]._iCharges > 0) {
+			plr[pnum]._pRSpell = plr[pnum].InvBody[INVLOC_HAND_LEFT]._iSpell;
+			plr[pnum]._pRSplType = RSPLTYPE_CHARGES;
+			drawpanflag = 255;
+		}
+		break;
+	case ILOC_ARMOR:
+		NetSendCmdChItem(FALSE, INVLOC_CHEST);
+		if (plr[pnum].InvBody[INVLOC_CHEST]._itype == ITYPE_NONE)
+			plr[pnum].InvBody[INVLOC_CHEST] = plr[pnum].HoldItem;
+		else
+			cn = SwapItem(&plr[pnum].InvBody[INVLOC_CHEST], &plr[pnum].HoldItem);
+		break;
+	case ILOC_UNEQUIPABLE:
+		if (plr[pnum].HoldItem._itype == ITYPE_GOLD && it == 0) {
+			ii = r - 25;
+			yy = 10 * (ii / 10);
+			xx = ii % 10;
+			if (plr[pnum].InvGrid[yy + xx] > 0) {
+				il = plr[pnum].InvGrid[yy + xx];
+				il--;
+				gt = plr[pnum].InvList[il]._ivalue;
+				ig = plr[pnum].HoldItem._ivalue + gt;
+				if (ig <= 5000) {
+					plr[pnum].InvList[il]._ivalue = ig;
+					plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
+					if (ig >= 2500)
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_LARGE;
+					else if (ig <= 1000)
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_SMALL;
+					else
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_MEDIUM;
 				} else {
-					NetSendCmdChItem(FALSE, 2u);
-					if (plr[v3].InvBody[INVLOC_RING_RIGHT]._itype == ITYPE_NONE) {
-						v22 = &plr[v3].InvBody[INVLOC_RING_RIGHT];
-						goto LABEL_158;
-					}
-					v23 = &plr[v3].InvBody[INVLOC_RING_RIGHT];
+					ig = 5000 - gt;
+					plr[pnum]._pGold += ig;
+					plr[pnum].HoldItem._ivalue -= ig;
+					plr[pnum].InvList[il]._ivalue = 5000;
+					plr[pnum].InvList[il]._iCurs = ICURS_GOLD_LARGE;
+					// BUGFIX: incorrect values here are leftover from beta
+					if (plr[pnum].HoldItem._ivalue >= 2500)
+						cn = 18;
+					else if (plr[pnum].HoldItem._ivalue <= 1000)
+						cn = 16;
+					else
+						cn = 17;
 				}
-				goto LABEL_99;
-			case ILOC_AMULET:
-				NetSendCmdChItem(FALSE, 3u);
-				if (plr[v3].InvBody[INVLOC_AMULET]._itype == ITYPE_NONE) {
-					v22 = &plr[v3].InvBody[INVLOC_AMULET];
-					goto LABEL_158;
-				}
-				v23 = &plr[v3].InvBody[INVLOC_AMULET];
-				goto LABEL_99;
-			case ILOC_UNEQUIPABLE:
-				v35 = plr[v3].HoldItem._itype;
-				if (v35 == ITYPE_GOLD) {
-					if (!v66) {
-						v36 = &plr[0].InvGrid[10 * ((v68 - 25) / 10) + v3 * 21720 + (v68 - 25) % 10];
-						if (*v36 <= 0) {
-							v42 = 368 * plr[v3]._pNumInv + v3 * 21720;
-							qmemcpy((char *)plr[0].InvList + v42, &plr[v3].HoldItem, 0x170u);
-							++plr[v3]._pNumInv;
-							*v36 = plr[v3]._pNumInv;
-							v43 = plr[v3].HoldItem._ivalue;
-							plr[v3]._pGold += v43;
-							if (v43 <= 5000) {
-								if (v43 < 2500) {
-									if (v43 > 1000)
-										*(int *)((char *)&plr[0].InvList[0]._iCurs + v42) = 5;
-									else
-										*(int *)((char *)&plr[0].InvList[0]._iCurs + v42) = 4;
-								} else {
-									*(int *)((char *)&plr[0].InvList[0]._iCurs + v42) = 6;
-								}
-							}
-							goto LABEL_226;
-						}
-						v37 = plr[v3].HoldItem._ivalue;
-						v38 = 368 * (*v36 - 1) + v3 * 21720;
-						v39 = *(int *)((char *)&plr[0].InvList[0]._ivalue + v38);
-						v40 = v37 + v39;
-						if (v37 + v39 <= 5000) {
-							*(int *)((char *)&plr[0].InvList[0]._ivalue + v38) = v40;
-							plr[v3]._pGold += plr[v3].HoldItem._ivalue;
-							if (v40 < 2500) {
-								if (v40 > 1000)
-									*(int *)((char *)&plr[0].InvList[0]._iCurs + v38) = 5;
-								else
-									*(int *)((char *)&plr[0].InvList[0]._iCurs + v38) = 4;
-							} else {
-								*(int *)((char *)&plr[0].InvList[0]._iCurs + v38) = 6;
-							}
-							goto LABEL_226;
-						}
-						plr[v3]._pGold += 5000 - v39;
-						plr[v3].HoldItem._ivalue = v37 - (5000 - v39);
-						*(int *)((char *)&plr[0].InvList[0]._ivalue + v38) = 5000;
-						*(int *)((char *)&plr[0].InvList[0]._iCurs + v38) = 6;
-						v41 = plr[v3].HoldItem._ivalue;
-						if (v41 >= 2500) {
-							cursor_ida = 18;
-							goto LABEL_226;
-						}
-						v24 = (v41 > 1000) + 16;
-						goto LABEL_172;
-					}
-				} else if (!v66) {
-					qmemcpy((char *)&plr[0].InvList[plr[v3]._pNumInv++] + v3 * 21720, &plr[v3].HoldItem, 0x170u);
-					v66 = plr[v3]._pNumInv;
-				LABEL_191:
-					v48 = v67;
-					v49 = 10 * ((v68 - 25) / 10 - ((v67 - 1) >> 1));
-					if (v49 < 0)
-						v49 = 0;
-					v65 = 0;
-					if (v67 > 0) {
-						v69 = (v68 - 25) % 10 - ((v64 - 1) >> 1);
-						do {
-							v50 = v69;
-							if (v69 < 0)
-								v50 = 0;
-							v67 = 0;
-							if (v64 > 0) {
-								v51 = &plr[v3].InvGrid[v50 + v49];
-								do {
-									if (v67 || v65 != v48 - 1)
-										v52 = -(char)v66;
-									else
-										v52 = v66;
-									*v51++ = v52;
-									++v67;
-								} while (v67 < v64);
-							}
-							v49 += 10;
-							++v65;
-						} while (v65 < v48);
-					}
-					goto LABEL_226;
+			} else {
+				il = plr[pnum]._pNumInv;
+				plr[pnum].InvList[il] = plr[pnum].HoldItem;
+				plr[pnum]._pNumInv++;
+				plr[pnum].InvGrid[yy + xx] = plr[pnum]._pNumInv;
+				plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
+				if (plr[pnum].HoldItem._ivalue <= 5000) {
+					if (plr[pnum].HoldItem._ivalue >= 2500)
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_LARGE;
+					else if (plr[pnum].HoldItem._ivalue <= 1000)
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_SMALL;
+					else
+						plr[pnum].InvList[il]._iCurs = ICURS_GOLD_MEDIUM;
 				}
-				v44 = v66 - 1;
-				if (v35 == ITYPE_GOLD)
-					plr[v3]._pGold += plr[v3].HoldItem._ivalue;
-				cursor_ida = SwapItem((ItemStruct *)((char *)&plr[0].InvList[v44] + v3 * 21720), &plr[v3].HoldItem);
-				if (plr[v3].HoldItem._itype == ITYPE_GOLD)
-					plr[v3]._pGold = CalculateGold(v21);
-				v45 = 0;
-				v46 = -v66;
-				do {
-					v47 = &plr[v3].InvGrid[v45];
-					if (*v47 == v66)
-						*v47 = 0;
-					if (*v47 == v46)
-						*v47 = 0;
-					++v45;
-				} while (v45 < 40);
-				goto LABEL_191;
-			case ILOC_BELT:
-				v53 = v3 * 21720 + 368 * (v68 - 65);
-				if (plr[v3].HoldItem._itype != ITYPE_GOLD) {
-					if (*(int *)((char *)&plr[0].SpdList[0]._itype + v53) == ITYPE_NONE) {
-						qmemcpy((char *)plr[0].SpdList + v53, &plr[v3].HoldItem, 0x170u);
-					} else {
-						cursor_ida = SwapItem((ItemStruct *)((char *)plr[0].SpdList + v53), &plr[v3].HoldItem);
-						if (plr[v3].HoldItem._itype == ITYPE_GOLD)
-							plr[v3]._pGold = CalculateGold(p);
-					}
-					goto LABEL_225;
+			}
+		} else {
+			if (it == 0) {
+				plr[pnum].InvList[plr[pnum]._pNumInv] = plr[pnum].HoldItem;
+				plr[pnum]._pNumInv++;
+				it = plr[pnum]._pNumInv;
+			} else {
+				il = it - 1;
+				if (plr[pnum].HoldItem._itype == ITYPE_GOLD)
+					plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
+				cn = SwapItem(&plr[pnum].InvList[il], &plr[pnum].HoldItem);
+				if (plr[pnum].HoldItem._itype == ITYPE_GOLD)
+					plr[pnum]._pGold = CalculateGold(pnum);
+				for (i = 0; i < NUM_INV_GRID_ELEM; i++) {
+					if (plr[pnum].InvGrid[i] == it)
+						plr[pnum].InvGrid[i] = 0;
+					if (plr[pnum].InvGrid[i] == -it)
+						plr[pnum].InvGrid[i] = 0;
+				}
+			}
+			ii = r - 25;
+			yy = 10 * (ii / 10 - ((sy - 1) >> 1));
+			if (yy < 0)
+				yy = 0;
+			for (j = 0; j < sy; j++) {
+				xx = (ii % 10 - ((sx - 1) >> 1));
+				if (xx < 0)
+					xx = 0;
+				for (i = 0; i < sx; i++) {
+					if (i != 0 || j != sy - 1)
+						plr[pnum].InvGrid[xx + yy] = -it;
+					else
+						plr[pnum].InvGrid[xx + yy] = it;
+					xx++;
 				}
-				v54 = *(int *)((char *)&plr[0].SpdList[0]._itype + v53);
-				if (v54 != ITYPE_NONE) {
-					if (v54 == ITYPE_GOLD) {
-						v55 = *(int *)((char *)&plr[0].SpdList[0]._ivalue + v53);
-						v56 = plr[v3].HoldItem._ivalue;
-						v57 = v55 + v56;
-						if (v55 + v56 <= 5000) {
-							*(int *)((char *)&plr[0].SpdList[0]._ivalue + v53) = v57;
-							plr[v3]._pGold += plr[v3].HoldItem._ivalue;
-							if (v57 < 2500) {
-								if (v57 > 1000)
-									*(int *)((char *)&plr[0].SpdList[0]._iCurs + v53) = 5;
-								else
-									*(int *)((char *)&plr[0].SpdList[0]._iCurs + v53) = 4;
-							} else {
-								*(int *)((char *)&plr[0].SpdList[0]._iCurs + v53) = 6;
-							}
-							goto LABEL_225;
-						}
-						plr[v3]._pGold += 5000 - v55;
-						plr[v3].HoldItem._ivalue = v56 - (5000 - v55);
-						*(int *)((char *)&plr[0].SpdList[0]._ivalue + v53) = 5000;
-						*(int *)((char *)&plr[0].SpdList[0]._iCurs + v53) = 6;
-						v58 = plr[v3].HoldItem._ivalue;
-						if (v58 >= 2500) {
-							cursor_ida = 18;
-							goto LABEL_225;
-						}
-						v59 = (v58 > 1000) + 16;
+				yy += 10;
+			}
+		}
+		break;
+	case ILOC_BELT:
+		ii = r - 65;
+		if (plr[pnum].HoldItem._itype == ITYPE_GOLD) {
+			if (plr[pnum].SpdList[ii]._itype != ITYPE_NONE) {
+				if (plr[pnum].SpdList[ii]._itype == ITYPE_GOLD) {
+					i = plr[pnum].HoldItem._ivalue + plr[pnum].SpdList[ii]._ivalue;
+					if (i <= 5000) {
+						plr[pnum].SpdList[ii]._ivalue += plr[pnum].HoldItem._ivalue;
+						plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
+						if (i >= 2500)
+							plr[pnum].SpdList[ii]._iCurs = ICURS_GOLD_LARGE;
+						else if (i <= 1000)
+							plr[pnum].SpdList[ii]._iCurs = ICURS_GOLD_SMALL;
+						else
+							plr[pnum].SpdList[ii]._iCurs = ICURS_GOLD_MEDIUM;
 					} else {
-						plr[v3]._pGold += plr[v3].HoldItem._ivalue;
-						v59 = SwapItem((ItemStruct *)((char *)plr[0].SpdList + v53), &plr[v3].HoldItem);
+						i = 5000 - plr[pnum].SpdList[ii]._ivalue;
+						plr[pnum]._pGold += i;
+						plr[pnum].HoldItem._ivalue -= i;
+						plr[pnum].SpdList[ii]._ivalue = 5000;
+						plr[pnum].SpdList[ii]._iCurs = ICURS_GOLD_LARGE;
+
+						// BUGFIX: incorrect values here are leftover from beta
+						if (plr[pnum].HoldItem._ivalue >= 2500)
+							cn = 18;
+						else if (plr[pnum].HoldItem._ivalue <= 1000)
+							cn = 16;
+						else
+							cn = 17;
 					}
-					cursor_ida = v59;
-					goto LABEL_225;
-				}
-				qmemcpy((char *)plr[0].SpdList + v53, &plr[v3].HoldItem, 0x170u);
-				plr[v3]._pGold += plr[v3].HoldItem._ivalue;
-			LABEL_225:
-				drawsbarflag = TRUE;
-			LABEL_226:
-				v60 = p;
-				CalcPlrInv(p, 1u);
-				if (v60 == myplr) {
-					if (cursor_ida == 1)
-						SetCursorPos(MouseX + (cursW >> 1), MouseY + (cursH >> 1));
-					SetCursor_(cursor_ida);
+				} else {
+					plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
+					cn = SwapItem(&plr[pnum].SpdList[ii], &plr[pnum].HoldItem);
 				}
-				return;
-			default:
-				goto LABEL_226;
+			} else {
+				plr[pnum].SpdList[ii] = plr[pnum].HoldItem;
+				plr[pnum]._pGold += plr[pnum].HoldItem._ivalue;
 			}
+		} else if (plr[pnum].SpdList[ii]._itype == ITYPE_NONE) {
+			plr[pnum].SpdList[ii] = plr[pnum].HoldItem;
+		} else {
+			cn = SwapItem(&plr[pnum].SpdList[ii], &plr[pnum].HoldItem);
+			if (plr[pnum].HoldItem._itype == 11)
+				plr[pnum]._pGold = CalculateGold(pnum);
 		}
-		v62 = (v68 - 25) % 10;
-		v14 = 10 * (v13 - ((v67 - 1) >> 1));
-		if (v14 < 0)
-			v14 = 0;
-		v65 = 0;
-		if (v67 <= 0)
-			goto LABEL_93;
-		v15 = &plr[v3].InvGrid[v14];
-		while (1) {
-			if (cursor_id == CURSOR_NONE)
-				return;
-			if (v14 >= 40)
-				cursor_id = 0;
-			v16 = v62 - ((v64 - 1) >> 1);
-			if (v16 < 0)
-				v16 = 0;
-			v17 = 0;
-			if (v64 > 0)
-				break;
-		LABEL_79:
-			v14 += 10;
-			v15 += 10;
-			if (++v65 >= v67) {
-				v12 = cursor_id;
-				v10 = v68;
-				goto LABEL_81;
-			}
-		}
-		while (1) {
-			if (cursor_id == CURSOR_NONE)
-				goto LABEL_79;
-			if (v16 >= 10)
-				goto LABEL_233;
-			_LOBYTE(v18) = v15[v16];
-			if ((_BYTE)v18) {
-				v18 = (char)v18;
-				if ((v18 & 0x80u) != 0)
-					v18 = -v18;
-				if (!v66) {
-					v66 = v18;
-					goto LABEL_78;
-				}
-				if (v66 != v18)
-				LABEL_233:
-					cursor_id = 0;
-			}
-		LABEL_78:
-			++v16;
-			if (++v17 >= v64)
-				goto LABEL_79;
-		}
-	}
-	if (v64 == 1 && v67 == 1) {
-		v12 = 1;
-		if (!AllItemsList[plr[v3].HoldItem.IDidx].iUsable)
-			v12 = 0;
-		if (!plr[v3].HoldItem._iStatFlag)
-			v12 = 0;
-		if (plr[v3].HoldItem._itype == ITYPE_GOLD) {
-			v12 = 0;
-			goto LABEL_50;
-		}
-	}
-LABEL_81:
-	if (!v12)
-		return;
-	if (v69 == ILOC_UNEQUIPABLE || v69 == ILOC_BELT || plr[v3].HoldItem._iStatFlag) {
-		goto LABEL_93;
+		drawsbarflag = 1;
+		break;
 	}
-	if (plr[v3]._pClass == PC_WARRIOR) {
-		PlaySFX(PS_WARR13);
-	} else if (plr[v3]._pClass == PC_ROGUE) {
-		PlaySFX(PS_ROGUE13);
-	} else if (plr[v3]._pClass == PC_SORCERER) {
-		PlaySFX(PS_MAGE13);
+	CalcPlrInv(pnum, 1);
+	if (pnum == myplr) {
+		if (cn == 1)
+			SetCursorPos(MouseX + (cursW >> 1), MouseY + (cursH >> 1));
+		SetCursor_(cn);
 	}
 }
-// 4B8C9C: using guessed type int cursH;
-// 4B8CB4: using guessed type int icursH;
-// 4B8CBC: using guessed type int icursW;
-// 52571C: using guessed type int drawpanflag;
 
 void CheckInvSwap(int pnum, BYTE bLoc, int idx, WORD wCI, int seed, BOOL bId)
 {
