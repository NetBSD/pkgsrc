# $NetBSD: buildlink3.mk,v 1.3 2022/09/09 15:21:13 wiz Exp $

BUILDLINK_TREE+=	graphene

.if !defined(GRAPHENE_BUILDLINK3_MK)
GRAPHENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphene+=	graphene>=1.10.2
BUILDLINK_ABI_DEPENDS.graphene?=	graphene>=1.10.2
BUILDLINK_PKGSRCDIR.graphene?=		../../graphics/graphene

.include "../../devel/glib2/buildlink3.mk"
.endif	# GRAPHENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphene
