# $NetBSD: buildlink3.mk,v 1.7 2026/09/27 11:36:45 tnn Exp $

BUILDLINK_TREE+=	graphene

.if !defined(GRAPHENE_BUILDLINK3_MK)
GRAPHENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphene+=	graphene>=1.10.2
BUILDLINK_ABI_DEPENDS.graphene?=	graphene>=1.10.8nb5
BUILDLINK_PKGSRCDIR.graphene?=		../../graphics/graphene

.include "../../devel/glib2/buildlink3.mk"
.endif	# GRAPHENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphene
