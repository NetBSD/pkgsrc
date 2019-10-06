# $NetBSD: buildlink3.mk,v 1.1 2019/10/06 15:50:31 fox Exp $

BUILDLINK_TREE+=	gjs

.if !defined(GJS_BUILDLINK3_MK)
GJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gjs+=	gjs>=1.53.4
BUILDLINK_PKGSRCDIR.gjs?=	../../lang/gjs

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/spidermonkey52/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# GJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gjs
