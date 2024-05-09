# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:31:57 pho Exp $

BUILDLINK_TREE+=	hs-git-lfs

.if !defined(HS_GIT_LFS_BUILDLINK3_MK)
HS_GIT_LFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-git-lfs+=	hs-git-lfs>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-git-lfs+=	hs-git-lfs>=1.2.2nb1
BUILDLINK_PKGSRCDIR.hs-git-lfs?=	../../devel/hs-git-lfs

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_GIT_LFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-git-lfs
