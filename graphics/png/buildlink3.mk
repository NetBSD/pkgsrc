# $NetBSD: buildlink3.mk,v 1.27 2013/02/16 11:16:06 wiz Exp $

BUILDLINK_TREE+=	png

.if !defined(PNG_BUILDLINK3_MK)
PNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.png+=	png>=1.2.4
BUILDLINK_ABI_DEPENDS.png+=	png>=1.6.0nb1
BUILDLINK_PKGSRCDIR.png?=	../../graphics/png

# keep this in sync with the same code in Makefile
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

# Some software directly tries to link against -lpng instead of
# using pkg-config or libpng-config to find the proper arguments
# instead of installing symlinks. Work around this with buildlink
# magic: packages outside pkgsrc will need to be converted to
# one of the proper methods or fail.
BUILDLINK_TRANSFORM+=	l:png:png16

.include "../../devel/zlib/buildlink3.mk"
.endif # PNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-png
