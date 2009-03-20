# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:09 joerg Exp $

BUILDLINK_TREE+=	allegro

.if !defined(ALLEGRO_BUILDLINK3_MK)
ALLEGRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.1.13
BUILDLINK_ABI_DEPENDS.allegro?=	allegro>=4.2.0nb1
BUILDLINK_PKGSRCDIR.allegro?=	../../devel/allegro

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif # ALLEGRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro
