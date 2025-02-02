# $NetBSD: buildlink3.mk,v 1.3 2025/02/02 13:05:21 pho Exp $

BUILDLINK_TREE+=	hs-selective

.if !defined(HS_SELECTIVE_BUILDLINK3_MK)
HS_SELECTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-selective+=	hs-selective>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-selective+=	hs-selective>=0.7.0.1nb2
BUILDLINK_PKGSRCDIR.hs-selective?=	../../devel/hs-selective
.endif	# HS_SELECTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-selective
