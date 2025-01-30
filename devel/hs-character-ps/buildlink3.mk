# $NetBSD: buildlink3.mk,v 1.1 2025/01/30 04:47:11 pho Exp $

BUILDLINK_TREE+=	hs-character-ps

.if !defined(HS_CHARACTER_PS_BUILDLINK3_MK)
HS_CHARACTER_PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-character-ps+=	hs-character-ps>=0.1
BUILDLINK_ABI_DEPENDS.hs-character-ps+=	hs-character-ps>=0.1
BUILDLINK_PKGSRCDIR.hs-character-ps?=	../../devel/hs-character-ps

.endif	# HS_CHARACTER_PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-character-ps
