# $NetBSD: buildlink3.mk,v 1.1 2026/08/09 17:24:32 wiz Exp $

BUILDLINK_TREE+=	libshumate

.if !defined(LIBSHUMATE_BUILDLINK3_MK)
LIBSHUMATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libshumate+=	libshumate>=1.6.2
BUILDLINK_PKGSRCDIR.libshumate?=	../../geography/libshumate

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBSHUMATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libshumate
