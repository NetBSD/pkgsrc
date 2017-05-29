# $NetBSD: buildlink3.mk,v 1.10 2017/05/29 11:01:43 jperkin Exp $

BUILDLINK_TREE+=	libarchive

.if !defined(LIBARCHIVE_BUILDLINK3_MK)
LIBARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.1
BUILDLINK_ABI_DEPENDS.libarchive+=	libarchive>=3.3.1
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
