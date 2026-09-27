# $NetBSD: buildlink3.mk,v 1.55 2026/09/27 11:37:53 tnn Exp $

BUILDLINK_TREE+=	libkcddb

.if !defined(LIBKCDDB_BUILDLINK3_MK)
LIBKCDDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcddb+=	libkcddb>=25.08.2
BUILDLINK_ABI_DEPENDS.libkcddb?=	libkcddb>=26.08.0nb1
BUILDLINK_PKGSRCDIR.libkcddb?=	../../multimedia/libkcddb

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKCDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcddb
