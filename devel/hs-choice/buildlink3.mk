# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:00 pho Exp $

BUILDLINK_TREE+=	hs-choice

.if !defined(HS_CHOICE_BUILDLINK3_MK)
HS_CHOICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-choice+=	hs-choice>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-choice+=	hs-choice>=0.2.4.1nb1
BUILDLINK_PKGSRCDIR.hs-choice?=		../../devel/hs-choice

.endif	# HS_CHOICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-choice
