# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:42 wiz Exp $

.if !defined(LIBWMF_BUILDLINK2_MK)
LIBWMF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libwmf
BUILDLINK_DEPENDS.libwmf?=	libwmf>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libwmf?=	../../graphics/libwmf

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwmf=libwmf
BUILDLINK_PREFIX.libwmf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwmf=		include/libwmf/libwmf/*.h
BUILDLINK_FILES.libwmf+=	include/libwmf/libwmf/gd/*.h
BUILDLINK_FILES.libwmf+=	lib/libwmf-0.2.so*
BUILDLINK_FILES.libwmf+=	lib/libwmf.*

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libwmf-buildlink

libwmf-buildlink: _BUILDLINK_USE

.endif	# LIBWMF_BUILDLINK2_MK
