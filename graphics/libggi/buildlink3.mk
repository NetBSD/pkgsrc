# $NetBSD: buildlink3.mk,v 1.16 2015/08/17 17:11:19 wiz Exp $

BUILDLINK_TREE+=	libggi

.if !defined(LIBGGI_BUILDLINK3_MK)
LIBGGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggi+=	libggi>=2.2.2
BUILDLINK_ABI_DEPENDS.libggi?=	libggi>=2.2.2nb2
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # LIBGGI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggi
