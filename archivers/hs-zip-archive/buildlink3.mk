# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:31:38 pho Exp $

BUILDLINK_TREE+=	hs-zip-archive

.if !defined(HS_ZIP_ARCHIVE_BUILDLINK3_MK)
HS_ZIP_ARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zip-archive+=	hs-zip-archive>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-zip-archive+=	hs-zip-archive>=0.4.3.2nb1
BUILDLINK_PKGSRCDIR.hs-zip-archive?=	../../archivers/hs-zip-archive

.include "../../security/hs-digest/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_ZIP_ARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zip-archive
