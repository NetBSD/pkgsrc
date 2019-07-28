$NetBSD: patch-Source_loadsave.cpp,v 1.1 2019/07/28 10:26:43 nia Exp $

64bit Compatible Saves
https://patch-diff.githubusercontent.com/raw/diasurgical/devilutionX/pull/162.patch

[PATCH] Fix load/save monster padding
https://github.com/diasurgical/devilutionX/commit/10ebca4efd422bbf46bad6d12ea4cdade9038b01.patch

--- Source/loadsave.cpp.orig	2019-05-19 17:06:45.000000000 +0000
+++ Source/loadsave.cpp
@@ -207,42 +207,829 @@ BOOL OLoad()
 		return FALSE;
 }
 
+void CopyInt(const void *src, void * dst)
+{
+	memcpy(dst, src, 4);
+	tbuff += 4;
+}
+
+void CopyShort(const void *src, void * dst)
+{
+	memcpy(dst, src, 2);
+	tbuff += 2;
+}
+
+void CopyShorts(const void *src, const int n, void * dst)
+{
+	memcpy(dst, src, 2 * n);
+	tbuff += 2 * n;
+}
+
+void CopyInts(const void *src, const int n, void * dst)
+{
+	memcpy(dst, src, 4 * n);
+	tbuff += 4 * n;
+}
+
+void CopyBytes(const void *src, const int n, void * dst)
+{
+	memcpy(dst, src, n);
+	tbuff += n;
+}
+
+void CopyChar(const void *src, void * dst)
+{
+	memcpy(dst, src, 1);
+	tbuff += 1;
+}
+
+void CopyInt64(const void *src, void * dst)
+{
+	memcpy(dst, src, 8);
+	tbuff += 8;
+}
+
 void LoadPlayer(int i)
 {
-	memcpy(&plr[i], tbuff, sizeof(*plr) - (10 * sizeof(void *)));
-	tbuff += sizeof(*plr) - (10 * sizeof(void *)); // omit last 10 pointers
+	PlayerStruct *pPlayer = &plr[i];
+
+	CopyInt(tbuff, &pPlayer->_pmode);
+
+	CopyBytes(tbuff, 25, pPlayer->walkpath);
+	CopyBytes(tbuff, 1, &pPlayer->plractive);
+	tbuff += 2;
+
+	CopyInt(tbuff, &pPlayer->destAction);
+	CopyInt(tbuff, &pPlayer->destParam1);
+	CopyInt(tbuff, &pPlayer->destParam2);
+	CopyInt(tbuff, &pPlayer->destParam3);
+	CopyInt(tbuff, &pPlayer->destParam4);
+	CopyInt(tbuff, &pPlayer->plrlevel);
+	CopyInt(tbuff, &pPlayer->WorldX);
+	CopyInt(tbuff, &pPlayer->WorldY);
+	CopyInt(tbuff, &pPlayer->_px);
+	CopyInt(tbuff, &pPlayer->_py);
+	CopyInt(tbuff, &pPlayer->_ptargx);
+	CopyInt(tbuff, &pPlayer->_ptargy);
+	CopyInt(tbuff, &pPlayer->_pownerx);
+	CopyInt(tbuff, &pPlayer->_pownery);
+	CopyInt(tbuff, &pPlayer->_poldx);
+	CopyInt(tbuff, &pPlayer->_poldy);
+	CopyInt(tbuff, &pPlayer->_pxoff);
+	CopyInt(tbuff, &pPlayer->_pyoff);
+	CopyInt(tbuff, &pPlayer->_pxvel);
+	CopyInt(tbuff, &pPlayer->_pyvel);
+	CopyInt(tbuff, &pPlayer->_pdir);
+	CopyInt(tbuff, &pPlayer->_nextdir);
+	CopyInt(tbuff, &pPlayer->_pgfxnum);
+	tbuff += 4; // Skip pointers
+	CopyInt(tbuff, &pPlayer->_pAnimDelay);
+	CopyInt(tbuff, &pPlayer->_pAnimCnt);
+	CopyInt(tbuff, &pPlayer->_pAnimLen);
+	CopyInt(tbuff, &pPlayer->_pAnimFrame);
+	CopyInt(tbuff, &pPlayer->_pAnimWidth);
+	CopyInt(tbuff, &pPlayer->_pAnimWidth2);
+	CopyInt(tbuff, &pPlayer->_peflag);
+	CopyInt(tbuff, &pPlayer->_plid);
+	CopyInt(tbuff, &pPlayer->_pvid);
+
+	CopyInt(tbuff, &pPlayer->_pSpell);
+	CopyChar(tbuff, &pPlayer->_pSplType);
+	CopyChar(tbuff, &pPlayer->_pSplFrom);
+	tbuff += 2;
+	CopyInt(tbuff, &pPlayer->_pTSpell);
+	CopyChar(tbuff, &pPlayer->_pTSplType);
+	tbuff += 3;
+	CopyInt(tbuff, &pPlayer->_pRSpell);
+	CopyChar(tbuff, &pPlayer->_pRSplType);
+	tbuff += 3;
+	CopyInt(tbuff, &pPlayer->_pSBkSpell);
+	CopyChar(tbuff, &pPlayer->_pSBkSplType);
+
+	CopyBytes(tbuff, 64, &pPlayer->_pSplLvl);
+	tbuff += 7;
+	CopyInt64(tbuff, &pPlayer->_pMemSpells);
+	CopyInt64(tbuff, &pPlayer->_pAblSpells);
+	CopyInt64(tbuff, &pPlayer->_pScrlSpells);
+	CopyChar(tbuff, &pPlayer->_pSpellFlags);
+ 	tbuff += 3;
+	CopyInts(tbuff, 4, &pPlayer->_pSplHotKey);
+	CopyBytes(tbuff, 4, &pPlayer->_pSplTHotKey);
+	CopyInt(tbuff, &pPlayer->_pwtype);
+	CopyChar(tbuff, &pPlayer->_pBlockFlag);
+	CopyChar(tbuff, &pPlayer->_pInvincible);
+	CopyChar(tbuff, &pPlayer->_pLightRad);
+	CopyChar(tbuff, &pPlayer->_pLvlChanging);
+	CopyBytes(tbuff, PLR_NAME_LEN, &pPlayer->_pName);
+	CopyChar(tbuff, &pPlayer->_pClass);
+	tbuff += 3;
+	CopyInt(tbuff, &pPlayer->_pStrength);
+	CopyInt(tbuff, &pPlayer->_pBaseStr);
+	CopyInt(tbuff, &pPlayer->_pMagic);
+	CopyInt(tbuff, &pPlayer->_pBaseMag);
+	CopyInt(tbuff, &pPlayer->_pDexterity);
+	CopyInt(tbuff, &pPlayer->_pBaseDex);
+	CopyInt(tbuff, &pPlayer->_pVitality);
+	CopyInt(tbuff, &pPlayer->_pBaseVit);
+	CopyInt(tbuff, &pPlayer->_pStatPts);
+	CopyInt(tbuff, &pPlayer->_pDamageMod);
+	CopyInt(tbuff, &pPlayer->_pBaseToBlk);
+	CopyInt(tbuff, &pPlayer->_pHPBase);
+	CopyInt(tbuff, &pPlayer->_pMaxHPBase);
+	CopyInt(tbuff, &pPlayer->_pHitPoints);
+	CopyInt(tbuff, &pPlayer->_pMaxHP);
+	CopyInt(tbuff, &pPlayer->_pHPPer);
+	CopyInt(tbuff, &pPlayer->_pManaBase);
+	CopyInt(tbuff, &pPlayer->_pMaxManaBase);
+	CopyInt(tbuff, &pPlayer->_pMana);
+	CopyInt(tbuff, &pPlayer->_pMaxMana);
+	CopyInt(tbuff, &pPlayer->_pManaPer);
+	CopyChar(tbuff, &pPlayer->_pLevel);
+	CopyChar(tbuff, &pPlayer->_pMaxLvl);
+	tbuff += 2;
+	CopyInt(tbuff, &pPlayer->_pExperience);
+	CopyInt(tbuff, &pPlayer->_pMaxExp);
+	CopyInt(tbuff, &pPlayer->_pNextExper);
+	CopyChar(tbuff, &pPlayer->_pArmorClass);
+	CopyChar(tbuff, &pPlayer->_pMagResist);
+	CopyChar(tbuff, &pPlayer->_pFireResist);
+	CopyChar(tbuff, &pPlayer->_pLghtResist);
+	CopyInt(tbuff, &pPlayer->_pGold);
+	CopyInt(tbuff, &pPlayer->_pInfraFlag);
+	CopyInt(tbuff, &pPlayer->_pVar1);
+	CopyInt(tbuff, &pPlayer->_pVar2);
+	CopyInt(tbuff, &pPlayer->_pVar3);
+	CopyInt(tbuff, &pPlayer->_pVar4);
+	CopyInt(tbuff, &pPlayer->_pVar5);
+	CopyInt(tbuff, &pPlayer->_pVar6);
+	CopyInt(tbuff, &pPlayer->_pVar7);
+	CopyInt(tbuff, &pPlayer->_pVar8);
+	CopyBytes(tbuff, NUMLEVELS, &pPlayer->_pLvlVisited);
+	CopyBytes(tbuff, NUMLEVELS, &pPlayer->_pSLvlVisited);
+	tbuff += 2;
+	CopyInt(tbuff, &pPlayer->_pGFXLoad);
+
+	tbuff += sizeof(__uint32_t) * 8;
+	CopyInt(tbuff, &pPlayer->_pNFrames);
+	CopyInt(tbuff, &pPlayer->_pNWidth);
+
+	tbuff += sizeof(__uint32_t) * 8;
+
+	CopyInt(tbuff, &pPlayer->_pWFrames);
+	CopyInt(tbuff, &pPlayer->_pWWidth);
+
+	tbuff += sizeof(__uint32_t) * 8;
+
+	CopyInt(tbuff, &pPlayer->_pAFrames);
+	CopyInt(tbuff, &pPlayer->_pAWidth);
+	CopyInt(tbuff, &pPlayer->_pAFNum);
+
+	tbuff += sizeof(__uint32_t) * 24;
+
+	CopyInt(tbuff, &pPlayer->_pSFrames);
+	CopyInt(tbuff, &pPlayer->_pSWidth);
+	CopyInt(tbuff, &pPlayer->_pSFNum);
+
+	tbuff += sizeof(__uint32_t) * 8;
+
+	CopyInt(tbuff, &pPlayer->_pHFrames);
+	CopyInt(tbuff, &pPlayer->_pHWidth);
+
+	tbuff += sizeof(__uint32_t) * 8;
+
+	CopyInt(tbuff, &pPlayer->_pDFrames);
+	CopyInt(tbuff, &pPlayer->_pDWidth);
+
+	tbuff += sizeof(__uint32_t) * 8;
+
+	CopyInt(tbuff, &pPlayer->_pBFrames);
+	CopyInt(tbuff, &pPlayer->_pBWidth);
+	CopyItems(NUM_INVLOC, pPlayer->InvBody);
+	CopyItems(NUM_INV_GRID_ELEM, pPlayer->InvList);
+	CopyInt(tbuff, &pPlayer->_pNumInv);
+	CopyBytes(tbuff, NUM_INV_GRID_ELEM, pPlayer->InvGrid);
+	CopyItems(MAXBELTITEMS, pPlayer->SpdList);
+	CopyItem(&pPlayer->HoldItem);
+	CopyInt(tbuff, &pPlayer->_pIMinDam);
+	CopyInt(tbuff, &pPlayer->_pIMaxDam);
+	CopyInt(tbuff, &pPlayer->_pIAC);
+	CopyInt(tbuff, &pPlayer->_pIBonusDam);
+	CopyInt(tbuff, &pPlayer->_pIBonusToHit);
+	CopyInt(tbuff, &pPlayer->_pIBonusAC);
+	CopyInt(tbuff, &pPlayer->_pIBonusDamMod);
+	tbuff += 4;
+	CopyInt64(tbuff, &pPlayer->_pISpells);
+	CopyInt(tbuff, &pPlayer->_pIFlags);
+	CopyInt(tbuff, &pPlayer->_pIGetHit);
+
+	CopyChar(tbuff, &pPlayer->_pISplLvlAdd);
+	CopyChar(tbuff, &pPlayer->_pISplCost);
+	tbuff += 2;
+
+	CopyInt(tbuff, &pPlayer->_pISplDur);
+	CopyInt(tbuff, &pPlayer->_pIEnAc);
+	CopyInt(tbuff, &pPlayer->_pIFMinDam);
+	CopyInt(tbuff, &pPlayer->_pIFMaxDam);
+	CopyInt(tbuff, &pPlayer->_pILMinDam);
+	CopyInt(tbuff, &pPlayer->_pILMaxDam);
+	CopyInt(tbuff, &pPlayer->_pOilType);
+
+	CopyChar(tbuff, &pPlayer->pTownWarps);
+	CopyChar(tbuff, &pPlayer->pDungMsgs);
+	CopyChar(tbuff, &pPlayer->pLvlLoad);
+	CopyChar(tbuff, &pPlayer->pBattleNet);
+
+	CopyChar(tbuff, &pPlayer->pManaShield);
+	CopyBytes(tbuff, 3, &pPlayer->bReserved);
+
+	CopyShorts(tbuff, 8, &pPlayer->wReserved);
+
+	CopyInt(tbuff, &pPlayer->pDiabloKillLevel);
+	CopyInts(tbuff, 7, &pPlayer->dwReserved);
+
+	// Omit 10 pointers
+	
+}
+
+void SavePlayer(int i)
+{
+	PlayerStruct *pPlayer = &plr[i];
+
+	CopyInt(&pPlayer->_pmode, tbuff);
+
+	CopyBytes(&pPlayer->walkpath, 25, tbuff);
+	CopyBytes(&pPlayer->plractive, 1, tbuff);
+	tbuff += 2;
+
+	CopyInt(&pPlayer->destAction, tbuff);
+	CopyInt(&pPlayer->destParam1, tbuff);
+	CopyInt(&pPlayer->destParam2, tbuff);
+	CopyInt(&pPlayer->destParam3, tbuff);
+	CopyInt(&pPlayer->destParam4, tbuff);
+	CopyInt(&pPlayer->plrlevel, tbuff);
+	CopyInt(&pPlayer->WorldX, tbuff);
+	CopyInt(&pPlayer->WorldY, tbuff);
+	CopyInt(&pPlayer->_px, tbuff);
+	CopyInt(&pPlayer->_py, tbuff);
+	CopyInt(&pPlayer->_ptargx, tbuff);
+	CopyInt(&pPlayer->_ptargy, tbuff);
+	CopyInt(&pPlayer->_pownerx, tbuff);
+	CopyInt(&pPlayer->_pownery, tbuff);
+	CopyInt(&pPlayer->_poldx, tbuff);
+	CopyInt(&pPlayer->_poldy, tbuff);
+	CopyInt(&pPlayer->_pxoff, tbuff);
+	CopyInt(&pPlayer->_pyoff, tbuff);
+	CopyInt(&pPlayer->_pxvel, tbuff);
+	CopyInt(&pPlayer->_pyvel, tbuff);
+	CopyInt(&pPlayer->_pdir, tbuff);
+	CopyInt(&pPlayer->_nextdir, tbuff);
+	CopyInt(&pPlayer->_pgfxnum, tbuff);
+	tbuff += 4; // Skip pointers
+	CopyInt(&pPlayer->_pAnimDelay, tbuff);
+	CopyInt(&pPlayer->_pAnimCnt, tbuff);
+	CopyInt(&pPlayer->_pAnimLen, tbuff);
+	CopyInt(&pPlayer->_pAnimFrame, tbuff);
+	CopyInt(&pPlayer->_pAnimWidth, tbuff);
+	CopyInt(&pPlayer->_pAnimWidth2, tbuff);
+	CopyInt(&pPlayer->_peflag, tbuff);
+	CopyInt(&pPlayer->_plid, tbuff);
+	CopyInt(&pPlayer->_pvid, tbuff);
+
+	CopyInt(&pPlayer->_pSpell, tbuff);
+
+	CopyChar(&pPlayer->_pSplType, tbuff);
+	CopyChar(&pPlayer->_pSplFrom, tbuff);
+	tbuff += 2;
+	
+	CopyInt(&pPlayer->_pTSpell, tbuff);
+	CopyChar(&pPlayer->_pTSplType, tbuff);
+	tbuff += 3;
+	CopyInt(&pPlayer->_pRSpell, tbuff);
+	CopyChar(&pPlayer->_pRSplType, tbuff);
+	tbuff += 3;
+	CopyInt(&pPlayer->_pSBkSpell, tbuff);
+	CopyChar(&pPlayer->_pSBkSplType, tbuff);
+
+	CopyBytes(&pPlayer->_pSplLvl, 64, tbuff);
+	tbuff += 7;
+	CopyInt64(&pPlayer->_pMemSpells, tbuff);
+	CopyInt64(&pPlayer->_pAblSpells, tbuff);
+	CopyInt64(&pPlayer->_pScrlSpells, tbuff);
+	CopyChar(&pPlayer->_pSpellFlags, tbuff);
+ 	tbuff += 3;
+	CopyInts(&pPlayer->_pSplHotKey, 4, tbuff);
+	CopyBytes(&pPlayer->_pSplTHotKey, 4, tbuff);
+	CopyInt(&pPlayer->_pwtype, tbuff);
+	CopyChar(&pPlayer->_pBlockFlag, tbuff);
+	CopyChar(&pPlayer->_pInvincible, tbuff);
+	CopyChar(&pPlayer->_pLightRad, tbuff);
+	CopyChar(&pPlayer->_pLvlChanging, tbuff);
+	CopyBytes(&pPlayer->_pName, PLR_NAME_LEN, tbuff);
+	CopyChar(&pPlayer->_pClass, tbuff);
+	tbuff += 3;
+	CopyInt(&pPlayer->_pStrength, tbuff);
+	CopyInt(&pPlayer->_pBaseStr, tbuff);
+	CopyInt(&pPlayer->_pMagic, tbuff);
+	CopyInt(&pPlayer->_pBaseMag, tbuff);
+	CopyInt(&pPlayer->_pDexterity, tbuff);
+	CopyInt(&pPlayer->_pBaseDex, tbuff);
+	CopyInt(&pPlayer->_pVitality, tbuff);
+	CopyInt(&pPlayer->_pBaseVit, tbuff);
+	CopyInt(&pPlayer->_pStatPts, tbuff);
+	CopyInt(&pPlayer->_pDamageMod, tbuff);
+	CopyInt(&pPlayer->_pBaseToBlk, tbuff);
+	CopyInt(&pPlayer->_pHPBase, tbuff);
+	CopyInt(&pPlayer->_pMaxHPBase, tbuff);
+	CopyInt(&pPlayer->_pHitPoints, tbuff);
+	CopyInt(&pPlayer->_pMaxHP, tbuff);
+	CopyInt(&pPlayer->_pHPPer, tbuff);
+	CopyInt(&pPlayer->_pManaBase, tbuff);
+	CopyInt(&pPlayer->_pMaxManaBase, tbuff);
+	CopyInt(&pPlayer->_pMana, tbuff);
+	CopyInt(&pPlayer->_pMaxMana, tbuff);
+	CopyInt(&pPlayer->_pManaPer, tbuff);
+	CopyChar(&pPlayer->_pLevel, tbuff);
+	CopyChar(&pPlayer->_pMaxLvl, tbuff);
+	tbuff += 2;
+	CopyInt(&pPlayer->_pExperience, tbuff);
+	CopyInt(&pPlayer->_pMaxExp, tbuff);
+	CopyInt(&pPlayer->_pNextExper, tbuff);
+	CopyChar(&pPlayer->_pArmorClass, tbuff);
+	CopyChar(&pPlayer->_pMagResist, tbuff);
+	CopyChar(&pPlayer->_pFireResist, tbuff);
+	CopyChar(&pPlayer->_pLghtResist, tbuff);
+	CopyInt(&pPlayer->_pGold, tbuff);
+	CopyInt(&pPlayer->_pInfraFlag, tbuff);
+	CopyInt(&pPlayer->_pVar1, tbuff);
+	CopyInt(&pPlayer->_pVar2, tbuff);
+	CopyInt(&pPlayer->_pVar3, tbuff);
+	CopyInt(&pPlayer->_pVar4, tbuff);
+	CopyInt(&pPlayer->_pVar5, tbuff);
+	CopyInt(&pPlayer->_pVar6, tbuff);
+	CopyInt(&pPlayer->_pVar7, tbuff);
+	CopyInt(&pPlayer->_pVar8, tbuff);
+	CopyBytes(&pPlayer->_pLvlVisited, NUMLEVELS, tbuff);
+	CopyBytes(&pPlayer->_pSLvlVisited, NUMLEVELS, tbuff); // only 10 used
+	tbuff += 2;
+	CopyInt(&pPlayer->_pGFXLoad, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+	CopyInt(&pPlayer->_pNFrames, tbuff);
+	CopyInt(&pPlayer->_pNWidth, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+
+	CopyInt(&pPlayer->_pWFrames, tbuff);
+	CopyInt(&pPlayer->_pWWidth, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+
+	CopyInt(&pPlayer->_pAFrames, tbuff);
+	CopyInt(&pPlayer->_pAWidth, tbuff);
+	CopyInt(&pPlayer->_pAFNum, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 24; // Skip 24 pointers
+
+	CopyInt(&pPlayer->_pSFrames, tbuff);
+	CopyInt(&pPlayer->_pSWidth, tbuff);
+	CopyInt(&pPlayer->_pSFNum, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+
+	CopyInt(&pPlayer->_pHFrames, tbuff);
+	CopyInt(&pPlayer->_pHWidth, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+
+	CopyInt(&pPlayer->_pDFrames, tbuff);
+	CopyInt(&pPlayer->_pDWidth, tbuff);
+
+	tbuff += sizeof(__uint32_t) * 8; // Skip 8 pointers
+
+	CopyInt(&pPlayer->_pBFrames, tbuff);
+	CopyInt(&pPlayer->_pBWidth, tbuff);
+	SaveItems(pPlayer->InvBody, NUM_INVLOC);
+	SaveItems(pPlayer->InvList, NUM_INV_GRID_ELEM);
+	CopyInt(&pPlayer->_pNumInv, tbuff);
+	CopyBytes(pPlayer->InvGrid, NUM_INV_GRID_ELEM, tbuff);
+	SaveItems(pPlayer->SpdList, MAXBELTITEMS);
+	SaveItem(&pPlayer->HoldItem);
+	CopyInt(&pPlayer->_pIMinDam, tbuff);
+	CopyInt(&pPlayer->_pIMaxDam, tbuff);
+	CopyInt(&pPlayer->_pIAC, tbuff);
+	CopyInt(&pPlayer->_pIBonusDam, tbuff);
+	CopyInt(&pPlayer->_pIBonusToHit, tbuff);
+	CopyInt(&pPlayer->_pIBonusAC, tbuff);
+	CopyInt(&pPlayer->_pIBonusDamMod, tbuff);
+	tbuff += 4;
+	CopyInt64(&pPlayer->_pISpells, tbuff);
+	CopyInt(&pPlayer->_pIFlags, tbuff);
+	CopyInt(&pPlayer->_pIGetHit, tbuff);
+
+	CopyChar(&pPlayer->_pISplLvlAdd, tbuff);
+	CopyChar(&pPlayer->_pISplCost, tbuff);
+	tbuff += 2;
+
+	CopyInt(&pPlayer->_pISplDur, tbuff);
+	CopyInt(&pPlayer->_pIEnAc, tbuff);
+	CopyInt(&pPlayer->_pIFMinDam, tbuff);
+	CopyInt(&pPlayer->_pIFMaxDam, tbuff);
+	CopyInt(&pPlayer->_pILMinDam, tbuff);
+	CopyInt(&pPlayer->_pILMaxDam, tbuff);
+	CopyInt(&pPlayer->_pOilType, tbuff);
+
+	CopyChar(&pPlayer->pTownWarps, tbuff);
+	CopyChar(&pPlayer->pDungMsgs, tbuff);
+	CopyChar(&pPlayer->pLvlLoad, tbuff);
+	CopyChar(&pPlayer->pBattleNet, tbuff);
+
+	CopyChar(&pPlayer->pManaShield, tbuff);
+	CopyBytes(&pPlayer->bReserved, 3, tbuff);
+
+	CopyShorts(&pPlayer->wReserved, 8, tbuff);
+
+	CopyInt(&pPlayer->pDiabloKillLevel, tbuff);
+	CopyInts(&pPlayer->dwReserved, 7, tbuff);
+
+	// Omit 10 pointers
+	
 }
 
 void LoadMonster(int i)
 {
-	memcpy(&monster[i], tbuff, sizeof(*monster) - (3 * sizeof(void *)));
-	tbuff += sizeof(*monster) - (3 * sizeof(void *)); // omit last 3 pointers
+	MonsterStruct *pMonster = &monster[i];
+
+	CopyInt(tbuff, &pMonster->_mMTidx);
+	CopyInt(tbuff, &pMonster->_mmode);
+
+	CopyChar(tbuff, &pMonster->_mgoal);
+	tbuff += 3;
+
+	CopyInt(tbuff, &pMonster->_mgoalvar1);
+	CopyInt(tbuff, &pMonster->_mgoalvar2);
+	CopyInt(tbuff, &pMonster->_mgoalvar3);
+	CopyInt(tbuff, &pMonster->field_18);
+
+	CopyChar(tbuff, &pMonster->_pathcount);
+	tbuff += 3;
+
+	CopyInt(tbuff, &pMonster->_mx);
+	CopyInt(tbuff, &pMonster->_my);
+	CopyInt(tbuff, &pMonster->_mfutx);
+	CopyInt(tbuff, &pMonster->_mfuty);
+	CopyInt(tbuff, &pMonster->_moldx);
+	CopyInt(tbuff, &pMonster->_moldy);
+	CopyInt(tbuff, &pMonster->_mxoff);
+	CopyInt(tbuff, &pMonster->_myoff);
+	CopyInt(tbuff, &pMonster->_mxvel);
+	CopyInt(tbuff, &pMonster->_myvel);
+	CopyInt(tbuff, &pMonster->_mdir);
+	CopyInt(tbuff, &pMonster->_menemy);
+
+	CopyChar(tbuff, &pMonster->_menemyx);
+	CopyChar(tbuff, &pMonster->_menemyy);
+	CopyShort(tbuff, &pMonster->falign_52);
+
+	tbuff += 4; // Skip pointer
+	CopyInt(tbuff, &pMonster->_mAnimDelay);
+	CopyInt(tbuff, &pMonster->_mAnimCnt);
+	CopyInt(tbuff, &pMonster->_mAnimLen);
+	CopyInt(tbuff, &pMonster->_mAnimFrame);
+	CopyInt(tbuff, &pMonster->_meflag);
+	CopyInt(tbuff, &pMonster->_mDelFlag);
+	CopyInt(tbuff, &pMonster->_mVar1);
+	CopyInt(tbuff, &pMonster->_mVar2);
+	CopyInt(tbuff, &pMonster->_mVar3);
+	CopyInt(tbuff, &pMonster->_mVar4);
+	CopyInt(tbuff, &pMonster->_mVar5);
+	CopyInt(tbuff, &pMonster->_mVar6);
+	CopyInt(tbuff, &pMonster->_mVar7);
+	CopyInt(tbuff, &pMonster->_mVar8);
+	CopyInt(tbuff, &pMonster->_mmaxhp);
+	CopyInt(tbuff, &pMonster->_mhitpoints);
+
+	CopyChar(tbuff, &pMonster->_mAi);
+	CopyChar(tbuff, &pMonster->_mint);
+	CopyShort(tbuff, &pMonster->falign_9A);
+
+	CopyInt(tbuff, &pMonster->_mFlags);
+
+	CopyChar(tbuff, &pMonster->_msquelch);
+	tbuff += 3;
+
+	CopyInt(tbuff, &pMonster->falign_A4);
+	CopyInt(tbuff, &pMonster->_lastx);
+	CopyInt(tbuff, &pMonster->_lasty);
+	CopyInt(tbuff, &pMonster->_mRndSeed);
+	CopyInt(tbuff, &pMonster->_mAISeed);
+	CopyInt(tbuff, &pMonster->falign_B8);
+
+	CopyChar(tbuff, &pMonster->_uniqtype);
+	CopyChar(tbuff, &pMonster->_uniqtrans);
+	CopyChar(tbuff, &pMonster->_udeadval);
+	CopyChar(tbuff, &pMonster->mWhoHit);
+
+	CopyChar(tbuff, &pMonster->mLevel);
+	tbuff += 1;
+	CopyShort(tbuff, &pMonster->mExp);
+	
+	CopyChar(tbuff, &pMonster->mHit);
+	CopyChar(tbuff, &pMonster->mMinDamage);
+	CopyChar(tbuff, &pMonster->mMaxDamage);
+	CopyChar(tbuff, &pMonster->mHit2);
+	
+	CopyChar(tbuff, &pMonster->mMinDamage2);
+	CopyChar(tbuff, &pMonster->mMaxDamage2);
+	CopyChar(tbuff, &pMonster->mArmorClass);
+	CopyChar(tbuff, &pMonster->falign_CB);
+	
+	CopyShort(tbuff, &pMonster->mMagicRes);
+	tbuff += 2;
+
+	CopyInt(tbuff, &pMonster->mtalkmsg);
+
+	CopyChar(tbuff, &pMonster->leader);
+	CopyChar(tbuff, &pMonster->leaderflag);
+	CopyChar(tbuff, &pMonster->packsize);
+	CopyChar(tbuff, &pMonster->mlid);
+	
 	SyncMonsterAnim(i);
 }
 
 void LoadMissile(int i)
 {
-	memcpy(&missile[i], tbuff, sizeof(*missile));
-	tbuff += sizeof(*missile);
+	MissileStruct *pMissile = &missile[i];
+
+	CopyInt(tbuff, &pMissile->_mitype);
+	CopyInt(tbuff, &pMissile->_mix);
+	CopyInt(tbuff, &pMissile->_miy);
+	CopyInt(tbuff, &pMissile->_mixoff);
+	CopyInt(tbuff, &pMissile->_miyoff);
+	CopyInt(tbuff, &pMissile->_mixvel);
+	CopyInt(tbuff, &pMissile->_miyvel);
+	CopyInt(tbuff, &pMissile->_misx);
+	CopyInt(tbuff, &pMissile->_misy);
+	CopyInt(tbuff, &pMissile->_mitxoff);
+	CopyInt(tbuff, &pMissile->_mityoff);
+	CopyInt(tbuff, &pMissile->_mimfnum);
+	CopyInt(tbuff, &pMissile->_mispllvl);
+	CopyInt(tbuff, &pMissile->_miDelFlag);
+	CopyChar(tbuff, &pMissile->_miAnimType);
+	tbuff += 3;
+	
+	CopyInt(tbuff, &pMissile->_miAnimFlags);
+	tbuff += 4;
+	CopyInt(tbuff, &pMissile->_miAnimDelay);
+	CopyInt(tbuff, &pMissile->_miAnimLen);
+	CopyInt(tbuff, &pMissile->_miAnimWidth);
+	CopyInt(tbuff, &pMissile->_miAnimWidth2);
+	CopyInt(tbuff, &pMissile->_miAnimCnt);
+	CopyInt(tbuff, &pMissile->_miAnimAdd);
+	CopyInt(tbuff, &pMissile->_miAnimFrame);
+	CopyInt(tbuff, &pMissile->_miDrawFlag);
+	CopyInt(tbuff, &pMissile->_miLightFlag);
+	CopyInt(tbuff, &pMissile->_miPreFlag);
+	CopyInt(tbuff, &pMissile->_miUniqTrans);
+	CopyInt(tbuff, &pMissile->_mirange);
+	CopyInt(tbuff, &pMissile->_misource);
+	CopyInt(tbuff, &pMissile->_micaster);
+	CopyInt(tbuff, &pMissile->_midam);
+	CopyInt(tbuff, &pMissile->_miHitFlag);
+	CopyInt(tbuff, &pMissile->_midist);
+	CopyInt(tbuff, &pMissile->_mlid);
+	CopyInt(tbuff, &pMissile->_mirnd);
+	CopyInt(tbuff, &pMissile->_miVar1);
+	CopyInt(tbuff, &pMissile->_miVar2);
+	CopyInt(tbuff, &pMissile->_miVar3);
+	CopyInt(tbuff, &pMissile->_miVar4);
+	CopyInt(tbuff, &pMissile->_miVar5);
+	CopyInt(tbuff, &pMissile->_miVar6);
+	CopyInt(tbuff, &pMissile->_miVar7);
+	CopyInt(tbuff, &pMissile->_miVar8);
 }
 
 void LoadObject(int i)
 {
-	memcpy(&object[i], tbuff, sizeof(*object));
-	tbuff += sizeof(*object);
+	ObjectStruct *pObject = &object[i];
+	CopyInt(tbuff, &pObject->_otype);
+	CopyInt(tbuff, &pObject->_ox);
+	CopyInt(tbuff, &pObject->_oy);
+	CopyInt(tbuff, &pObject->_oLight);
+	CopyInt(tbuff, &pObject->_oAnimFlag);
+	tbuff += 4;
+	CopyInt(tbuff, &pObject->_oAnimDelay);
+	CopyInt(tbuff, &pObject->_oAnimCnt);
+	CopyInt(tbuff, &pObject->_oAnimLen);
+	CopyInt(tbuff, &pObject->_oAnimFrame);
+	CopyInt(tbuff, &pObject->_oAnimWidth);
+	CopyInt(tbuff, &pObject->_oAnimWidth2);
+	CopyInt(tbuff, &pObject->_oDelFlag);
+
+	CopyChar(tbuff, &pObject->_oBreak);
+	tbuff += 3;
+
+	CopyInt(tbuff, &pObject->_oSolidFlag);
+	CopyInt(tbuff, &pObject->_oMissFlag);
+
+	CopyChar(tbuff, &pObject->_oSelFlag); 
+	tbuff += 3;
+
+	CopyInt(tbuff, &pObject->_oPreFlag);
+	CopyInt(tbuff, &pObject->_oTrapFlag);
+	CopyInt(tbuff, &pObject->_oDoorFlag);
+	CopyInt(tbuff, &pObject->_olid);
+	CopyInt(tbuff, &pObject->_oRndSeed);
+	CopyInt(tbuff, &pObject->_oVar1);
+	CopyInt(tbuff, &pObject->_oVar2);
+	CopyInt(tbuff, &pObject->_oVar3);
+	CopyInt(tbuff, &pObject->_oVar4);
+	CopyInt(tbuff, &pObject->_oVar5);
+	CopyInt(tbuff, &pObject->_oVar6);
+	CopyInt(tbuff, &pObject->_oVar7);
+	CopyInt(tbuff, &pObject->_oVar8);
 }
 
 void LoadItem(int i)
 {
-	memcpy(&item[i], tbuff, sizeof(*item));
-	tbuff += sizeof(*item);
+	CopyItem(&item[i]);
 	GetItemFrm(i);
 }
 
+void CopyItem(ItemStruct *pItem)
+{
+	CopyInt(tbuff, &pItem->_iSeed);
+	CopyShort(tbuff, &pItem->_iCreateInfo);
+	tbuff += 2;
+	CopyInt(tbuff, &pItem->_itype);
+	CopyInt(tbuff, &pItem->_ix);
+	CopyInt(tbuff, &pItem->_iy);
+	CopyInt(tbuff, &pItem->_iAnimFlag);
+	tbuff += 4; // Skip pointer _iAnimData
+	CopyInt(tbuff, &pItem->_iAnimLen);
+	CopyInt(tbuff, &pItem->_iAnimFrame);
+	CopyInt(tbuff, &pItem->_iAnimWidth);
+	CopyInt(tbuff, &pItem->_iAnimWidth2);
+	CopyInt(tbuff, &pItem->_isin);
+	CopyChar(tbuff, &pItem->_iSelFlag);
+	tbuff += 3;
+	CopyInt(tbuff, &pItem->_iPostDraw);
+	CopyInt(tbuff, &pItem->_iIdentified);
+	CopyChar(tbuff, &pItem->_iMagical);
+	CopyBytes(tbuff, 64, &pItem->_iName);
+	CopyBytes(tbuff, 64, &pItem->_iIName);
+	CopyChar(tbuff, &pItem->_iLoc);
+	CopyChar(tbuff, &pItem->_iClass);
+	tbuff += 1;
+	CopyInt(tbuff, &pItem->_iCurs);
+	CopyInt(tbuff, &pItem->_ivalue);
+	CopyInt(tbuff, &pItem->_iIvalue);
+	CopyInt(tbuff, &pItem->_iMinDam);
+	CopyInt(tbuff, &pItem->_iMaxDam);
+	CopyInt(tbuff, &pItem->_iAC);
+	CopyInt(tbuff, &pItem->_iFlags);
+	CopyInt(tbuff, &pItem->_iMiscId);
+	CopyInt(tbuff, &pItem->_iSpell);
+	CopyInt(tbuff, &pItem->_iCharges);
+	CopyInt(tbuff, &pItem->_iMaxCharges);
+	CopyInt(tbuff, &pItem->_iDurability);
+	CopyInt(tbuff, &pItem->_iMaxDur);
+	CopyInt(tbuff, &pItem->_iPLDam);
+	CopyInt(tbuff, &pItem->_iPLToHit);
+	CopyInt(tbuff, &pItem->_iPLAC);
+	CopyInt(tbuff, &pItem->_iPLStr);
+	CopyInt(tbuff, &pItem->_iPLMag);
+	CopyInt(tbuff, &pItem->_iPLDex);
+	CopyInt(tbuff, &pItem->_iPLVit);
+	CopyInt(tbuff, &pItem->_iPLFR);
+	CopyInt(tbuff, &pItem->_iPLLR);
+	CopyInt(tbuff, &pItem->_iPLMR);
+	CopyInt(tbuff, &pItem->_iPLMana);
+	CopyInt(tbuff, &pItem->_iPLHP);
+	CopyInt(tbuff, &pItem->_iPLDamMod);
+	CopyInt(tbuff, &pItem->_iPLGetHit);
+	CopyInt(tbuff, &pItem->_iPLLight);
+	CopyChar(tbuff, &pItem->_iSplLvlAdd);
+	CopyChar(tbuff, &pItem->_iRequest);
+	tbuff += 2;
+	CopyInt(tbuff, &pItem->_iUid);
+	CopyInt(tbuff, &pItem->_iFMinDam);
+	CopyInt(tbuff, &pItem->_iFMaxDam);
+	CopyInt(tbuff, &pItem->_iLMinDam);
+	CopyInt(tbuff, &pItem->_iLMaxDam);
+	CopyInt(tbuff, &pItem->_iPLEnAc);
+	CopyChar(tbuff, &pItem->_iPrePower);
+	CopyChar(tbuff, &pItem->_iSufPower);
+	tbuff += 2;
+	CopyInt(tbuff, &pItem->_iVAdd1);
+	CopyInt(tbuff, &pItem->_iVMult1);
+	CopyInt(tbuff, &pItem->_iVAdd2);
+	CopyInt(tbuff, &pItem->_iVMult2);
+	CopyChar(tbuff, &pItem->_iMinStr);
+	CopyChar(tbuff, &pItem->_iMinMag);
+	CopyChar(tbuff, &pItem->_iMinDex);
+	tbuff += 1;
+	CopyInt(tbuff, &pItem->_iStatFlag);
+	CopyInt(tbuff, &pItem->IDidx);
+	CopyInt(tbuff, &pItem->offs016C);
+}
+
+void CopyItems(const int n, ItemStruct *pItem)
+{
+	for (int i = 0; i < n; i++)
+	{
+		CopyItem(&pItem[i]);
+	}
+}
+
+void SaveItem(ItemStruct *pItem)
+{
+	CopyInt(&pItem->_iSeed, tbuff);
+	CopyShort(&pItem->_iCreateInfo, tbuff);
+	tbuff += 2;
+	CopyInt(&pItem->_itype, tbuff);
+	CopyInt(&pItem->_ix, tbuff);
+	CopyInt(&pItem->_iy, tbuff);
+	CopyInt(&pItem->_iAnimFlag, tbuff);
+	tbuff += 4; // Skip pointer _iAnimData
+	CopyInt(&pItem->_iAnimLen, tbuff);
+	CopyInt(&pItem->_iAnimFrame, tbuff);
+	CopyInt(&pItem->_iAnimWidth, tbuff);
+	CopyInt(&pItem->_iAnimWidth2, tbuff); // width 2?
+	CopyInt(&pItem->_isin, tbuff);        // set when item is flagged for deletion, deprecated in 1.02
+	CopyChar(&pItem->_iSelFlag, tbuff);
+	tbuff += 3;
+	CopyInt(&pItem->_iPostDraw, tbuff);
+	CopyInt(&pItem->_iIdentified, tbuff);
+	CopyChar(&pItem->_iMagical, tbuff);
+	CopyBytes(&pItem->_iName, 64, tbuff);
+	CopyBytes(&pItem->_iIName, 64, tbuff);
+	CopyChar(&pItem->_iLoc, tbuff);
+	CopyChar(&pItem->_iClass, tbuff);
+	tbuff += 1;
+	CopyInt(&pItem->_iCurs, tbuff);
+	CopyInt(&pItem->_ivalue, tbuff);
+	CopyInt(&pItem->_iIvalue, tbuff);
+	CopyInt(&pItem->_iMinDam, tbuff);
+	CopyInt(&pItem->_iMaxDam, tbuff);
+	CopyInt(&pItem->_iAC, tbuff);
+	CopyInt(&pItem->_iFlags, tbuff);
+	CopyInt(&pItem->_iMiscId, tbuff);
+	CopyInt(&pItem->_iSpell, tbuff);
+	CopyInt(&pItem->_iCharges, tbuff);
+	CopyInt(&pItem->_iMaxCharges, tbuff);
+	CopyInt(&pItem->_iDurability, tbuff);
+	CopyInt(&pItem->_iMaxDur, tbuff);
+	CopyInt(&pItem->_iPLDam, tbuff);
+	CopyInt(&pItem->_iPLToHit, tbuff);
+	CopyInt(&pItem->_iPLAC, tbuff);
+	CopyInt(&pItem->_iPLStr, tbuff);
+	CopyInt(&pItem->_iPLMag, tbuff);
+	CopyInt(&pItem->_iPLDex, tbuff);
+	CopyInt(&pItem->_iPLVit, tbuff);
+	CopyInt(&pItem->_iPLFR, tbuff);
+	CopyInt(&pItem->_iPLLR, tbuff);
+	CopyInt(&pItem->_iPLMR, tbuff);
+	CopyInt(&pItem->_iPLMana, tbuff);
+	CopyInt(&pItem->_iPLHP, tbuff);
+	CopyInt(&pItem->_iPLDamMod, tbuff);
+	CopyInt(&pItem->_iPLGetHit, tbuff);
+	CopyInt(&pItem->_iPLLight, tbuff);
+	CopyChar(&pItem->_iSplLvlAdd, tbuff);
+	CopyChar(&pItem->_iRequest, tbuff);
+	tbuff += 2;
+	CopyInt(&pItem->_iUid, tbuff);
+	CopyInt(&pItem->_iFMinDam, tbuff);
+	CopyInt(&pItem->_iFMaxDam, tbuff);
+	CopyInt(&pItem->_iLMinDam, tbuff);
+	CopyInt(&pItem->_iLMaxDam, tbuff);
+	CopyInt(&pItem->_iPLEnAc, tbuff);
+	CopyChar(&pItem->_iPrePower, tbuff);
+	CopyChar(&pItem->_iSufPower, tbuff);
+	tbuff += 2;
+	CopyInt(&pItem->_iVAdd1, tbuff);
+	CopyInt(&pItem->_iVMult1, tbuff);
+	CopyInt(&pItem->_iVAdd2, tbuff);
+	CopyInt(&pItem->_iVMult2, tbuff);
+	CopyChar(&pItem->_iMinStr, tbuff);
+	CopyChar(&pItem->_iMinMag, tbuff);
+	CopyChar(&pItem->_iMinDex, tbuff);
+	tbuff += 1;
+	CopyInt(&pItem->_iStatFlag, tbuff);
+	CopyInt(&pItem->IDidx, tbuff);
+	CopyInt(&pItem->offs016C, tbuff);
+}
+
+void SaveItems(ItemStruct *pItem, const int n)
+{
+	for (int i = 0; i < n; i++)
+	{
+		SaveItem(&pItem[i]);
+	}
+}
+
 void LoadPremium(int i)
 {
-	memcpy(&premiumitem[i], tbuff, sizeof(*premiumitem));
-	tbuff += sizeof(*premiumitem);
+	CopyItem(&item[i]);
 }
 
 void LoadQuest(int i)
@@ -348,7 +1135,7 @@ void SaveGame()
 	for (i = 0; i < MAXITEMS; i++)
 		BSave(itemavail[i]);
 	for (i = 0; i < numitems; i++)
-		SaveItem(itemactive[i]);
+		SaveItem(&item[itemactive[i]]);
 	for (i = 0; i < 128; i++)
 		OSave(UniqueItemFlag[i]);
 
@@ -446,40 +1233,201 @@ void OSave(BOOL v)
 		*tbuff++ = FALSE;
 }
 
-void SavePlayer(int i)
-{
-	memcpy(tbuff, &plr[i], sizeof(*plr) - (10 * sizeof(void *)));
-	tbuff += sizeof(*plr) - (10 * sizeof(void *)); // omit last 10 pointers
-}
-
 void SaveMonster(int i)
 {
-	memcpy(tbuff, &monster[i], sizeof(*monster) - (3 * sizeof(void *)));
-	tbuff += sizeof(*monster) - (3 * sizeof(void *)); // omit last 3 pointers
+	MonsterStruct *pMonster = &monster[i];
+
+	CopyInt(&pMonster->_mMTidx, tbuff);
+	CopyInt(&pMonster->_mmode, tbuff);
+
+	CopyChar(&pMonster->_mgoal, tbuff);
+	tbuff += 3;
+
+	CopyInt(&pMonster->_mgoalvar1, tbuff);
+	CopyInt(&pMonster->_mgoalvar2, tbuff);
+	CopyInt(&pMonster->_mgoalvar3, tbuff);
+	CopyInt(&pMonster->field_18, tbuff);
+
+	CopyChar(&pMonster->_pathcount, tbuff);
+	tbuff += 3;
+
+	CopyInt(&pMonster->_mx, tbuff);
+	CopyInt(&pMonster->_my, tbuff);
+	CopyInt(&pMonster->_mfutx, tbuff);
+	CopyInt(&pMonster->_mfuty, tbuff);
+	CopyInt(&pMonster->_moldx, tbuff);
+	CopyInt(&pMonster->_moldy, tbuff);
+	CopyInt(&pMonster->_mxoff, tbuff);
+	CopyInt(&pMonster->_myoff, tbuff);
+	CopyInt(&pMonster->_mxvel, tbuff);
+	CopyInt(&pMonster->_myvel, tbuff);
+	CopyInt(&pMonster->_mdir, tbuff);
+	CopyInt(&pMonster->_menemy, tbuff);
+
+	CopyChar(&pMonster->_menemyx, tbuff);
+	CopyChar(&pMonster->_menemyy, tbuff);
+	CopyShort(&pMonster->falign_52, tbuff);
+
+	tbuff += 4; // Skip pointer
+	CopyInt(&pMonster->_mAnimDelay, tbuff);
+	CopyInt(&pMonster->_mAnimCnt, tbuff);
+	CopyInt(&pMonster->_mAnimLen, tbuff);
+	CopyInt(&pMonster->_mAnimFrame, tbuff);
+	CopyInt(&pMonster->_meflag, tbuff);
+	CopyInt(&pMonster->_mDelFlag, tbuff);
+	CopyInt(&pMonster->_mVar1, tbuff);
+	CopyInt(&pMonster->_mVar2, tbuff);
+	CopyInt(&pMonster->_mVar3, tbuff);
+	CopyInt(&pMonster->_mVar4, tbuff);
+	CopyInt(&pMonster->_mVar5, tbuff);
+	CopyInt(&pMonster->_mVar6, tbuff);
+	CopyInt(&pMonster->_mVar7, tbuff);
+	CopyInt(&pMonster->_mVar8, tbuff);
+	CopyInt(&pMonster->_mmaxhp, tbuff);
+	CopyInt(&pMonster->_mhitpoints, tbuff);
+
+	CopyChar(&pMonster->_mAi, tbuff);
+	CopyChar(&pMonster->_mint, tbuff);
+	CopyShort(&pMonster->falign_9A, tbuff);
+
+	CopyInt(&pMonster->_mFlags, tbuff);
+
+	CopyChar(&pMonster->_msquelch, tbuff);
+	tbuff += 3;
+
+	CopyInt(&pMonster->falign_A4, tbuff);
+	CopyInt(&pMonster->_lastx, tbuff);
+	CopyInt(&pMonster->_lasty, tbuff);
+	CopyInt(&pMonster->_mRndSeed, tbuff);
+	CopyInt(&pMonster->_mAISeed, tbuff);
+	CopyInt(&pMonster->falign_B8, tbuff);
+
+	CopyChar(&pMonster->_uniqtype, tbuff);
+	CopyChar(&pMonster->_uniqtrans, tbuff);
+	CopyChar(&pMonster->_udeadval, tbuff);
+	CopyChar(&pMonster->mWhoHit, tbuff);
+
+	CopyChar(&pMonster->mLevel, tbuff);
+	tbuff += 1;
+	CopyShort(&pMonster->mExp, tbuff);
+	
+	CopyChar(&pMonster->mHit, tbuff);
+	CopyChar(&pMonster->mMinDamage, tbuff);
+	CopyChar(&pMonster->mMaxDamage, tbuff);
+	CopyChar(&pMonster->mHit2, tbuff);
+	
+	CopyChar(&pMonster->mMinDamage2, tbuff);
+	CopyChar(&pMonster->mMaxDamage2, tbuff);
+	CopyChar(&pMonster->mArmorClass, tbuff);
+	CopyChar(&pMonster->falign_CB, tbuff);
+	
+	CopyShort(&pMonster->mMagicRes, tbuff);
+	tbuff += 2;
+
+	CopyInt(&pMonster->mtalkmsg, tbuff);
+
+	CopyChar(&pMonster->leader, tbuff);
+	CopyChar(&pMonster->leaderflag, tbuff);
+	CopyChar(&pMonster->packsize, tbuff);
+	CopyChar(&pMonster->mlid, tbuff);
 }
 
 void SaveMissile(int i)
 {
-	memcpy(tbuff, &missile[i], sizeof(*missile));
-	tbuff += sizeof(*missile);
-}
+	MissileStruct *pMissile = &missile[i];
 
-void SaveObject(int i)
-{
-	memcpy(tbuff, &object[i], sizeof(*object));
-	tbuff += sizeof(*object);
+	CopyInt(&pMissile->_mitype, tbuff);
+	CopyInt(&pMissile->_mix, tbuff);
+	CopyInt(&pMissile->_miy, tbuff);
+	CopyInt(&pMissile->_mixoff, tbuff);
+	CopyInt(&pMissile->_miyoff, tbuff);
+	CopyInt(&pMissile->_mixvel, tbuff);
+	CopyInt(&pMissile->_miyvel, tbuff);
+	CopyInt(&pMissile->_misx, tbuff);
+	CopyInt(&pMissile->_misy, tbuff);
+	CopyInt(&pMissile->_mitxoff, tbuff);
+	CopyInt(&pMissile->_mityoff, tbuff);
+	CopyInt(&pMissile->_mimfnum, tbuff);
+	CopyInt(&pMissile->_mispllvl, tbuff);
+	CopyInt(&pMissile->_miDelFlag, tbuff);
+	CopyChar(&pMissile->_miAnimType, tbuff);
+	tbuff += 3;
+	
+	CopyInt(&pMissile->_miAnimFlags, tbuff);
+	tbuff += 4;
+	CopyInt(&pMissile->_miAnimDelay, tbuff);
+	CopyInt(&pMissile->_miAnimLen, tbuff);
+	CopyInt(&pMissile->_miAnimWidth, tbuff);
+	CopyInt(&pMissile->_miAnimWidth2, tbuff);
+	CopyInt(&pMissile->_miAnimCnt, tbuff);
+	CopyInt(&pMissile->_miAnimAdd, tbuff);
+	CopyInt(&pMissile->_miAnimFrame, tbuff);
+	CopyInt(&pMissile->_miDrawFlag, tbuff);
+	CopyInt(&pMissile->_miLightFlag, tbuff);
+	CopyInt(&pMissile->_miPreFlag, tbuff);
+	CopyInt(&pMissile->_miUniqTrans, tbuff);
+	CopyInt(&pMissile->_mirange, tbuff);
+	CopyInt(&pMissile->_misource, tbuff);
+	CopyInt(&pMissile->_micaster, tbuff);
+	CopyInt(&pMissile->_midam, tbuff);
+	CopyInt(&pMissile->_miHitFlag, tbuff);
+	CopyInt(&pMissile->_midist, tbuff);
+	CopyInt(&pMissile->_mlid, tbuff);
+	CopyInt(&pMissile->_mirnd, tbuff);
+	CopyInt(&pMissile->_miVar1, tbuff);
+	CopyInt(&pMissile->_miVar2, tbuff);
+	CopyInt(&pMissile->_miVar3, tbuff);
+	CopyInt(&pMissile->_miVar4, tbuff);
+	CopyInt(&pMissile->_miVar5, tbuff);
+	CopyInt(&pMissile->_miVar6, tbuff);
+	CopyInt(&pMissile->_miVar7, tbuff);
+	CopyInt(&pMissile->_miVar8, tbuff);
 }
 
-void SaveItem(int i)
+void SaveObject(int i)
 {
-	memcpy(tbuff, &item[i], sizeof(*item));
-	tbuff += sizeof(*item);
+	ObjectStruct *pObject = &object[i];
+	CopyInt(tbuff, &pObject->_otype);
+	CopyInt(&pObject->_ox, tbuff);
+	CopyInt(&pObject->_oy, tbuff);
+	CopyInt(&pObject->_oLight, tbuff);
+	CopyInt(&pObject->_oAnimFlag, tbuff);
+	tbuff += 4;
+	CopyInt(&pObject->_oAnimDelay, tbuff);
+	CopyInt(&pObject->_oAnimCnt, tbuff);
+	CopyInt(&pObject->_oAnimLen, tbuff);
+	CopyInt(&pObject->_oAnimFrame, tbuff);
+	CopyInt(&pObject->_oAnimWidth, tbuff);
+	CopyInt(&pObject->_oAnimWidth2, tbuff);
+	CopyInt(&pObject->_oDelFlag, tbuff);
+
+	CopyChar(&pObject->_oBreak, tbuff);
+	tbuff += 3;
+
+	CopyInt(&pObject->_oSolidFlag, tbuff);
+	CopyInt(&pObject->_oMissFlag, tbuff);
+
+	CopyChar(&pObject->_oSelFlag, tbuff); 
+	tbuff += 3;
+
+	CopyInt(&pObject->_oPreFlag, tbuff);
+	CopyInt(&pObject->_oTrapFlag, tbuff);
+	CopyInt(&pObject->_oDoorFlag, tbuff);
+	CopyInt(&pObject->_olid, tbuff);
+	CopyInt(&pObject->_oRndSeed, tbuff);
+	CopyInt(&pObject->_oVar1, tbuff);
+	CopyInt(&pObject->_oVar2, tbuff);
+	CopyInt(&pObject->_oVar3, tbuff);
+	CopyInt(&pObject->_oVar4, tbuff);
+	CopyInt(&pObject->_oVar5, tbuff);
+	CopyInt(&pObject->_oVar6, tbuff);
+	CopyInt(&pObject->_oVar7, tbuff);
+	CopyInt(&pObject->_oVar8, tbuff);
 }
 
 void SavePremium(int i)
 {
-	memcpy(tbuff, &premiumitem[i], sizeof(*premiumitem));
-	tbuff += sizeof(*premiumitem);
+	SaveItem(&item[i]);
 }
 
 void SaveQuest(int i)
@@ -554,7 +1502,7 @@ void SaveLevel()
 	for (i = 0; i < MAXITEMS; i++)
 		BSave(itemavail[i]);
 	for (i = 0; i < numitems; i++)
-		SaveItem(itemactive[i]);
+		SaveItem(&item[itemactive[i]]);
 
 	for (j = 0; j < MAXDUNY; j++) {
 		for (i = 0; i < MAXDUNX; i++)
