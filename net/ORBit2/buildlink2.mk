# $NetBSD: buildlink2.mk,v 1.12 2004/04/01 18:16:17 jmmv Exp $
#
# This Makefile fragment is included by packages that use ORBit2.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(ORBIT2_BUILDLINK2_MK)
ORBIT2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ORBit2
BUILDLINK_DEPENDS.ORBit2?=		ORBit2>=2.10.0
BUILDLINK_PKGSRCDIR.ORBit2?=		../../net/ORBit2

EVAL_PREFIX+=	BUILDLINK_PREFIX.ORBit2=ORBit2
BUILDLINK_PREFIX.ORBit2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/ORBitservices/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit-idl/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit/dynamic/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit/orb-core/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit/poa/*
BUILDLINK_FILES.ORBit2+=	include/orbit-2.0/orbit/util/*
BUILDLINK_FILES.ORBit2+=	lib/libORBit-2.*
BUILDLINK_FILES.ORBit2+=	lib/libORBit-imodule-2.*
BUILDLINK_FILES.ORBit2+=	lib/libORBitCosNaming-2.*
BUILDLINK_FILES.ORBit2+=	lib/libname-server-2.*
BUILDLINK_FILES.ORBit2+=	lib/orbit-2.0/Everything_module.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/libIDL/buildlink2.mk"

BUILDLINK_TARGETS+=	ORBit2-buildlink

ORBit2-buildlink: _BUILDLINK_USE

.endif	# ORBIT2_BUILDLINK2_MK
