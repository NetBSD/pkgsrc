# $NetBSD: buildlink.mk,v 1.1 2001/06/19 15:59:27 jlam Exp $
#
# This Makefile fragment is included by packages that use libmikmod.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define LIBMIKMOD_REQD to the version of libmikmod desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBMIKMOD_BUILDLINK_MK)
LIBMIKMOD_BUILDLINK_MK=	# defined

LIBMIKMOD_REQD?=	3.1.9
DEPENDS+=		libmikmod>=${LIBMIKMOD_REQD}:../../audio/libmikmod

BUILDLINK_PREFIX.libmikmod=	${LOCALBASE}
BUILDLINK_FILES.libmikmod=	include/mikmod.h
BUILDLINK_FILES.libmikmod+=	lib/libmikmod.*

BUILDLINK_TARGETS.libmikmod=	libmikmod-buildlink
BUILDLINK_TARGETS.libmikmod+=	libmikmod-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmikmod}

BUILDLINK_CONFIG.libmikmod=		${LOCALBASE}/bin/libmikmod-config
BUILDLINK_CONFIG_WRAPPER.libmikmod=	${BUILDLINK_DIR}/bin/libmikmod-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		LIBMIKMOD_CONFIG="${BUILDLINK_CONFIG_WRAPPER.libmikmod}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libmikmod}
libmikmod-buildlink: _BUILDLINK_USE
libmikmod-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# LIBMIKMOD_BUILDLINK_MK
