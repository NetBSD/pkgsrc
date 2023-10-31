# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 16:16:37 pho Exp $

BUILDLINK_TREE+=	hs-posix-paths

.if !defined(HS_POSIX_PATHS_BUILDLINK3_MK)
HS_POSIX_PATHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-posix-paths+=	hs-posix-paths>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-posix-paths+=	hs-posix-paths>=0.3.0.0
BUILDLINK_PKGSRCDIR.hs-posix-paths?=	../../sysutils/hs-posix-paths

.include "../../devel/hs-unliftio/buildlink3.mk"
.endif	# HS_POSIX_PATHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-posix-paths
