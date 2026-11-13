# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:45 pho Exp $

BUILDLINK_TREE+=	hs-filelock

.if !defined(HS_FILELOCK_BUILDLINK3_MK)
HS_FILELOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filelock+=	hs-filelock>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-filelock+=	hs-filelock>=0.1.1.7nb2
BUILDLINK_PKGSRCDIR.hs-filelock?=	../../sysutils/hs-filelock

.endif	# HS_FILELOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filelock
