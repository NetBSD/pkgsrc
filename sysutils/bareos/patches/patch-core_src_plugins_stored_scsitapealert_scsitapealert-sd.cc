$NetBSD: patch-core_src_plugins_stored_scsitapealert_scsitapealert-sd.cc,v 1.1 2021/02/01 09:08:43 kardel Exp $

	tape alerts where not always gathered, add missing cases.

--- core/src/plugins/stored/scsitapealert/scsitapealert-sd.cc.orig	2021-01-22 16:12:55.749020270 +0000
+++ core/src/plugins/stored/scsitapealert/scsitapealert-sd.cc
@@ -129,8 +129,8 @@ static bRC newPlugin(PluginContext* ctx)
    * Only register plugin events we are interested in.
    */
   bareos_core_functions->registerBareosEvents(
-      ctx, 6, bSdEventVolumeLoad, bSdEventLabelVerified, bSdEventReadError,
-      bSdEventWriteError, bSdEventVolumeUnload, bSdEventDeviceRelease);
+      ctx, 7, bSdEventVolumeLoad, bSdEventLabelVerified, bSdEventReadError,
+      bSdEventWriteError, bSdEventVolumeLoad, bSdEventVolumeUnload, bSdEventDeviceRelease);
 
   return bRC_OK;
 }
@@ -177,7 +177,9 @@ static bRC handlePluginEvent(PluginConte
     case bSdEventLabelVerified:
     case bSdEventReadError:
     case bSdEventWriteError:
+    case bSdEventVolumeLoad:
     case bSdEventVolumeUnload:
+    case bSdEventDeviceRelease:
       return handle_tapealert_readout(value);
     default:
       Dmsg1(debuglevel, "scsitapealert-sd: Unknown event %d\n",
