# $NetBSD: buildlink3.mk,v 1.1 2026/06/23 06:49:07 drixter Exp $

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.5.5
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.endif

BUILDLINK_TREE+=	-knot
