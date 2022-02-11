# $NetBSD: buildlink3.mk,v 1.5 2022/02/11 12:18:39 pho Exp $

BUILDLINK_TREE+=	hs-emojis

.if !defined(HS_EMOJIS_BUILDLINK3_MK)
HS_EMOJIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-emojis+=	hs-emojis>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-emojis+=	hs-emojis>=0.1.2
BUILDLINK_PKGSRCDIR.hs-emojis?=		../../converters/hs-emojis
.endif	# HS_EMOJIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-emojis
