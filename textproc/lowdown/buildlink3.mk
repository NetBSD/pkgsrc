# $NetBSD: buildlink3.mk,v 1.4 2026/07/24 18:20:59 wiz Exp $

BUILDLINK_TREE+=	lowdown

.if !defined(LOWDOWN_BUILDLINK3_MK)
LOWDOWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lowdown+=	lowdown>=1.0.2
BUILDLINK_ABI_DEPENDS.lowdown+=	lowdown>=3.1.1
BUILDLINK_PKGSRCDIR.lowdown?=	../../textproc/lowdown
.endif	# LOWDOWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lowdown
