# $NetBSD: buildlink3.mk,v 1.24 2022/08/11 05:09:06 gutteridge Exp $

BUILDLINK_TREE+=	libkcddb

.if !defined(LIBKCDDB_BUILDLINK3_MK)
LIBKCDDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcddb+=	libkcddb>=19.08.3
BUILDLINK_ABI_DEPENDS.libkcddb?=	libkcddb>=20.12.3nb10
BUILDLINK_PKGSRCDIR.libkcddb?=	../../multimedia/libkcddb

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKCDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcddb
