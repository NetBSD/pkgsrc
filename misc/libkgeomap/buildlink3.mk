# $NetBSD: buildlink3.mk,v 1.45 2021/01/01 09:52:12 ryoon Exp $

BUILDLINK_TREE+=	libkgeomap

.if !defined(LIBKGEOMAP_BUILDLINK3_MK)
LIBKGEOMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgeomap+=	libkgeomap>=19.08.3
BUILDLINK_ABI_DEPENDS.libkgeomap?=	libkgeomap>=20.04.1nb5
BUILDLINK_PKGSRCDIR.libkgeomap?=	../../misc/libkgeomap

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif	# LIBKGEOMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgeomap
