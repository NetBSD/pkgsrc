# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:37:05 pho Exp $

BUILDLINK_TREE+=	hs-word8

.if !defined(HS_WORD8_BUILDLINK3_MK)
HS_WORD8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-word8+=	hs-word8>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-word8+=	hs-word8>=0.1.3nb6
BUILDLINK_PKGSRCDIR.hs-word8?=		../../devel/hs-word8
.endif	# HS_WORD8_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-word8
