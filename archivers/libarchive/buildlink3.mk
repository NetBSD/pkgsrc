# $NetBSD: buildlink3.mk,v 1.8 2015/01/17 12:44:47 adam Exp $

BUILDLINK_TREE+=	libarchive

.if !defined(LIBARCHIVE_BUILDLINK3_MK)
LIBARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.1
BUILDLINK_ABI_DEPENDS.libarchive+=	libarchive>=3.1.2
BUILDLINK_PKGSRCDIR.libarchive?=	../../archivers/libarchive

CHECK_BUILTIN.libarchive:=	yes
.include "../../archivers/libarchive/builtin.mk"
CHECK_BUILTIN.libarchive:=	no

# A built-in libarchive is always using built-in zlib, bzip2, and xz.
.if empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif
.endif # LIBARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libarchive
