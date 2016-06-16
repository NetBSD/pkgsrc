# $NetBSD: buildlink3.mk,v 1.12 2016/06/16 06:00:46 wiz Exp $

BUILDLINK_TREE+=	allegro

.if !defined(ALLEGRO_BUILDLINK3_MK)
ALLEGRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.4.2
BUILDLINK_PKGSRCDIR.allegro?=	../../devel/allegro

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif	# ALLEGRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro
