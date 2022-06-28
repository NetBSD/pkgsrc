# $NetBSD: buildlink3.mk,v 1.13 2022/06/28 11:34:02 wiz Exp $

BUILDLINK_TREE+=	libpano13

.if !defined(LIBPANO13_BUILDLINK3_MK)
LIBPANO13_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpano13+=	libpano13>=2.9.17
BUILDLINK_ABI_DEPENDS.libpano13+=	libpano13>=2.9.21nb1
BUILDLINK_PKGSRCDIR.libpano13?=		../../graphics/libpano13

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LIBPANO13_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpano13
