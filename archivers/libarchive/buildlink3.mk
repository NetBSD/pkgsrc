# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:23:50 joerg Exp $

BUILDLINK_TREE+=	libarchive

.if !defined(LIBARCHIVE_BUILDLINK3_MK)
LIBARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.2
BUILDLINK_PKGSRCDIR.libarchive?=	../../archivers/libarchive

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # LIBARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libarchive
