# $NetBSD: buildlink3.mk,v 1.18 2024/05/06 08:40:27 jperkin Exp $

BUILDLINK_TREE+=	libggi

.if !defined(LIBGGI_BUILDLINK3_MK)
LIBGGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggi+=	libggi>=2.2.2
BUILDLINK_ABI_DEPENDS.libggi?=	libggi>=2.2.2nb5
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
