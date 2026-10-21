# $NetBSD: buildlink3.mk,v 1.6 2026/10/21 19:27:28 drixter Exp $

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.6.2
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.endif

BUILDLINK_TREE+=	-knot
