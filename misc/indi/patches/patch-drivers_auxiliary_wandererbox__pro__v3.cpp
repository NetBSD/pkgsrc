$NetBSD: patch-drivers_auxiliary_wandererbox__pro__v3.cpp,v 1.1 2025/12/01 20:09:09 adam Exp $

Fix build with GCC.

--- drivers/auxiliary/wandererbox_pro_v3.cpp.orig	2025-12-01 20:02:29.758734416 +0000
+++ drivers/auxiliary/wandererbox_pro_v3.cpp
@@ -416,7 +416,7 @@ bool WandererBoxProV3::getData()
             dc5diffSP.setState(IPS_OK);
             dc5diffSP.apply();
         }
-        if (dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&isnan(ENVMonitorNP[DEW_Point].value)==1)
+        if (dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&std::isnan(ENVMonitorNP[DEW_Point].value)==1)
         {
             DC5DIFFMODE=false;
             DC5CONSTMODE=false;
@@ -478,7 +478,7 @@ bool WandererBoxProV3::getData()
             dc6diffSP.setState(IPS_OK);
             dc6diffSP.apply();
         }
-        if (dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&isnan(ENVMonitorNP[DEW_Point].value)==1)
+        if (dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&std::isnan(ENVMonitorNP[DEW_Point].value)==1)
         {
             DC6DIFFMODE=false;
             DC6CONSTMODE=false;
@@ -539,7 +539,7 @@ bool WandererBoxProV3::getData()
             dc7diffSP.setState(IPS_OK);
             dc7diffSP.apply();
         }
-        if (dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&isnan(ENVMonitorNP[DEW_Point].value)==1)
+        if (dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&std::isnan(ENVMonitorNP[DEW_Point].value)==1)
         {
             DC7DIFFMODE=false;
             DC7CONSTMODE=false;
@@ -966,7 +966,7 @@ bool WandererBoxProV3::ISNewSwitch(const
     {
         dc5diffSP.update(states, names, n);
         dc5diffSP.setState(IPS_ALERT);
-        if(dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe1_Temp].value!=-127&&isnan(ENVMonitorNP[DEW_Point].value)==0)
+        if(dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe1_Temp].value!=-127&&std::isnan(ENVMonitorNP[DEW_Point].value)==0)
         {
             DC5DIFFMODE=true;
             DC5CONSTMODE=false;
@@ -981,7 +981,7 @@ bool WandererBoxProV3::ISNewSwitch(const
             LOGF_INFO("Dew Point Difference Mode for DC5 activated! WandererBox will keep the dew heater at the temperature higher than the dew point by the set value.","Updated");
             return true;
         }
-        else if(dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe1_Temp].value==-127||isnan(ENVMonitorNP[DEW_Point].value)==1))
+        else if(dc5diffSP[DC5_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe1_Temp].value==-127||std::isnan(ENVMonitorNP[DEW_Point].value)==1))
         {
             DC5DIFFMODE=false;
             DC5CONSTMODE=false;
@@ -1032,7 +1032,7 @@ bool WandererBoxProV3::ISNewSwitch(const
     {
         dc6diffSP.update(states, names, n);
         dc6diffSP.setState(IPS_ALERT);
-        if(dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe2_Temp].value!=-127&&isnan(ENVMonitorNP[DEW_Point].value)==0)
+        if(dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe2_Temp].value!=-127&&std::isnan(ENVMonitorNP[DEW_Point].value)==0)
         {
             DC6DIFFMODE=true;
             DC6CONSTMODE=false;
@@ -1047,7 +1047,7 @@ bool WandererBoxProV3::ISNewSwitch(const
             LOGF_INFO("Dew Point Difference Mode for DC6 activated! WandererBox will keep the dew heater at the temperature higher than the dew point by the set value.","Updated");
             return true;
         }
-        else if(dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe2_Temp].value==-127||isnan(ENVMonitorNP[DEW_Point].value)==1))
+        else if(dc6diffSP[DC6_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe2_Temp].value==-127||std::isnan(ENVMonitorNP[DEW_Point].value)==1))
         {
             DC6DIFFMODE=false;
             DC6CONSTMODE=false;
@@ -1098,7 +1098,7 @@ bool WandererBoxProV3::ISNewSwitch(const
     {
         dc7diffSP.update(states, names, n);
         dc7diffSP.setState(IPS_ALERT);
-        if(dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe3_Temp].value!=-127&&isnan(ENVMonitorNP[DEW_Point].value)==0)
+        if(dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&ENVMonitorNP[Probe3_Temp].value!=-127&&std::isnan(ENVMonitorNP[DEW_Point].value)==0)
         {
             DC7DIFFMODE=true;
             DC7CONSTMODE=false;
@@ -1113,7 +1113,7 @@ bool WandererBoxProV3::ISNewSwitch(const
             LOGF_INFO("Dew Point Difference Mode for DC7 activated! WandererBox will keep the dew heater at the temperature higher than the dew point by the set value.","Updated");
             return true;
         }
-        else if(dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe3_Temp].value==-127||isnan(ENVMonitorNP[DEW_Point].value)==1))
+        else if(dc7diffSP[DC7_DPD_Mode].getState() == ISS_ON&&(ENVMonitorNP[Probe3_Temp].value==-127||std::isnan(ENVMonitorNP[DEW_Point].value)==1))
         {
             DC7DIFFMODE=false;
             DC7CONSTMODE=false;
