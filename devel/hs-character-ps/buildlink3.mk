# $NetBSD: buildlink3.mk,v 1.5 2026/11/13 14:38:51 pho Exp $

BUILDLINK_TREE+=	hs-character-ps

.if !defined(HS_CHARACTER_PS_BUILDLINK3_MK)
HS_CHARACTER_PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-character-ps+=	hs-character-ps>=0.1
BUILDLINK_ABI_DEPENDS.hs-character-ps+=	hs-character-ps>=0.1nb4
BUILDLINK_PKGSRCDIR.hs-character-ps?=	../../devel/hs-character-ps

.endif	# HS_CHARACTER_PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-character-ps
