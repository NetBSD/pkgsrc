# $NetBSD: buildlink3.mk,v 1.5 2011/11/01 06:50:28 sbd Exp $

BUILDLINK_TREE+=	libarchive

.if !defined(LIBARCHIVE_BUILDLINK3_MK)
LIBARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.2
BUILDLINK_ABI_DEPENDS.libarchive?=	libarchive>=2.8.4nb1
BUILDLINK_PKGSRCDIR.libarchive?=	../../archivers/libarchive

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # LIBARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libarchive
