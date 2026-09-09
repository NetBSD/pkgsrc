# $NetBSD: buildlink3.mk,v 1.4 2026/09/09 14:25:20 drixter Exp $

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.6.0
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.endif

BUILDLINK_TREE+=	-knot
