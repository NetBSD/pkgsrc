# $NetBSD: buildlink.mk,v 1.2 2001/10/03 20:56:42 jlam Exp $
#
# This Makefile fragment is included by packages that use wsound.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.wsound to the dependency pattern
#     for the version of wsound desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(WSOUND_BUILDLINK_MK)
WSOUND_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.wsound?=	wsoundserver>=0.4.0
DEPENDS+=	${BUILDLINK_DEPENDS.wsound}:../../audio/wsoundserver

EVAL_PREFIX+=			BUILDLINK_PREFIX.wsound=wsoundserver
BUILDLINK_FILES.wsound=		include/wsound.h
BUILDLINK_FILES.wsound+=	lib/libwsound.*

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"

BUILDLINK_TARGETS.wsound=	wsound-buildlink
BUILDLINK_TARGETS.wsound+=	wsound-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.wsound}

BUILDLINK_CONFIG.wsound=	\
	${BUILDLINK_PREFIX.wsound}/bin/get-wsound-flags
BUILDLINK_CONFIG_WRAPPER.wsound=	\
	${BUILDLINK_DIR}/bin/get-wsound-flags
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.wsound}|${BUILDLINK_CONFIG.wsound}|g"

.if defined(USE_CONFIG_WRAPPER)
GET_WSOUND_FLAGS?=	${BUILDLINK_CONFIG_WRAPPER.wsound}
CONFIGURE_ENV+=		GET_WSOUND_FLAGS="${GET_WSOUND_FLAGS}"
MAKE_ENV+=		GET_WSOUND_FLAGS="${GET_WSOUND_FLAGS}"
.endif

pre-configure: ${BUILDLINK_TARGETS.wsound}
wsound-buildlink: _BUILDLINK_USE
wsound-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# WSOUND_BUILDLINK_MK
