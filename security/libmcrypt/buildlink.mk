# $NetBSD: buildlink.mk,v 1.1 2001/10/09 06:43:58 jlam Exp $
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

BUILDLINK_DEPENDS.libmcrypt?=	libmcrypt>=2.2
DEPENDS+=	${BUILDLINK_DEPENDS.libmcrypt}:../../security/libmcrypt

EVAL_PREFIX+=			BUILDLINK_PREFIX.libmcrypt=libmcrypt
BUILDLINK_PREFIX.libmcrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmcrypt=	include/mcrypt.h
BUILDLINK_FILES.libmcrypt+=	lib/libmcrypt.*

BUILDLINK_TARGETS.libmcrypt=	libmcrypt-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmcrypt}

pre-configure: ${BUILDLINK_TARGETS.libmcrypt}
libmcrypt-buildlink: _BUILDLINK_USE

.endif	# LIBMCRYPT_BUILDLINK_MK
