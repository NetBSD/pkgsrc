# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/05 18:13:17 drochner Exp $

BUILDLINK_TREE+=	folks

.if !defined(FOLKS_BUILDLINK3_MK)
FOLKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.folks+=	folks>=0.3.6
BUILDLINK_PKGSRCDIR.folks?=	../../chat/libfolks

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.endif	# FOLKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-folks
