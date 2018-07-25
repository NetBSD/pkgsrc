# $NetBSD: buildlink3.mk,v 1.2 2018/07/25 00:26:30 minskim Exp $

BUILDLINK_TREE+=	hyperscan

.if !defined(HYPERSCAN_BUILDLINK3_MK)
HYPERSCAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hyperscan+=	hyperscan>=5.0.0
BUILDLINK_PKGSRCDIR.hyperscan?=		../../devel/hyperscan

.endif	# HYPERSCAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hyperscan
