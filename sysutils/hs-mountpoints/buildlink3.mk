# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:46 pho Exp $

BUILDLINK_TREE+=	hs-mountpoints

.if !defined(HS_MOUNTPOINTS_BUILDLINK3_MK)
HS_MOUNTPOINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2nb6
BUILDLINK_PKGSRCDIR.hs-mountpoints?=	../../sysutils/hs-mountpoints
.endif	# HS_MOUNTPOINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mountpoints
