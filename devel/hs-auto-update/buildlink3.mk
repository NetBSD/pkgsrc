# $NetBSD: buildlink3.mk,v 1.10 2025/01/30 16:00:10 pho Exp $

BUILDLINK_TREE+=	hs-auto-update

.if !defined(HS_AUTO_UPDATE_BUILDLINK3_MK)
HS_AUTO_UPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-auto-update+=	hs-auto-update>=0.2.6
BUILDLINK_ABI_DEPENDS.hs-auto-update+=	hs-auto-update>=0.2.6
BUILDLINK_PKGSRCDIR.hs-auto-update?=	../../devel/hs-auto-update
.endif	# HS_AUTO_UPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-auto-update
