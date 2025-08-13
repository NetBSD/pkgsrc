# $NetBSD: buildlink3.mk,v 1.16 2025/08/13 11:06:24 pho Exp $

BUILDLINK_TREE+=	hs-emojis

.if !defined(HS_EMOJIS_BUILDLINK3_MK)
HS_EMOJIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-emojis+=	hs-emojis>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-emojis+=	hs-emojis>=0.1.4.1nb3
BUILDLINK_PKGSRCDIR.hs-emojis?=		../../converters/hs-emojis
.endif	# HS_EMOJIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-emojis
