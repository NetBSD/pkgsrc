$NetBSD: patch-drivers_auxiliary_wandererbox__plus__v3.cpp,v 1.1 2025/12/01 20:09:09 adam Exp $

Fix build with GCC.

--- drivers/auxiliary/wandererbox_plus_v3.cpp.orig	2025-12-01 19:59:06.856778958 +0000
+++ drivers/auxiliary/wandererbox_plus_v3.cpp
@@ -272,7 +272,7 @@ bool WandererBoxPlusV3::getData()
             DC3diffSP.setState(IPS_OK);
             DC3diffSP.apply();
         }
-        if (DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&isnan(ENVMonitorNP[DEW_Point].value)==1)
+        if (DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&std::isnan(ENVMonitorNP[DEW_Point].value)==1)
         {
             DC3DIFFMODE=false;
             DC3CONSTMODE=false;
@@ -530,7 +530,7 @@ bool WandererBoxPlusV3::ISNewSwitch(cons
     {
         DC3diffSP.update(states, names, n);
         DC3diffSP.setState(IPS_ALERT);
-        if(DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe1_Temp].value!=-127&&isnan(ENVMonitorNP[DEW_Point].value)==0)
+        if(DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe1_Temp].value!=-127&&std::isnan(ENVMonitorNP[DEW_Point].value)==0)
         {
             DC3DIFFMODE=true;
             DC3CONSTMODE=false;
@@ -545,7 +545,7 @@ bool WandererBoxPlusV3::ISNewSwitch(cons
             LOGF_INFO("Dew Point Difference Mode for DC3 activated! WandererBox will keep the dew heater at the temperature higher than the dew point by the set value.","Updated");
             return true;
         }
-        else if(DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe1_Temp].value==-127||isnan(ENVMonitorNP[DEW_Point].value)==1))
+        else if(DC3diffSP[DC3_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe1_Temp].value==-127||std::isnan(ENVMonitorNP[DEW_Point].value)==1))
         {
             DC3DIFFMODE=false;
             DC3CONSTMODE=false;
