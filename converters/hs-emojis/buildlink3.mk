# $NetBSD: buildlink3.mk,v 1.1 2020/01/15 11:53:16 pho Exp $

BUILDLINK_TREE+=	hs-emojis

.if !defined(HS_EMOJIS_BUILDLINK3_MK)
HS_EMOJIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-emojis+=	hs-emojis>=0.1
BUILDLINK_ABI_DEPENDS.hs-emojis+=	hs-emojis>=0.1
BUILDLINK_PKGSRCDIR.hs-emojis?=		../../converters/hs-emoji
.endif	# HS_EMOJIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-emojis
