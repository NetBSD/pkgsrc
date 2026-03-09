# $NetBSD: buildlink3.mk,v 1.3 2026/03/09 17:32:36 wiz Exp $

BUILDLINK_TREE+=	lowdown

.if !defined(LOWDOWN_BUILDLINK3_MK)
LOWDOWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lowdown+=	lowdown>=1.0.2
BUILDLINK_ABI_DEPENDS.lowdown+=	lowdown>=3.0.0
BUILDLINK_PKGSRCDIR.lowdown?=	../../textproc/lowdown
.endif	# LOWDOWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lowdown
