# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:06:00 pho Exp $

BUILDLINK_TREE+=	hs-wcwidth

.if !defined(HS_WCWIDTH_BUILDLINK3_MK)
HS_WCWIDTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wcwidth+=	hs-wcwidth>=0.0.2
BUILDLINK_ABI_DEPENDS.hs-wcwidth+=	hs-wcwidth>=0.0.2nb9
BUILDLINK_PKGSRCDIR.hs-wcwidth?=	../../textproc/hs-wcwidth
.endif	# HS_WCWIDTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wcwidth
