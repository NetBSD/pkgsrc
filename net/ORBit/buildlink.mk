# $NetBSD: buildlink.mk,v 1.9 2002/01/15 23:52:11 rh Exp $
#
# This Makefile fragment is included by packages that use ORBit.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ORBit to the dependency pattern
#     for the version of ORBit desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ORBIT_BUILDLINK_MK)
ORBIT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ORBit?=	ORBit>=0.5.12
DEPENDS+=	${BUILDLINK_DEPENDS.ORBit}:../../net/ORBit

EVAL_PREFIX+=		BUILDLINK_PREFIX.ORBit=ORBit
BUILDLINK_PREFIX.ORBit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ORBit+=	include/libIDL-1.0/libIDL/*
BUILDLINK_FILES.ORBit=	include/orbit-1.0/IIOP/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/ORBitservices/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/ORBitutil/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/orb/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/orbit-idl2.h
BUILDLINK_FILES.ORBit+=	lib/libIDLConf.sh
BUILDLINK_FILES.ORBit+=	lib/libIDL.*
BUILDLINK_FILES.ORBit+=	lib/libIIOP.*
BUILDLINK_FILES.ORBit+=	lib/libORBit.*
BUILDLINK_FILES.ORBit+=	lib/libORBitCosNaming.*
BUILDLINK_FILES.ORBit+=	lib/libORBitutil.*
BUILDLINK_FILES.ORBit+=	lib/libname-server.*
BUILDLINK_FILES.ORBit+=	lib/liborbit-c-backend.*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"

BUILDLINK_TARGETS.ORBit=	ORBit-buildlink
BUILDLINK_TARGETS.ORBit+=	libIDL-buildlink-config-wrapper
BUILDLINK_TARGETS.ORBit+=	orbit-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ORBit}

BUILDLINK_CONFIG.libIDL=	${BUILDLINK_PREFIX.ORBit}/bin/libIDL-config
BUILDLINK_CONFIG_WRAPPER.libIDL=${BUILDLINK_DIR}/bin/libIDL-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libIDL}|${BUILDLINK_CONFIG.libIDL}|g"

BUILDLINK_CONFIG.orbit=		${BUILDLINK_PREFIX.ORBit}/bin/orbit-config
BUILDLINK_CONFIG_WRAPPER.orbit=	${BUILDLINK_DIR}/bin/orbit-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.orbit}|${BUILDLINK_CONFIG.orbit}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBIDL_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libIDL}
ORBIT_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.orbit}
CONFIGURE_ENV+=		LIBIDL_CONFIG="${LIBIDL_CONFIG}"
CONFIGURE_ENV+=		ORBIT_CONFIG="${ORBIT_CONFIG}"
MAKE_ENV+=		LIBIDL_CONFIG="${LIBIDL_CONFIG}"
MAKE_ENV+=		ORBIT_CONFIG="${ORBIT_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.ORBit}
ORBit-buildlink: _BUILDLINK_USE
libIDL-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
orbit-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# ORBIT_BUILDLINK_MK
