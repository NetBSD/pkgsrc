# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 07:47:36 ryoon Exp $

BUILDLINK_TREE+=	graphite2

.if !defined(GRAPHITE2_BUILDLINK3_MK)
GRAPHITE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphite2+=	graphite2>=1.2
BUILDLINK_PKGSRCDIR.graphite2?=		../../graphics/graphite2
.endif # GRAPHITE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphite2
