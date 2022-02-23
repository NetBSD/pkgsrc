# $NetBSD: buildlink3.mk,v 1.1 2022/02/23 08:20:29 fcambus Exp $

BUILDLINK_TREE+=	lowdown

.if !defined(LOWDOWN_BUILDLINK3_MK)
LOWDOWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lowdown+=	lowdown>=0.11.0
BUILDLINK_PKGSRCDIR.lowdown?=	../../textproc/lowdown
.endif	# LOWDOWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lowdown
