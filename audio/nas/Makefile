# New ports collection makefile for:	nas (formerly netaudio)
# Version required:	1.2p1
# Date created:		03 Nov 1994
# Whom:			jkh
#
# $NetBSD: Makefile,v 1.2 1998/01/19 01:00:16 hubertf Exp $
# FreeBSD Id: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.2p5
PKGNAME=	nas-1.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	audio/nas

MAINTAINER=	augustss@netbsd.org

USE_IMAKE=	yes
ALL_TARGET=	World
# no need to "xmkmf -a" and create the Makefiles twice -- see above
XMKMF=		xmkmf

MAN1=		auserver.1 AUVoxConfig.1 auvoxware.1 auconvert.1 auctl.1 audemo.1 audial.1 auedit.1 auinfo.1 aupanel.1 auplay.1 aurecord.1 autool.1 auwave.1 auphone.1 auscope.1 soundtoh.1 issndfile.1 playbucket.1 checkmail.1 nas.1
MAN3=		AuAnyEvent.3 AuBucketAttributes.3 AuConvertDataToShort.3 AuConvertShortToData.3 AuCloseServer.3 AuCreateBucket.3 AuCreateFlow.3 AuDeviceAttributes.3 AuDataFormats.3 AuDataTypes.3 AuDefineToFormat.3 AuDestroyBucket.3 AuDestroyFlow.3 AuDispatchEvent.3 AuElementNotifyEvent.3 AuElementParameters.3 AuElementState.3 AuElement.3 AuErrorEvent.3 AuEvent.3 AuEventsQueued.3 AuFixedPointFractionalAddend.3 AuFixedPointFromFraction.3 AuFixedPointFromSum.3 AuFixedPointIntegralAddend.3 AuFixedPointRoundDown.3 AuFixedPointRoundUp.3 AuFileFormats.3 AuFlush.3 AuFreeBucketAttributes.3 AuFreeDeviceAttributes.3 AuFreeElementStates.3 AuFormatToDefine.3 AuFormatToString.3 AuFreeElements.3 AuGetBucketAttributes.3 AuGetCloseDownMode.3 AuGetDeviceAttributes.3 AuGetErrorDatabaseText.3 AuGetElementParameters.3 AuGetElementStates.3 AuGetErrorText.3 AuGetScratchFlowFromBucket.3 AuGetScratchFlowToBucket.3 AuGetScratchFlow.3 AuGetServerTime.3 AuGetElements.3 AuGrabNotifyEvent.3 AuHandleEvents.3 AuIDOfEvent.3 AuInputTrack.3 AuKillClient.3 AuListBuckets.3 AuListDevices.3 AuLookupEventHandler.3 AuMakeChangeStateAction.3 AuMakeElementAddConstant.3 AuMakeElementBundle.3 AuMakeElementExportBucket.3 AuMakeElementExportClient.3 AuMakeElementExportDevice.3 AuMakeElementExportMonitor.3 AuMakeElementImportBucket.3 AuMakeElementImportClient.3 AuMakeElementImportDevice.3 AuMakeElementImportWaveForm.3 AuMakeElementMultiplyConstant.3 AuMakeElementState.3 AuMakeElementSum.3 AuMakeInputTrack.3 AuMakeNoopAction.3 AuMonitorNotifyEvent.3 AuMakeSendNotifyAction.3 AuMonitorDevice.3 AuNextEvent.3 AuOpenServer.3 AuPauseFlow.3 AuRegisterEventHandler.3 AuReleaseScratchFlow.3 AuReadElement.3 AuRequeueEvent.3 AuSetBucketAttributes.3 AuSoundCreateBucketFromData.3 AuSoundCreateBucketFromFile.3 AuSoundCreateDataFromBucket.3 AuSetCloseDownMode.3 AuSoundCreateFileFromBucket.3 AuSetDeviceAttributes.3 AuSetElementParameters.3 AuSetElementStates.3 AuSetElements.3 AuSetErrorHandler.3 AuSetIOErrorHandler.3 AuSoundPlay.3 AuSoundPlayFromBucket.3 AuSoundPlayFromData.3 AuSoundPlayFromFile.3 AuSoundPlaySynchronousFromFile.3 AuSoundRecord.3 AuSoundRecordToBucket.3 AuSoundRecordToData.3 AuSoundRecordToFile.3 AuSoundRecordToFileN.3 AuSetString.3 AuScanEvents.3 AuScanForTypedEvent.3 AuServerName.3 AuServer.3 AuStopFlow.3 AuStartFlow.3 AuStringToFormat.3 AuStringToWaveForm.3 AuSync.3 AuSynchronize.3 AuUnregisterEventHandler.3 AuWaveFormToString.3 AuWriteElement.3 SoundAbbrevToFileFormat.3 SoundCloseFile.3 SoundCreate.3 SoundOpenFileForReading.3 SoundOpenFileForWriting.3 SoundReadFile.3 SoundRewindFile.3 SoundStringToFileFormat.3 SoundWriteFile.3 Sound.3 SoundFlushFile.3 SoundSeekFile.3 SoundTellFile.3

.include <bsd.port.mk>
