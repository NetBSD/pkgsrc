# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:27 jlam Exp $

.if !defined(LIBWMF_BUILDLINK2_MK)
LIBWMF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libwmf
BUILDLINK_DEPENDS.libwmf?=	libwmf>=0.2.2nb1
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
