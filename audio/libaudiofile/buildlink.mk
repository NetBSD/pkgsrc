# $NetBSD: buildlink.mk,v 1.8 2001/08/17 21:14:01 jlam Exp $
#
# This Makefile fragment is included by packages that use libaudiofile.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.audiofile to the dependency pattern
#     for the version of libaudiofile desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(AUDIOFILE_BUILDLINK_MK)
AUDIOFILE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.audiofile?=	libaudiofile>=0.2.1
DEPENDS+=	${BUILDLINK_DEPENDS.audiofile}:../../audio/libaudiofile

EVAL_PREFIX+=			BUILDLINK_PREFIX.audiofile=libaudiofile
BUILDLINK_PREFIX.audiofile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.audiofile=	include/af_vfs.h
BUILDLINK_FILES.audiofile+=	include/audiofile.h
BUILDLINK_FILES.audiofile+=	include/aupvlist.h
BUILDLINK_FILES.audiofile+=	lib/libaudiofile.*

BUILDLINK_TARGETS.audiofile=	audiofile-buildlink
BUILDLINK_TARGETS.audiofile+=	audiofile-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.audiofile}

BUILDLINK_CONFIG.audiofile=	\
			${BUILDLINK_PREFIX.audiofile}/bin/audiofile-config
BUILDLINK_CONFIG_WRAPPER.audiofile=	\
			${BUILDLINK_DIR}/bin/audiofile-config

.if defined(USE_CONFIG_WRAPPER)
AUDIOFILE_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.audiofile}
CONFIGURE_ENV+=		AUDIOFILE_CONFIG="${AUDIOFILE_CONFIG}"
MAKE_ENV+=		AUDIOFILE_CONFIG="${AUDIOFILE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.audiofile}
audiofile-buildlink: _BUILDLINK_USE
audiofile-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# AUDIOFILE_BUILDLINK_MK
