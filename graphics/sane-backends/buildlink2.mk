# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:28 jlam Exp $

.if !defined(SANE_BUILDLINK2_MK)
SANE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sane
BUILDLINK_DEPENDS.sane?=	sane-backends>=1.0.3
BUILDLINK_PKGSRCDIR.sane?=	../../graphics/sane-backends

EVAL_PREFIX+=			BUILDLINK_PREFIX.sane=sane-backends
BUILDLINK_PREFIX.sane_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sane=		include/sane/*.h
BUILDLINK_FILES.sane+=		lib/libsane.*

.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	sane-buildlink

sane-buildlink: _BUILDLINK_USE

.endif	# SANE_BUILDLINK2_MK
