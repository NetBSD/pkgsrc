# $NetBSD: buildlink.mk,v 1.1 2001/11/26 05:56:37 jlam Exp $
#
# This Makefile fragment is included by packages that use libcdaudio.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libcdaudio to the dependency pattern
#     for the version of libcdaudio desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBCDAUDIO_BUILDLINK_MK)
LIBCDAUDIO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libcdaudio?=	libcdaudio>=0.99.4nb1
DEPENDS+=	${BUILDLINK_DEPENDS.libcdaudio}:../../audio/libcdaudio

EVAL_PREFIX+=	BUILDLINK_PREFIX.libcdaudio=libcdaudio
BUILDLINK_PREFIX.libcdaudio_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libcdaudio=		include/cdaudio.h
BUILDLINK_FILES.libcdaudio+=		lib/libcdaudio.*

BUILDLINK_TARGETS.libcdaudio=	libcdaudio-buildlink
BUILDLINK_TARGETS.libcdaudio+=	libcdaudio-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libcdaudio}

BUILDLINK_CONFIG.libcdaudio=	\
	${BUILDLINK_PREFIX.libcdaudio}/bin/libcdaudio-config
BUILDLINK_CONFIG_WRAPPER.libcdaudio=	\
	${BUILDLINK_DIR}/bin/libcdaudio-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libcdaudio}|${BUILDLINK_CONFIG.libcdaudio}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBCDAUDIO_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libcdaudio}
CONFIGURE_ENV+=		LIBCDAUDIO_CONFIG="${LIBCDAUDIO_CONFIG}"
MAKE_ENV+=		LIBCDAUDIO_CONFIG="${LIBCDAUDIO_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libcdaudio}
libcdaudio-buildlink: _BUILDLINK_USE
libcdaudio-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBCDAUDIO_BUILDLINK_MK
