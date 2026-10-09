# $NetBSD: buildlink3.mk,v 1.5 2026/10/09 17:50:25 drixter Exp $

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.6.1
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.endif

BUILDLINK_TREE+=	-knot
