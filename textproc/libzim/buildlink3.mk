# $NetBSD: buildlink3.mk,v 1.1 2025/08/31 19:16:21 wiz Exp $

BUILDLINK_TREE+=	libzim

.if !defined(LIBZIM_BUILDLINK3_MK)
LIBZIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzim+=	libzim>=9.3.0
BUILDLINK_PKGSRCDIR.libzim?=	../../textproc/libzim

.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.endif	# LIBZIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzim
