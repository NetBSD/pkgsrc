# $NetBSD: buildlink.mk,v 1.4 2002/07/12 15:33:13 wiz Exp $
#
# This Makefile fragment is included by packages that use orbit2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.orbit2 to the dependency pattern
#     for the version of orbit2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ORBIT2_BUILDLINK_MK)
ORBIT2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.orbit2?=	ORBit2>=2.4.0
DEPENDS+=	${BUILDLINK_DEPENDS.orbit2}:../../net/ORBit2

EVAL_PREFIX+=		BUILDLINK_PREFIX.orbit2=orbit2
BUILDLINK_PREFIX.orbit2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.orbit2=	include/orbit-2.0/orbit/*/*
BUILDLINK_FILES.orbit2+=include/orbit-2.0/orbit/*
BUILDLINK_FILES.orbit2+=include/orbit-2.0/ORBitservices/*
BUILDLINK_FILES.orbit2+=lib/libORBit-2.*
BUILDLINK_FILES.orbit2+=lib/libORBitCosNaming-2.*
BUILDLINK_FILES.orbit2+=lib/libname-server-2.*
BUILDLINK_FILES.orbit2+=lib/orbit-2.0/*

.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../net/libIDL/buildlink.mk"
.include "../../net/linc/buildlink.mk"

BUILDLINK_TARGETS.orbit2=	orbit2-buildlink
BUILDLINK_TARGETS.orbit2+=	orbit2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.orbit2}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

BUILDLINK_CONFIG.orbit2=${BUILDLINK_PREFIX.orbit2}/bin/orbit2-config
BUILDLINK_CONFIG_WRAPPER.orbit2=${BUILDLINK_DIR}/bin/orbit2-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.orbit2}|${BUILDLINK_CONFIG.orbit2}|g"

.if defined(USE_CONFIG_WRAPPER)
ORBIT2_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.orbit2}
CONFIGURE_ENV+=	ORBIT2_CONFIG="${ORBIT2_CONFIG}"
MAKE_ENV+=	ORBIT2_CONFIG="${ORBIT2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.orbit2}
orbit2-buildlink: _BUILDLINK_USE
orbit2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# ORBIT2_BUILDLINK_MK
