# $NetBSD: buildlink.mk,v 1.3 2001/07/27 13:33:24 jlam Exp $
#
# This Makefile fragment is included by packages that use libnet.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libnet to the dependency pattern
#     for the version of libnet desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBNET_BUILDLINK_MK)
LIBNET_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libnet?=	libnet-*
DEPENDS+=	${BUILDLINK_DEPENDS.libnet}:../../devel/libnet

EVAL_PREFIX+=			BUILDLINK_PREFIX.libnet=libnet
BUILDLINK_PREFIX.libnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnet=		include/libnet.h
BUILDLINK_FILES.libnet+=	include/libnet/*
BUILDLINK_FILES.libnet+=	lib/libnet.*

REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libnet}|${BUILDLINK_CONFIG.libnet}|g"

BUILDLINK_TARGETS.libnet=	libnet-buildlink
BUILDLINK_TARGETS.libnet+=	libnet-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libnet}

BUILDLINK_CONFIG.libnet=	${BUILDLINK_PREFIX.libnet}/bin/libnet-config
BUILDLINK_CONFIG_WRAPPER.libnet=${BUILDLINK_DIR}/bin/libnet-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
LIBNET_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libnet}
CONFIGURE_ENV+=	LIBNET_CONFIG="${LIBNET_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libnet}
libnet-buildlink: _BUILDLINK_USE
libnet-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBNET_BUILDLINK_MK
