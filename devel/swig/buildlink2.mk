# $NetBSD: buildlink2.mk,v 1.1 2002/11/26 23:17:00 jlam Exp $

.if !defined(SWIG_BUILDLINK2_MK)
SWIG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		swig
BUILDLINK_DEPENDS.swig?=	swig>=1.1p5
BUILDLINK_PKGSRCDIR.swig?=	../../devel/swig

# This adds a build-dependency as swig only has a static library.
BUILDLINK_DEPMETHOD.swig?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.swig=swig
BUILDLINK_PREFIX.swig_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.swig=	include/swig.h
BUILDLINK_FILES.swig+=	lib/libswig.a

BUILDLINK_TARGETS+=	swig-buildlink

swig-buildlink: _BUILDLINK_USE

.endif	# SWIG_BUILDLINK2_MK
