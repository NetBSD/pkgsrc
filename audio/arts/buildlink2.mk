# $NetBSD: buildlink2.mk,v 1.13 2003/09/17 23:01:46 markd Exp $
#
# This Makefile fragment is included by packages that use arts.

.if !defined(ARTS_BUILDLINK2_MK)
ARTS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			arts
BUILDLINK_DEPENDS.arts?=		arts>=1.1.3
BUILDLINK_PKGSRCDIR.arts?=		../../audio/arts

EVAL_PREFIX+=	BUILDLINK_PREFIX.arts=arts
BUILDLINK_PREFIX.arts_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.arts+=	include/arts/gsl/*.h
BUILDLINK_FILES.arts+=	include/arts/*.h
BUILDLINK_FILES.arts+=	include/arts/*.idl
BUILDLINK_FILES.arts+=	include/artsc/*.h
BUILDLINK_FILES.arts+=	lib/libartsc.*
BUILDLINK_FILES.arts+=	lib/libartscbackend.*
BUILDLINK_FILES.arts+=	lib/libartsdsp.*
BUILDLINK_FILES.arts+=	lib/libartsdsp_st.*
BUILDLINK_FILES.arts+=	lib/libartsflow.*
BUILDLINK_FILES.arts+=	lib/libartsflow_idl.*
BUILDLINK_FILES.arts+=	lib/libartsgslplayobject.*
BUILDLINK_FILES.arts+=	lib/libartswavplayobject.*
BUILDLINK_FILES.arts+=	lib/libkmedia2.*
BUILDLINK_FILES.arts+=	lib/libkmedia2_idl.*
BUILDLINK_FILES.arts+=	lib/libmcop.*
BUILDLINK_FILES.arts+=	lib/libmcop_mt.*
BUILDLINK_FILES.arts+=	lib/libqtmcop.*
BUILDLINK_FILES.arts+=	lib/libsoundserver_idl.*
BUILDLINK_FILES.arts+=	lib/libx11globalcomm.*
BUILDLINK_FILES.arts+=	lib/mcop/Arts/DataHandlePlay.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/FileInputStream.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/GSLPlayObject.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_ADD.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_AMAN_PLAY.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_AMAN_RECORD.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_BUS_DOWNLINK.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_BUS_UPLINK.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_FREQUENCY.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_MUL.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_MULTI_ADD.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_PLAY.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_PLAY_WAV.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_RECORD.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/Synth_WAVE_SIN.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/WavPlayObject.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/WaveDataHandle.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/Arts/X11GlobalComm.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/artsflow.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/artsflow.mcoptype
BUILDLINK_FILES.arts+=	lib/mcop/kmedia2.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/kmedia2.mcoptype
BUILDLINK_FILES.arts+=	lib/mcop/soundserver.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/soundserver.mcoptype
BUILDLINK_FILES.arts+=	lib/mcop/x11globalcomm.mcopclass
BUILDLINK_FILES.arts+=	lib/mcop/x11globalcomm.mcoptype

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

BUILDLINK_TARGETS+=	arts-buildlink

arts-buildlink: _BUILDLINK_USE

.endif	# ARTS_BUILDLINK2_MK
