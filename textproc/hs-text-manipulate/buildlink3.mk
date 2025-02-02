# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:58 pho Exp $

BUILDLINK_TREE+=	hs-text-manipulate

.if !defined(HS_TEXT_MANIPULATE_BUILDLINK3_MK)
HS_TEXT_MANIPULATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-manipulate+=	hs-text-manipulate>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-text-manipulate+=	hs-text-manipulate>=0.3.1.0nb5
BUILDLINK_PKGSRCDIR.hs-text-manipulate?=	../../textproc/hs-text-manipulate
.endif	# HS_TEXT_MANIPULATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-manipulate
