# $NetBSD: buildlink2.mk,v 1.8 2003/11/12 01:31:48 salo Exp $

.if !defined(LIBGNOMEUI_BUILDLINK2_MK)
LIBGNOMEUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgnomeui
BUILDLINK_DEPENDS.libgnomeui?=	libgnomeui>=2.2.2nb2
BUILDLINK_PKGSRCDIR.libgnomeui?=	../../devel/libgnomeui

EVAL_PREFIX+=			BUILDLINK_PREFIX.libgnomeui=libgnomeui
BUILDLINK_PREFIX.libgnomeui_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgnomeui=	include/libgnomeui-2.0/libgnomeui/*
BUILDLINK_FILES.libgnomeui+=	include/libgnomeui-2.0/*
BUILDLINK_FILES.libgnomeui+=	lib/libglade/2.0/libgnome.*
BUILDLINK_FILES.libgnomeui+=	lib/libgnomeui-2.*
BUILDLINK_FILES.libgnomeui+=	lib/pkgconfig/libgnomeui-2.0.pc

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"

BUILDLINK_TARGETS+=	libgnomeui-buildlink

libgnomeui-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEUI_BUILDLINK2_MK
