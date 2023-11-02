# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:25 pho Exp $

BUILDLINK_TREE+=	hs-posix-paths

.if !defined(HS_POSIX_PATHS_BUILDLINK3_MK)
HS_POSIX_PATHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-posix-paths+=	hs-posix-paths>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-posix-paths+=	hs-posix-paths>=0.3.0.0nb1
BUILDLINK_PKGSRCDIR.hs-posix-paths?=	../../sysutils/hs-posix-paths

.include "../../devel/hs-unliftio/buildlink3.mk"
.endif	# HS_POSIX_PATHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-posix-paths
