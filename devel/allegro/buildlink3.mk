# $NetBSD: buildlink3.mk,v 1.11 2012/02/20 15:39:37 reinoud Exp $

BUILDLINK_TREE+=	allegro

.if !defined(ALLEGRO_BUILDLINK3_MK)
ALLEGRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.4.2
BUILDLINK_PKGSRCDIR.allegro?=	../../devel/allegro

.endif	# ALLEGRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-allegro
