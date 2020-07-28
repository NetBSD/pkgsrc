$NetBSD: patch-core_src_plugins_stored_scsitapealert-sd.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Tape alerts where not always gathered, add missing cases.

--- core/src/plugins/stored/scsitapealert-sd.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/plugins/stored/scsitapealert-sd.cc
@@ -126,8 +126,8 @@ static bRC newPlugin(bpContext* ctx)
    * Only register plugin events we are interested in.
    */
   bfuncs->registerBareosEvents(
-      ctx, 6, bsdEventVolumeLoad, bsdEventLabelVerified, bsdEventReadError,
-      bsdEventWriteError, bsdEventVolumeUnload, bsdEventDeviceRelease);
+      ctx, 7, bsdEventVolumeLoad, bsdEventLabelVerified, bsdEventReadError,
+      bsdEventWriteError, bsdEventVolumeLoad, bsdEventVolumeUnload, bsdEventDeviceRelease);
 
   return bRC_OK;
 }
@@ -174,7 +174,9 @@ static bRC handlePluginEvent(bpContext* 
     case bsdEventLabelVerified:
     case bsdEventReadError:
     case bsdEventWriteError:
+    case bsdEventVolumeLoad:
     case bsdEventVolumeUnload:
+    case bsdEventDeviceRelease:
       return handle_tapealert_readout(value);
     default:
       Dmsg1(debuglevel, "scsitapealert-sd: Unknown event %d\n",
