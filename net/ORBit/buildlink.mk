# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:19 jlam Exp $
#
# This Makefile fragment is included by packages that use ORBit.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define ORBIT_REQD to the version of ORBit desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ORBIT_BUILDLINK_MK)
ORBIT_BUILDLINK_MK=	# defined

ORBIT_REQD?=		0.5.1
DEPENDS+=		ORBit>=${ORBIT_REQD}:../../net/ORBit

BUILDLINK_PREFIX.ORBit=	${LOCALBASE}
BUILDLINK_FILES.ORBit=	include/IIOP/*
BUILDLINK_FILES.ORBit+=	include/ORBitservices/*
BUILDLINK_FILES.ORBit+=	include/ORBitutil/*
BUILDLINK_FILES.ORBit+=	include/libIDL/*
BUILDLINK_FILES.ORBit+=	include/orb/*
BUILDLINK_FILES.ORBit+=	include/orbit-idl2.h
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

BUILDLINK_CONFIG.libIDL=		${LOCALBASE}/bin/libIDL-config
BUILDLINK_CONFIG_WRAPPER.libIDL=	${BUILDLINK_DIR}/bin/libIDL-config

BUILDLINK_CONFIG.orbit=			${LOCALBASE}/bin/orbit-config
BUILDLINK_CONFIG_WRAPPER.orbit=		${BUILDLINK_DIR}/bin/orbit-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		LIBIDL_CONFIG="${BUILDLINK_CONFIG_WRAPPER.libIDL}"
CONFIGURE_ENV+=		ORBIT_CONFIG="${BUILDLINK_CONFIG_WRAPPER.orbit}"
.endif

pre-configure: ${BUILDLINK_TARGETS.ORBit}
ORBit-buildlink: _BUILDLINK_USE
libIDL-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
orbit-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# ORBIT_BUILDLINK_MK
