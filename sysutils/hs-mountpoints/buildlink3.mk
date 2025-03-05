# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:53 pho Exp $

BUILDLINK_TREE+=	hs-mountpoints

.if !defined(HS_MOUNTPOINTS_BUILDLINK3_MK)
HS_MOUNTPOINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2nb4
BUILDLINK_PKGSRCDIR.hs-mountpoints?=	../../sysutils/hs-mountpoints
.endif	# HS_MOUNTPOINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mountpoints
