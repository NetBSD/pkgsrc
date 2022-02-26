# $NetBSD: buildlink3.mk,v 1.4 2022/02/26 03:57:48 pho Exp $

BUILDLINK_TREE+=	hs-auto-update

.if !defined(HS_AUTO_UPDATE_BUILDLINK3_MK)
HS_AUTO_UPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-auto-update+=	hs-auto-update>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-auto-update+=	hs-auto-update>=0.1.6nb3
BUILDLINK_PKGSRCDIR.hs-auto-update?=	../../devel/hs-auto-update
.endif	# HS_AUTO_UPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-auto-update
