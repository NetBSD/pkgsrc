# $NetBSD: buildlink3.mk,v 1.2 2023/05/26 20:38:47 schmonz Exp $

BUILDLINK_TREE+=	lowdown

.if !defined(LOWDOWN_BUILDLINK3_MK)
LOWDOWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lowdown+=	lowdown>=1.0.2
BUILDLINK_PKGSRCDIR.lowdown?=	../../textproc/lowdown
.endif	# LOWDOWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lowdown
