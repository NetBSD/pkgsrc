# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:38:55 pho Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.6.4
BUILDLINK_ABI_DEPENDS.hs-tar+=	hs-tar>=0.6.4.0nb2
BUILDLINK_PKGSRCDIR.hs-tar?=	../../archivers/hs-tar

.include "../../sysutils/hs-directory-ospath-streaming/buildlink3.mk"
.include "../../devel/hs-file-io/buildlink3.mk"
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
