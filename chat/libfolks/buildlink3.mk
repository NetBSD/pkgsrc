# $NetBSD: buildlink3.mk,v 1.5 2012/03/03 00:11:59 wiz Exp $

BUILDLINK_TREE+=	libfolks

.if !defined(LIBFOLKS_BUILDLINK3_MK)
LIBFOLKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfolks+=	libfolks>=0.3.6
BUILDLINK_ABI_DEPENDS.libfolks?=	libfolks>=0.4.2nb3
BUILDLINK_PKGSRCDIR.libfolks?=	../../chat/libfolks

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.endif	# LIBFOLKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfolks
