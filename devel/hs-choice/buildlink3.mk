# $NetBSD: buildlink3.mk,v 1.4 2025/08/13 11:06:33 pho Exp $

BUILDLINK_TREE+=	hs-choice

.if !defined(HS_CHOICE_BUILDLINK3_MK)
HS_CHOICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-choice+=	hs-choice>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-choice+=	hs-choice>=0.2.4.1nb3
BUILDLINK_PKGSRCDIR.hs-choice?=		../../devel/hs-choice

.endif	# HS_CHOICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-choice
