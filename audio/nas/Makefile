# $NetBSD: Makefile,v 1.6 1998/05/21 20:23:51 frueauf Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.2p5
PKGNAME=	nas-1.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	audio/nas

MAINTAINER=	packages@netbsd.org

USE_IMAKE=	yes

CAT1=		auserver.0 AUVoxConfig.0 auvoxware.0 auconvert.0
CAT1+=		auctl.0 audemo.0 audial.0 auedit.0 auinfo.0 aupanel.0
CAT1+=		auplay.0 aurecord.0 autool.0 auwave.0 auphone.0
CAT1+=		auscope.0 soundtoh.0 issndfile.0 playbucket.0
CAT1+=		checkmail.0 nas.0

CAT3=		AuAnyEvent.0 AuBucketAttributes.0 AuConvertDataToShort.0
CAT3+=		AuConvertShortToData.0 AuCloseServer.0 AuCreateBucket.0
CAT3+=		AuCreateFlow.0 AuDeviceAttributes.0 AuDataFormats.0
CAT3+=		AuDataTypes.0 AuDefineToFormat.0 AuDestroyBucket.0
CAT3+=		AuDestroyFlow.0 AuDispatchEvent.0 AuElementNotifyEvent.0
CAT3+=		AuElementParameters.0 AuElementState.0 AuElement.0
CAT3+=		AuErrorEvent.0 AuEvent.0 AuEventsQueued.0
CAT3+=		AuFixedPointFractionalAddend.0 AuFixedPointFromFraction.0
CAT3+=		AuFixedPointFromSum.0 AuFixedPointIntegralAddend.0
CAT3+=		AuFixedPointRoundDown.0 AuFixedPointRoundUp.0
CAT3+=		AuFileFormats.0 AuFlush.0 AuFreeBucketAttributes.0
CAT3+=		AuFreeDeviceAttributes.0 AuFreeElementStates.0
CAT3+=		AuFormatToDefine.0 AuFormatToString.0 AuFreeElements.0
CAT3+=		AuGetBucketAttributes.0 AuGetCloseDownMode.0
CAT3+=		AuGetDeviceAttributes.0 AuGetErrorDatabaseText.0
CAT3+=		AuGetElementParameters.0 AuGetElementStates.0
CAT3+=		AuGetErrorText.0 AuGetScratchFlowFromBucket.0
CAT3+=		AuGetScratchFlowToBucket.0 AuGetScratchFlow.0
CAT3+=		AuGetServerTime.0 AuGetElements.0 AuGrabNotifyEvent.0
CAT3+=		AuHandleEvents.0 AuIDOfEvent.0 AuServer.0 AuInputTrack.0
CAT3+=		AuKillClient.0 AuListBuckets.0 AuListDevices.0
CAT3+=		AuLookupEventHandler.0 AuMakeChangeStateAction.0
CAT3+=		AuMakeElementAddConstant.0 AuMakeElementBundle.0
CAT3+=		AuMakeElementExportBucket.0 AuMakeElementExportClient.0
CAT3+=		AuMakeElementExportDevice.0 AuMakeElementExportMonitor.0
CAT3+=		AuMakeElementImportBucket.0 AuMakeElementImportClient.0
CAT3+=		AuMakeElementImportDevice.0 AuNextEvent.0
CAT3+=		AuMakeElementImportWaveForm.0 AuMakeElementMultiplyConstant.0
CAT3+=		AuMakeElementState.0 AuMakeElementSum.0 AuMakeInputTrack.0
CAT3+=		AuMakeNoopAction.0 AuMonitorNotifyEvent.0
CAT3+=		AuMakeSendNotifyAction.0 AuMonitorDevice.0
CAT3+=		AuOpenServer.0 AuPauseFlow.0 AuRegisterEventHandler.0
CAT3+=		AuReleaseScratchFlow.0 AuReadElement.0 AuRequeueEvent.0
CAT3+=		AuSetBucketAttributes.0 AuSync.0 AuSoundCreateBucketFromData.0
CAT3+=		AuSoundCreateBucketFromFile.0 AuSoundCreateDataFromBucket.0
CAT3+=		AuSetCloseDownMode.0 AuSoundCreateFileFromBucket.0
CAT3+=		AuSetDeviceAttributes.0 AuSetElementParameters.0
CAT3+=		AuSetElementStates.0 AuSetElements.0 AuSetErrorHandler.0
CAT3+=		AuSetIOErrorHandler.0 AuSoundPlay.0 AuSoundPlayFromBucket.0
CAT3+=		AuSoundPlayFromData.0 AuSoundPlayFromFile.0 Sound.0
CAT3+=		AuSoundPlaySynchronousFromFile.0 AuSoundRecord.0
CAT3+=		AuSoundRecordToBucket.0 AuSoundRecordToData.0
CAT3+=		AuSoundRecordToFile.0 AuSoundRecordToFileN.0
CAT3+=		AuSetString.0 AuScanEvents.0 AuScanForTypedEvent.0
CAT3+=		AuServerName.0 AuStopFlow.0 AuStartFlow.0 AuStringToFormat.0
CAT3+=		AuStringToWaveForm.0 AuSynchronize.0 AuUnregisterEventHandler.0
CAT3+=		AuWaveFormToString.0 AuWriteElement.0
CAT3+=		SoundAbbrevToFileFormat.0 SoundCloseFile.0 SoundCreate.0
CAT3+=		SoundFlushFile.0 SoundOpenFileForReading.0
CAT3+=		SoundOpenFileForWriting.0 SoundReadFile.0
CAT3+=		SoundRewindFile.0 SoundSeekFile.0
CAT3+=		SoundStringToFileFormat.0 SoundTellFile.0
CAT3+=		SoundWriteFile.0

.include "../../mk/bsd.pkg.mk"
