# $NetBSD: buildlink3.mk,v 1.34 2022/01/10 01:46:26 ryoon Exp $

BUILDLINK_TREE+=	libvisio

.if !defined(LIBVISIO_BUILDLINK3_MK)
LIBVISIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvisio+=	libvisio>=0.0.15
BUILDLINK_ABI_DEPENDS.libvisio+=	libvisio>=0.1.7nb14
BUILDLINK_PKGSRCDIR.libvisio?=		../../converters/libvisio

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libvisio
