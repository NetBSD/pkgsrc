# $NetBSD: buildlink2.mk,v 1.2 2002/11/01 00:27:51 wiz Exp $
#

.if !defined(LIBARGPARSE_BUILDLINK2_MK)
LIBARGPARSE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libargparse
BUILDLINK_DEPENDS.libargparse?=		libargparse>=0.1.0000
BUILDLINK_PKGSRCDIR.libargparse?=	../../devel/libargparse

EVAL_PREFIX+=	BUILDLINK_PREFIX.libargparse=libargparse
BUILDLINK_PREFIX.libargparse_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libargparse+=	include/argparse.h
BUILDLINK_FILES.libargparse+=	lib/libargparse.*

BUILDLINK_TARGETS+=	libargparse-buildlink

libargparse-buildlink: _BUILDLINK_USE

.endif	# LIBARGPARSE_BUILDLINK2_MK
