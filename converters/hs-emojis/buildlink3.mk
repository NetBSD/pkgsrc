# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:12 pho Exp $

BUILDLINK_TREE+=	hs-emojis

.if !defined(HS_EMOJIS_BUILDLINK3_MK)
HS_EMOJIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-emojis+=	hs-emojis>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-emojis+=	hs-emojis>=0.1.3nb1
BUILDLINK_PKGSRCDIR.hs-emojis?=		../../converters/hs-emojis
.endif	# HS_EMOJIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-emojis
