# $NetBSD: buildlink.mk,v 1.6 2001/08/17 21:14:06 jlam Exp $
#
# This Makefile fragment is included by packages that use pcre.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pcre to the dependency pattern
#     for the version of pcre desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PCRE_BUILDLINK_MK)
PCRE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pcre?=	pcre>=3.4
DEPENDS+=	${BUILDLINK_DEPENDS.pcre}:../../devel/pcre

EVAL_PREFIX+=		BUILDLINK_PREFIX.pcre=pcre
BUILDLINK_PREFIX.pcre_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pcre=	include/pcre.h
BUILDLINK_FILES.pcre+=	include/pcreposix.h
BUILDLINK_FILES.pcre+=	lib/libpcre.*
BUILDLINK_FILES.pcre+=	lib/libpcreposix.*

BUILDLINK_TARGETS.pcre=		pcre-buildlink
BUILDLINK_TARGETS.pcre+=	pcre-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pcre}

BUILDLINK_CONFIG.pcre=		${BUILDLINK_PREFIX.pcre}/bin/pcre-config
BUILDLINK_CONFIG_WRAPPER.pcre=	${BUILDLINK_DIR}/bin/pcre-config

.if defined(USE_CONFIG_WRAPPER)
PCRE_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.pcre}
CONFIGURE_ENV+=		PCRE_CONFIG="${PCRE_CONFIG}"
MAKE_ENV+=		PCRE_CONFIG="${PCRE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.pcre}
pcre-buildlink: _BUILDLINK_USE
pcre-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PCRE_BUILDLINK_MK
