# $NetBSD: buildlink.mk,v 1.3 2001/10/09 19:37:11 jlam Exp $
#
# This Makefile fragment is included by packages that use libmcrypt.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libmcrypt to the dependency pattern
#     for the version of libmcrypt desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBMCRYPT_BUILDLINK_MK)
LIBMCRYPT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libmcrypt?=	libmcrypt>=2.4.17
DEPENDS+=	${BUILDLINK_DEPENDS.libmcrypt}:../../security/libmcrypt

EVAL_PREFIX+=			BUILDLINK_PREFIX.libmcrypt=libmcrypt
BUILDLINK_PREFIX.libmcrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmcrypt=	include/mcrypt.h
BUILDLINK_FILES.libmcrypt+=	lib/libmcrypt.*

.include "../../devel/libtool/buildlink.mk"

BUILDLINK_TARGETS.libmcrypt=	libmcrypt-buildlink
BUILDLINK_TARGETS.libmcrypt+=	libmcrypt-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmcrypt}

BUILDLINK_CONFIG.libmcrypt=	\
	${BUILDLINK_PREFIX.libmcrypt}/bin/libmcrypt-config
BUILDLINK_CONFIG_WRAPPER.libmcrypt=	\
	${BUILDLINK_DIR}/bin/libmcrypt-config

.if defined(USE_CONFIG_WRAPPER)
LIBMCRYPT_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libmcrypt}
CONFIGURE_ENV+=		LIBMCRYPT_CONFIG="${LIBMCRYPT_CONFIG}"
MAKE_ENV+=		LIBMCRYPT_CONFIG="${LIBMCRYPT_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libmcrypt}
libmcrypt-buildlink: _BUILDLINK_USE
libmcrypt-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBMCRYPT_BUILDLINK_MK
