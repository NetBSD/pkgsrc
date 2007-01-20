# $NetBSD: buildlink3.mk,v 1.9 2007/01/20 14:16:29 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ALLEGRO_BUILDLINK3_MK:=	${ALLEGRO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	allegro
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nallegro}
BUILDLINK_PACKAGES+=	allegro
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}allegro

.if !empty(ALLEGRO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.1.13
BUILDLINK_ABI_DEPENDS.allegro?=	allegro>=4.2.0nb1
BUILDLINK_PKGSRCDIR.allegro?=	../../devel/allegro
.endif	# ALLEGRO_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
