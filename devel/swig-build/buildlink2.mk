# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/25 08:52:37 epg Exp $

.if !defined(SWIG_BUILD_BUILDLINK2_MK)
SWIG_BUILD_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			swig-build
BUILDLINK_DEPENDS.swig-build?=		swig-build>=${SWIG_VERSION}
BUILDLINK_PKGSRCDIR.swig-build?=	../../devel/swig-build

# This package contains no run-time components.
BUILDLINK_DEPMETHOD.swig-build?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.swig-build=swig-build
BUILDLINK_PREFIX.swig-build_DEFAULT=	${LOCALBASE}

.include "../../devel/swig-build/Makefile.version"

BUILDLINK_TARGETS+=			swig-build-buildlink

swig-build-buildlink: _BUILDLINK_USE

.endif	# SWIG_BUILD_BUILDLINK2_MK
