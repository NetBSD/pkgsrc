# $NetBSD: buildlink3.mk,v 1.8 2023/01/25 01:52:55 pho Exp $

BUILDLINK_TREE+=	hs-unix-compat

.if !defined(HS_UNIX_COMPAT_BUILDLINK3_MK)
HS_UNIX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unix-compat+=	hs-unix-compat>=0.6
BUILDLINK_ABI_DEPENDS.hs-unix-compat+=	hs-unix-compat>=0.6
BUILDLINK_PKGSRCDIR.hs-unix-compat?=	../../devel/hs-unix-compat
.endif	# HS_UNIX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unix-compat
