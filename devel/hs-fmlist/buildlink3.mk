# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:31:54 pho Exp $

BUILDLINK_TREE+=	hs-fmlist

.if !defined(HS_FMLIST_BUILDLINK3_MK)
HS_FMLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fmlist+=	hs-fmlist>=0.9.4
BUILDLINK_ABI_DEPENDS.hs-fmlist+=	hs-fmlist>=0.9.4nb7
BUILDLINK_PKGSRCDIR.hs-fmlist?=		../../devel/hs-fmlist
.endif	# HS_FMLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fmlist
