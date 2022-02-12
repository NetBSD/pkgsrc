# $NetBSD: buildlink3.mk,v 1.3 2022/02/12 08:50:32 pho Exp $

BUILDLINK_TREE+=	hs-fmlist

.if !defined(HS_FMLIST_BUILDLINK3_MK)
HS_FMLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fmlist+=	hs-fmlist>=0.9.4
BUILDLINK_ABI_DEPENDS.hs-fmlist+=	hs-fmlist>=0.9.4nb2
BUILDLINK_PKGSRCDIR.hs-fmlist?=		../../devel/hs-fmlist
.endif	# HS_FMLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fmlist
