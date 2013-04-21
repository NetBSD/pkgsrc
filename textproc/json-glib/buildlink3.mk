# $NetBSD: buildlink3.mk,v 1.9 2013/04/21 14:04:20 rodent Exp $
#

BUILDLINK_TREE+=	json-glib

.if !defined(JSON_GLIB_BUILDLINK3_MK)
JSON_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.6.2
BUILDLINK_ABI_DEPENDS.json-glib+=		json-glib>=0.14.2nb3
BUILDLINK_PKGSRCDIR.json-glib?=		../../textproc/json-glib

pkgbase := json-glib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.json-glib:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.json-glib:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # JSON_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-glib
