# $NetBSD: buildlink2.mk,v 1.2 2002/09/15 05:35:27 rh Exp $

.if !defined(LIBBONOBOUI_BUILDLINK2_MK)
LIBBONOBOUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libbonoboui
BUILDLINK_DEPENDS.libbonoboui?=	libbonoboui>=2.0.3nb1
BUILDLINK_PKGSRCDIR.libbonoboui?=	../../devel/libbonoboui

EVAL_PREFIX+=	BUILDLINK_PREFIX.libbonoboui=libbonoboui
BUILDLINK_PREFIX.libbonoboui_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libbonoboui+=	include/libbonoboui-2.0/bonobo/*
BUILDLINK_FILES.libbonoboui+=	include/libbonoboui-2.0/*
BUILDLINK_FILES.libbonoboui+=	lib/libbonoboui-2.*
BUILDLINK_FILES.libbonoboui+=	lib/libglade/2.0/libbonobo.*
BUILDLINK_FILES.libbonoboui+=	lib/pkgconfig/libbonoboui-2.0.pc

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libbonoboui-buildlink

libbonoboui-buildlink: _BUILDLINK_USE

.endif	# LIBBONOBOUI_BUILDLINK2_MK
