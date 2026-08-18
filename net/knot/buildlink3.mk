# $NetBSD: buildlink3.mk,v 1.2 2026/08/18 19:01:10 drixter Exp $

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.5.7
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.endif

BUILDLINK_TREE+=	-knot
