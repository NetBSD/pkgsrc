# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SWIG_BUILD_BUILDLINK3_MK:=	${SWIG_BUILD_BUILDLINK3_MK}+

.include "../../devel/swig-build/Makefile.version"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swig-build
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswig-build}
BUILDLINK_PACKAGES+=	swig-build

.if !empty(SWIG_BUILD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swig-build+=		swig-build>=${SWIG_VERSION}
BUILDLINK_PKGSRCDIR.swig-build?=	../../devel/swig-build

# This package contains no run-time components.
BUILDLINK_DEPMETHOD.swig-build?=	build
.endif	# SWIG_BUILD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
