# $NetBSD: buildlink3.mk,v 1.8 2014/10/27 08:57:06 jnemeth Exp $

BUILDLINK_TREE+=	libfolks

.if !defined(LIBFOLKS_BUILDLINK3_MK)
LIBFOLKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfolks+=	libfolks>=0.3.6
BUILDLINK_ABI_DEPENDS.libfolks+=	libfolks>=0.4.2nb4
BUILDLINK_PKGSRCDIR.libfolks?=	../../chat/libfolks

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/libgee0.6/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.endif	# LIBFOLKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfolks
