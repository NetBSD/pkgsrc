$NetBSD: patch-plugins_TelescopeControl_src_INDI_INDIConnection.cpp,v 1.1 2024/05/03 12:07:41 wiz Exp $

Port code to INDI 2.0.2
https://github.com/Stellarium/stellarium/pull/3269/files

--- plugins/TelescopeControl/src/INDI/INDIConnection.cpp.orig	2024-02-04 13:27:52.000000000 +0000
+++ plugins/TelescopeControl/src/INDI/INDIConnection.cpp
@@ -44,98 +44,96 @@ INDIConnection::Coordinates INDIConnecti
 void INDIConnection::setPosition(INDIConnection::Coordinates coords)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope)
+	if (!mTelescope.isValid())
 		return;
 
-	if (!mTelescope->isConnected())
+	if (!mTelescope.isConnected())
 	{
 		qDebug() << "Error: Telescope not connected";
 		return;
 	}
 
 	// Make sure the TRACK member of switch ON_COORD_SET is set
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("ON_COORD_SET");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("ON_COORD_SET");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or ON_COORD_SET switch...";
 		return;
 	}
 	// Note that confusingly there is a SLEW switch member as well that will move but not track.
 	// TODO: Figure out if there is to be support for it
-	ISwitch *track = IUFindSwitch(switchVector, "TRACK");
+	auto track = switchVector.findWidgetByName("TRACK");
 	if (track->s == ISS_OFF)
 	{
-		track->s = ISS_ON;
+		track->setState(ISS_ON);
 		sendNewSwitch(switchVector);
 	}
 
-	INumberVectorProperty *property = nullptr;
-	property = mTelescope->getNumber("EQUATORIAL_EOD_COORD");
-	if (!property)
+	auto property = mTelescope.getNumber("EQUATORIAL_EOD_COORD");
+	if (!property.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or EQUATORIAL_EOD_COORD property...";
 		return;
 	}
 
-	property->np[0].value = coords.RA;
-	property->np[1].value = coords.DEC;
+	property[0].setValue(coords.RA);
+	property[1].setValue(coords.DEC);
 	sendNewNumber(property);
 }
 
 void INDIConnection::syncPosition(INDIConnection::Coordinates coords)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope)
+	if (!mTelescope.isValid())
 		return;
 
-	if (!mTelescope->isConnected())
+	if (!mTelescope.isConnected())
 	{
 		qDebug() << "Error: Telescope not connected";
 		return;
 	}
 
 	// Make sure the SYNC member of switch ON_COORD_SET is set
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("ON_COORD_SET");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("ON_COORD_SET");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or ON_COORD_SET switch...";
 		return;
 	}
 
-	ISwitch *track = IUFindSwitch(switchVector, "TRACK");
-	ISwitch *slew = IUFindSwitch(switchVector, "SLEW");
-	ISwitch *sync = IUFindSwitch(switchVector, "SYNC");
-	track->s = ISS_OFF;
-	slew->s = ISS_OFF;
-	sync->s = ISS_ON;
+	auto track = switchVector.findWidgetByName("TRACK");
+	auto slew = switchVector.findWidgetByName("SLEW");
+	auto sync = switchVector.findWidgetByName("SYNC");
+	track->setState(ISS_OFF);
+	slew->setState(ISS_OFF);
+	sync->setState(ISS_ON);
 	sendNewSwitch(switchVector);
 
-	INumberVectorProperty *property = nullptr;
-	property = mTelescope->getNumber("EQUATORIAL_EOD_COORD");
-	if (!property)
+	auto property = mTelescope.getNumber("EQUATORIAL_EOD_COORD");
+	if (!property.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or EQUATORIAL_EOD_COORD property...";
 		return;
 	}
 
-	property->np[0].value = coords.RA;
-	property->np[1].value = coords.DEC;
+	property[0].setValue(coords.RA);
+	property[1].setValue(coords.DEC);
 	sendNewNumber(property);
 
 	// And now unset SYNC switch member to revert to default state/behavior
-	track->s = ISS_ON;
-	slew->s = ISS_OFF;
-	sync->s = ISS_OFF;
+	track->setState(ISS_ON);
+	slew->setState(ISS_OFF);
+	sync->setState(ISS_OFF);
 	sendNewSwitch(switchVector);
 }
 
 bool INDIConnection::isDeviceConnected() const
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope)
+	if (!mTelescope.isValid())
 		return false;
 
-	return mTelescope->isConnected();
+	return mTelescope.isConnected();
 }
 
 const QStringList INDIConnection::devices() const
@@ -147,28 +145,28 @@ const QStringList INDIConnection::device
 void INDIConnection::unParkTelescope()
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_PARK");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_PARK");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_PARK switch...";
 		return;
 	}
 
-	ISwitch *park = IUFindSwitch(switchVector, "PARK");
+	auto park = switchVector.findWidgetByName("PARK");
 	if (park->s == ISS_ON)
 	{
-		park->s = ISS_OFF;
+		park->setState(ISS_OFF);
 		sendNewSwitch(switchVector);
 	}
 
 	// The telescope will work without running command below, but I use it to avoid undefined state for parking property.
-	ISwitch *unpark = IUFindSwitch(switchVector, "UNPARK");
+	auto unpark = switchVector.findWidgetByName("UNPARK");
 	if (unpark->s == ISS_OFF)
 	{
-		unpark->s = ISS_ON;
+		unpark->setState(ISS_ON);
 		sendNewSwitch(switchVector);
 	}
 }
@@ -179,27 +177,27 @@ void INDIConnection::unParkTelescope()
 void INDIConnection::parkTelescope()
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_PARK");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_PARK");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_PARK switch...";
 		return;
 	}
 
-	ISwitch *park = IUFindSwitch(switchVector, "PARK");
+	auto park = switchVector.findWidgetByName("PARK");
 	if (park->s == ISS_OFF)
 	{
-		park->s = ISS_ON;
+		park->setState(ISS_ON);
 		sendNewSwitch(switchVector);
 	}
 
-	ISwitch *unpark = IUFindSwitch(switchVector, "UNPARK");
+	auto unpark = switchVector.findWidgetByName("UNPARK");
 	if (unpark->s == ISS_ON)
 	{
-		unpark->s = ISS_OFF;
+		unpark->setState(ISS_OFF);
 		sendNewSwitch(switchVector);
 	}
 }
@@ -208,24 +206,24 @@ void INDIConnection::parkTelescope()
 void INDIConnection::moveNorth(int speed)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_MOTION_NS");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_MOTION_NS");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_MOTION_NS switch...";
 		return;
 	}
 
-	ISwitch *motion = IUFindSwitch(switchVector, "MOTION_NORTH");
+	auto motion = switchVector.findWidgetByName("MOTION_NORTH");
 
 	if (speed == SLEW_STOP)
-		motion->s = ISS_OFF;
+		motion->setState(ISS_OFF);
 	else
 	{
 		setSpeed(speed);
-		motion->s = ISS_ON;
+		motion->setState(ISS_ON);
 	}
 
 	sendNewSwitch(switchVector);
@@ -234,24 +232,24 @@ void INDIConnection::moveNorth(int speed
 void INDIConnection::moveEast(int speed)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_MOTION_WE");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_MOTION_WE");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_MOTION_WE switch...";
 		return;
 	}
 
-	ISwitch *motion = IUFindSwitch(switchVector, "MOTION_EAST");
+	auto motion = switchVector.findWidgetByName("MOTION_EAST");
 
 	if (speed == SLEW_STOP)
-		motion->s = ISS_OFF;
+		motion->setState(ISS_OFF);
 	else
 	{
 		setSpeed(speed);
-		motion->s = ISS_ON;
+		motion->setState(ISS_ON);
 	}
 
 	sendNewSwitch(switchVector);
@@ -260,24 +258,24 @@ void INDIConnection::moveEast(int speed)
 void INDIConnection::moveSouth(int speed)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_MOTION_NS");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_MOTION_NS");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_MOTION_NS switch...";
 		return;
 	}
 
-	ISwitch *motion = IUFindSwitch(switchVector, "MOTION_SOUTH");
+	auto motion = switchVector.findWidgetByName("MOTION_SOUTH");
 
 	if (speed == SLEW_STOP)
-		motion->s = ISS_OFF;
+		motion->setState(ISS_OFF);
 	else
 	{
 		setSpeed(speed);
-		motion->s = ISS_ON;
+		motion->setState(ISS_ON);
 	}
 
 	sendNewSwitch(switchVector);
@@ -286,24 +284,24 @@ void INDIConnection::moveSouth(int speed
 void INDIConnection::moveWest(int speed)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (!mTelescope || !mTelescope->isConnected())
+	if (!mTelescope.isValid() || !mTelescope.isConnected())
 		return;
 
-	ISwitchVectorProperty *switchVector = mTelescope->getSwitch("TELESCOPE_MOTION_WE");
-	if (!switchVector)
+	auto switchVector = mTelescope.getSwitch("TELESCOPE_MOTION_WE");
+	if (!switchVector.isValid())
 	{
 		qDebug() << "Error: unable to find Telescope or TELESCOPE_MOTION_WE switch...";
 		return;
 	}
 
-	ISwitch *motion = IUFindSwitch(switchVector, "MOTION_WEST");
+	auto motion = switchVector.findWidgetByName("MOTION_WEST");
 
 	if (speed == SLEW_STOP)
-		motion->s = ISS_OFF;
+		motion->setState(ISS_OFF);
 	else
 	{
 		setSpeed(speed);
-		motion->s = ISS_ON;
+		motion->setState(ISS_ON);
 	}
 
 	sendNewSwitch(switchVector);
@@ -311,23 +309,24 @@ void INDIConnection::moveWest(int speed)
 
 void INDIConnection::setSpeed(int speed)
 {
-	ISwitchVectorProperty *slewRateSP = mTelescope->getSwitch("TELESCOPE_SLEW_RATE");
+	auto slewRateSP = mTelescope.getSwitch("TELESCOPE_SLEW_RATE");
 
-	if (!slewRateSP || speed < 0 || speed > slewRateSP->nsp)
+	if (!slewRateSP.isValid() || speed < 0 ||
+			static_cast<std::size_t>(speed) > slewRateSP.count())
 		return;
 
-	IUResetSwitch(slewRateSP);
-	slewRateSP->sp[speed].s = ISS_ON;
+	slewRateSP.reset();
+	slewRateSP[speed].setState(ISS_ON);
 	sendNewSwitch(slewRateSP);
 }
 
-void INDIConnection::newDevice(INDI::BaseDevice *dp)
+void INDIConnection::newDevice(INDI::BaseDevice dp)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
 	if (!dp)
 		return;
 
-	QString name(dp->getDeviceName());
+	QString name(dp.getDeviceName());
 
 	qDebug() << "INDIConnection::newDevice| New Device... " << name;
 
@@ -337,91 +336,54 @@ void INDIConnection::newDevice(INDI::Bas
 	emit newDeviceReceived(name);
 }
 
-void INDIConnection::removeDevice(INDI::BaseDevice *dp)
+void INDIConnection::removeDevice(INDI::BaseDevice dp)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
 	if (!dp)
 		return;
 
-	QString name(dp->getDeviceName());
+	QString name(dp.getDeviceName());
 	int index = mDevices.indexOf(name);
 	if (index != -1)
 		mDevices.removeAt(index);
 
-	if (mTelescope == dp)
-		mTelescope = nullptr;
+	if (mTelescope.isDeviceNameMatch(dp.getDeviceName()))
+		mTelescope.detach();
 
 	emit removeDeviceReceived(name);
 }
 
-void INDIConnection::newProperty(INDI::Property *property)
+void INDIConnection::newProperty(INDI::Property property)
 {
 	std::lock_guard<std::mutex> lock(mMutex);
-	if (mTelescope != property->getBaseDevice())
+	if (!mTelescope.isDeviceNameMatch(
+				property.getBaseDevice().getDeviceName()))
 		return;
 
-	QString name(property->getName());
+	QString name(property.getName());
 
 	qDebug() << "INDIConnection::newProperty| " << name;
 
 	if (name == "EQUATORIAL_EOD_COORD")
 	{
-		mCoordinates.RA = property->getNumber()->np[0].value;
-		mCoordinates.DEC = property->getNumber()->np[1].value;
+		mCoordinates.RA = property.getNumber()->np[0].value;
+		mCoordinates.DEC = property.getNumber()->np[1].value;
 	}
 
-	if (!mTelescope->isConnected())
+	if (!mTelescope.isConnected())
 	{
-		connectDevice(mTelescope->getDeviceName());
-		if (mTelescope->isConnected())
+		connectDevice(mTelescope.getDeviceName());
+		if (mTelescope.isConnected())
 			qDebug() << "connected\n";
 	}
 }
 
-void INDIConnection::removeProperty(INDI::Property *property)
+void INDIConnection::removeProperty(INDI::Property property)
 {
 	Q_UNUSED(property)
 }
 
-void INDIConnection::newBLOB(IBLOB *bp)
-{
-	Q_UNUSED(bp)
-}
-
-void INDIConnection::newSwitch(ISwitchVectorProperty *svp)
-{
-	std::lock_guard<std::mutex> lock(mMutex);
-	QString name(svp->name);
-	if (name == "TELESCOPE_SLEW_RATE")
-	{
-		int speed = IUFindOnSwitchIndex(svp);
-		emit speedChanged(speed);
-	}
-}
-
-void INDIConnection::newNumber(INumberVectorProperty *nvp)
-{
-	std::lock_guard<std::mutex> lock(mMutex);
-
-	QString name(nvp->name);
-	if (name == "EQUATORIAL_EOD_COORD")
-	{
-		mCoordinates.RA = nvp->np[0].value;
-		mCoordinates.DEC = nvp->np[1].value;
-	}
-}
-
-void INDIConnection::newText(ITextVectorProperty *tvp)
-{
-	Q_UNUSED(tvp)
-}
-
-void INDIConnection::newLight(ILightVectorProperty *lvp)
-{
-	Q_UNUSED(lvp)
-}
-
-void INDIConnection::newMessage(INDI::BaseDevice *dp, int messageID)
+void INDIConnection::newMessage(INDI::BaseDevice dp, int messageID)
 {
 	Q_UNUSED(dp)
 	Q_UNUSED(messageID)
