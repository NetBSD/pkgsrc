# $NetBSD: buildlink2.mk,v 1.9 2003/09/19 17:24:31 adam Exp $

.if !defined(LIBWMF_BUILDLINK2_MK)
LIBWMF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libwmf
BUILDLINK_DEPENDS.libwmf?=	libwmf>=0.2.8nb2
BUILDLINK_PKGSRCDIR.libwmf?=	../../graphics/libwmf

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwmf=libwmf
BUILDLINK_PREFIX.libwmf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwmf=		include/libwmf/*.h
BUILDLINK_FILES.libwmf+=	include/libwmf/gd/*.h
BUILDLINK_FILES.libwmf+=	lib/libwmf-0.2.so*
BUILDLINK_FILES.libwmf+=	lib/libwmf.*
BUILDLINK_FILES.libwmf+=	lib/libwmflite-0.2.so*
BUILDLINK_FILES.libwmf+=	lib/libwmflite.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libwmf-buildlink

libwmf-buildlink: _BUILDLINK_USE

.endif	# LIBWMF_BUILDLINK2_MK
