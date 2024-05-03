$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.hpp,v 1.2 2024/05/03 12:07:41 wiz Exp $

Port code to INDI 2.0.2
https://github.com/Stellarium/stellarium/pull/3269/files

--- plugins/TelescopeControl/src/INDI/INDIConnection.hpp.orig	2024-02-04 13:27:52.000000000 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.hpp
@@ -21,6 +21,7 @@
 
 #include <QObject>
 #include "libindi/baseclient.h"
+#include <libindi/basedevice.h>
 
 #include <mutex>
 #include <QStringList>
@@ -64,21 +65,16 @@ private:
 	void setSpeed(int speed);
 
 	mutable std::mutex mMutex;
-	INDI::BaseDevice* mTelescope = nullptr;
+	INDI::BaseDevice mTelescope;
 	Coordinates mCoordinates;
 	QStringList mDevices;
 
 public: // from INDI::BaseClient
-	void newDevice(INDI::BaseDevice *dp) override;
-	void removeDevice(INDI::BaseDevice *dp) override;
-	void newProperty(INDI::Property *property) override;
-	void removeProperty(INDI::Property *property) override;
-	void newBLOB(IBLOB *bp) override;
-	void newSwitch(ISwitchVectorProperty *svp) override;
-	void newNumber(INumberVectorProperty *nvp) override;
-	void newText(ITextVectorProperty *tvp) override;
-	void newLight(ILightVectorProperty *lvp) override;
-	void newMessage(INDI::BaseDevice *dp, int messageID) override;
+	void newDevice(INDI::BaseDevice dp) override;
+	void removeDevice(INDI::BaseDevice dp) override;
+	void newProperty(INDI::Property property) override;
+	void removeProperty(INDI::Property property) override;
+	void newMessage(INDI::BaseDevice dp, int messageID) override;
 	void serverConnected() override;
 	void serverDisconnected(int exit_code) override;
 	void unParkTelescope();
