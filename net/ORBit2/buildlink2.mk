# $NetBSD: buildlink2.mk,v 1.4 2002/09/10 16:06:46 wiz Exp $

.if !defined(ORBIT2_BUILDLINK2_MK)
ORBIT2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		orbit2
BUILDLINK_DEPENDS.orbit2?=	ORBit2>=2.4.0nb2
BUILDLINK_PKGSRCDIR.orbit2?=	../../net/ORBit2

EVAL_PREFIX+=				BUILDLINK_PREFIX.orbit2=orbit2
BUILDLINK_PREFIX.orbit2_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.orbit2=		include/orbit-2.0/orbit/*/*
BUILDLINK_FILES.orbit2+=	include/orbit-2.0/orbit/*
BUILDLINK_FILES.orbit2+=	include/orbit-2.0/ORBitservices/*
BUILDLINK_FILES.orbit2+=	lib/libORBit-2.*
BUILDLINK_FILES.orbit2+=	lib/libORBitCosNaming-2.*
BUILDLINK_FILES.orbit2+=	lib/libname-server-2.*
BUILDLINK_FILES.orbit2+=	lib/orbit-2.0/*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/libIDL/buildlink2.mk"
.include "../../net/linc/buildlink2.mk"

BUILDLINK_TARGETS+=	orbit2-buildlink

orbit2-buildlink: _BUILDLINK_USE

.endif	# ORBIT2_BUILDLINK2_MK
