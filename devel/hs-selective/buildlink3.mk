# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:10 pho Exp $

BUILDLINK_TREE+=	hs-selective

.if !defined(HS_SELECTIVE_BUILDLINK3_MK)
HS_SELECTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-selective+=	hs-selective>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-selective+=	hs-selective>=0.7.0.1nb1
BUILDLINK_PKGSRCDIR.hs-selective?=	../../devel/hs-selective
.endif	# HS_SELECTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-selective
