$NetBSD: patch-src_FDM_JSBSim_models_propulsion_FGEngine.cpp,v 1.1 2014/08/19 13:32:46 joerg Exp $

--- src/FDM/JSBSim/models/propulsion/FGEngine.cpp.orig	2014-08-19 13:11:25.000000000 +0000
+++ src/FDM/JSBSim/models/propulsion/FGEngine.cpp
@@ -83,7 +83,7 @@ FGEngine::FGEngine(FGFDMExec* exec, Elem
 
   Name = engine_element->GetAttributeValue("name");
 
-  Load(engine_element, PropertyManager, to_string(EngineNumber)); // Call ModelFunctions loader
+  Load(engine_element, PropertyManager, ::to_string(EngineNumber)); // Call ModelFunctions loader
 
 // Find and set engine location
 
@@ -132,7 +132,7 @@ FGEngine::FGEngine(FGFDMExec* exec, Elem
   property_name = base_property_name + "/fuel-used-lbs";
   PropertyManager->Tie( property_name.c_str(), this, &FGEngine::GetFuelUsedLbs);
 
-  PostLoad(engine_element, PropertyManager, to_string(EngineNumber));
+  PostLoad(engine_element, PropertyManager, ::to_string(EngineNumber));
 
   Debug(0);
 }
