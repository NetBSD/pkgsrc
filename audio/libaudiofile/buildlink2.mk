# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:32 jlam Exp $

.if !defined(AUDIOFILE_BUILDLINK2_MK)
AUDIOFILE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		audiofile
BUILDLINK_PKGBASE.audiofile?=	libaudiofile
BUILDLINK_DEPENDS.audiofile?=	libaudiofile>=0.2.1
BUILDLINK_PKGSRCDIR.audiofile?=	../../audio/libaudiofile

EVAL_PREFIX+=	BUILDLINK_PREFIX.audiofile=audiofile
BUILDLINK_PREFIX.audiofile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.audiofile=	include/af_vfs.h
BUILDLINK_FILES.audiofile+=	include/audiofile.h
BUILDLINK_FILES.audiofile+=	include/aupvlist.h
BUILDLINK_FILES.audiofile+=	lib/libaudiofile.*

BUILDLINK_TARGETS+=		audiofile-buildlink

audiofile-buildlink: _BUILDLINK_USE

.endif	# AUDIOFILE_BUILDLINK2_MK
