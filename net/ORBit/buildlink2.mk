# $NetBSD: buildlink2.mk,v 1.3 2002/09/11 10:16:10 jlam Exp $

.if !defined(ORBIT_BUILDLINK2_MK)
ORBIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ORBit
BUILDLINK_DEPENDS.ORBit?=	ORBit>=0.5.12
BUILDLINK_PKGSRCDIR.ORBit?=	../../net/ORBit

EVAL_PREFIX+=	BUILDLINK_PREFIX.ORBit=ORBit
BUILDLINK_PREFIX.ORBit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ORBit+=	include/libIDL-1.0/libIDL/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/IIOP/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/ORBitservices/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/ORBitutil/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/orb/*
BUILDLINK_FILES.ORBit+=	include/orbit-1.0/orbit-idl2.h
BUILDLINK_FILES.ORBit+=	lib/libIDL.*
BUILDLINK_FILES.ORBit+=	lib/libIIOP.*
BUILDLINK_FILES.ORBit+=	lib/libORBit.*
BUILDLINK_FILES.ORBit+=	lib/libORBitCosNaming.*
BUILDLINK_FILES.ORBit+=	lib/libORBitutil.*
BUILDLINK_FILES.ORBit+=	lib/libname-server.*
BUILDLINK_FILES.ORBit+=	lib/liborbit-c-backend.*

# The ORBit headers should be found at the same location as for libxml.
#BUILDLINK_TRANSFORM.ORBit=    -e "s|/include/orbit-1.0/|/include/|g"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

BUILDLINK_TARGETS+=	ORBit-buildlink

ORBit-buildlink: _BUILDLINK_USE

.endif	# ORBIT_BUILDLINK2_MK
