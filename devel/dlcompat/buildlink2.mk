# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:10 jlam Exp $

.if !defined(DLCOMPAT_BUILDLINK2_MK)
DLCOMPAT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		dlcompat
BUILDLINK_DEPENDS.dlcompat?=	dlcompat>=20020508
BUILDLINK_PKGSRCDIR.dlcompat?=	../../devel/dlcompat

EVAL_PREFIX+=				BUILDLINK_PREFIX.dlcompat=dlcompat
BUILDLINK_PREFIX.dlcompat_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dlcompat=		include/dlfcn.h
BUILDLINK_FILES.dlcompat+=		lib/libdl.*

BUILDLINK_TARGETS+=		dlcompat-buildlink

dlcompat-buildlink: _BUILDLINK_USE

.endif  # DLCOMPAT_BUILDLINK2_MK
