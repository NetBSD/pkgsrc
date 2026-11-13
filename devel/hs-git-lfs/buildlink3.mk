# $NetBSD: buildlink3.mk,v 1.9 2026/11/13 14:39:00 pho Exp $

BUILDLINK_TREE+=	hs-git-lfs

.if !defined(HS_GIT_LFS_BUILDLINK3_MK)
HS_GIT_LFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-git-lfs+=	hs-git-lfs>=1.2.3
BUILDLINK_ABI_DEPENDS.hs-git-lfs+=	hs-git-lfs>=1.2.3nb4
BUILDLINK_PKGSRCDIR.hs-git-lfs?=	../../devel/hs-git-lfs

.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.endif	# HS_GIT_LFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-git-lfs
