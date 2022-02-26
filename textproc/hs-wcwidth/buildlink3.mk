# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:32 pho Exp $

BUILDLINK_TREE+=	hs-wcwidth

.if !defined(HS_WCWIDTH_BUILDLINK3_MK)
HS_WCWIDTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wcwidth+=	hs-wcwidth>=0.0.2
BUILDLINK_ABI_DEPENDS.hs-wcwidth+=	hs-wcwidth>=0.0.2nb4
BUILDLINK_PKGSRCDIR.hs-wcwidth?=	../../textproc/hs-wcwidth
.endif	# HS_WCWIDTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wcwidth
