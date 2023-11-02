# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:36:19 pho Exp $

BUILDLINK_TREE+=	hs-auto-update

.if !defined(HS_AUTO_UPDATE_BUILDLINK3_MK)
HS_AUTO_UPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-auto-update+=	hs-auto-update>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-auto-update+=	hs-auto-update>=0.1.6nb6
BUILDLINK_PKGSRCDIR.hs-auto-update?=	../../devel/hs-auto-update
.endif	# HS_AUTO_UPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-auto-update
