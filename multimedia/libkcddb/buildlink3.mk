# $NetBSD: buildlink3.mk,v 1.48 2026/01/07 08:48:09 wiz Exp $

BUILDLINK_TREE+=	libkcddb

.if !defined(LIBKCDDB_BUILDLINK3_MK)
LIBKCDDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcddb+=	libkcddb>=25.08.2
BUILDLINK_ABI_DEPENDS.libkcddb?=	libkcddb>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libkcddb?=	../../multimedia/libkcddb

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKCDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcddb
