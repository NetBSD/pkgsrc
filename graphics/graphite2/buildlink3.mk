# $NetBSD: buildlink3.mk,v 1.3 2025/08/11 08:26:09 wiz Exp $

BUILDLINK_TREE+=	graphite2

.if !defined(GRAPHITE2_BUILDLINK3_MK)
GRAPHITE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphite2+=	graphite2>=1.2
BUILDLINK_ABI_DEPENDS.graphite2?=	graphite2>=1.3.14nb2
BUILDLINK_PKGSRCDIR.graphite2?=		../../graphics/graphite2
.endif # GRAPHITE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphite2
