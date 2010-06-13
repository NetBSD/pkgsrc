# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:44:38 wiz Exp $

BUILDLINK_TREE+=	libpano13

.if !defined(LIBPANO13_BUILDLINK3_MK)
LIBPANO13_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpano13+=	libpano13>=2.9.14
BUILDLINK_ABI_DEPENDS.libpano13?=		libpano13>=2.9.14nb3
BUILDLINK_PKGSRCDIR.libpano13?=		../../graphics/libpano13

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LIBPANO13_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpano13
