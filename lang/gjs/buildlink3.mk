# $NetBSD: buildlink3.mk,v 1.4 2020/11/05 17:12:00 nia Exp $

BUILDLINK_TREE+=	gjs

.if !defined(GJS_BUILDLINK3_MK)
GJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gjs+=	gjs>=1.53.4
BUILDLINK_ABI_DEPENDS.gjs?=	gjs>=1.53.4nb3
BUILDLINK_PKGSRCDIR.gjs?=	../../wip/gjs

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/mozjs68/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# GJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gjs
