# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:25 pho Exp $

BUILDLINK_TREE+=	hs-mountpoints

.if !defined(HS_MOUNTPOINTS_BUILDLINK3_MK)
HS_MOUNTPOINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-mountpoints+=	hs-mountpoints>=1.0.2nb1
BUILDLINK_PKGSRCDIR.hs-mountpoints?=	../../sysutils/hs-mountpoints
.endif	# HS_MOUNTPOINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mountpoints
