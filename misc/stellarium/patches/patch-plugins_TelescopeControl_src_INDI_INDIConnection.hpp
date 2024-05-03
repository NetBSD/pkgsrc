$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.hpp,v 1.1 2024/05/03 11:28:27 wiz Exp $

Compatibility with indi 2.0.7.

--- plugins/TelescopeControl/src/INDI/INDIConnection.hpp.orig	2024-05-03 11:24:20.270404353 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.hpp
@@ -69,18 +69,18 @@ private:
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
-	void serverConnected() override;
-	void serverDisconnected(int exit_code) override;
+	void newDevice(INDI::BaseDevice *dp);
+	void removeDevice(INDI::BaseDevice *dp);
+	void newProperty(INDI::Property *property);
+	void removeProperty(INDI::Property *property);
+	void newBLOB(IBLOB *bp);
+	void newSwitch(ISwitchVectorProperty *svp);
+	void newNumber(INumberVectorProperty *nvp);
+	void newText(ITextVectorProperty *tvp);
+	void newLight(ILightVectorProperty *lvp);
+	void newMessage(INDI::BaseDevice *dp, int messageID);
+	void serverConnected();
+	void serverDisconnected(int exit_code);
 	void unParkTelescope();
 	//void parkTelescope();
 };
