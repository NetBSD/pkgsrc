# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:32 jlam Exp $
#
# This Makefile fragment is included by packages that use libaudiofile.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.audiofile to the dependency pattern
#     for the version of libaudiofile desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(AUDIOFILE_BUILDLINK2_MK)
AUDIOFILE_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.audiofile?=	libaudiofile>=0.2.1
DEPENDS+=	${BUILDLINK_DEPENDS.audiofile}:../../audio/libaudiofile

EVAL_PREFIX+=	BUILDLINK_PREFIX.audiofile=audiofile
BUILDLINK_PREFIX.audiofile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.audiofile=	include/af_vfs.h
BUILDLINK_FILES.audiofile+=	include/audiofile.h
BUILDLINK_FILES.audiofile+=	include/aupvlist.h
BUILDLINK_FILES.audiofile+=	lib/libaudiofile.*

BUILDLINK_TARGETS+=		audiofile-buildlink

audiofile-buildlink: _BUILDLINK_USE

.endif	# AUDIOFILE_BUILDLINK2_MK
