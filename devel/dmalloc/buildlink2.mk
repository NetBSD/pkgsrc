# $NetBSD: buildlink2.mk,v 1.2 2003/07/15 12:56:36 drochner Exp $
#

.if !defined(DMALLOC_BUILDLINK2_MK)
DMALLOC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			dmalloc
BUILDLINK_DEPENDS.dmalloc?=		dmalloc>=4.8.2nb2
BUILDLINK_PKGSRCDIR.dmalloc?=		../../devel/dmalloc

BUILDLINK_DEPMETHOD.dmalloc?=		build

EVAL_PREFIX+=	BUILDLINK_PREFIX.dmalloc=dmalloc
BUILDLINK_PREFIX.dmalloc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dmalloc+=	include/dmalloc.h
BUILDLINK_FILES.dmalloc+=	lib/libdmalloc.*
BUILDLINK_FILES.dmalloc+=	lib/libdmallocxx.*
BUILDLINK_FILES.dmalloc+=	lib/libdmallocth.*
BUILDLINK_FILES.dmalloc+=	lib/libdmallocthcxx.*

BUILDLINK_TARGETS+=	dmalloc-buildlink

dmalloc-buildlink: _BUILDLINK_USE

.endif	# DMALLOC_BUILDLINK2_MK
