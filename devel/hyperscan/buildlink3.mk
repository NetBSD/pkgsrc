# $NetBSD: buildlink3.mk,v 1.4 2024/12/29 14:56:38 adam Exp $

BUILDLINK_TREE+=	hyperscan

.if !defined(HYPERSCAN_BUILDLINK3_MK)
HYPERSCAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hyperscan+=	hyperscan>=5.0.0
BUILDLINK_ABI_DEPENDS.hyperscan+=	hyperscan>=5.0.0nb7
BUILDLINK_PKGSRCDIR.hyperscan?=		../../devel/hyperscan

.endif	# HYPERSCAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hyperscan
