# $NetBSD: buildlink3.mk,v 1.13 2020/03/08 16:48:14 wiz Exp $
#

BUILDLINK_TREE+=	json-glib

.if !defined(JSON_GLIB_BUILDLINK3_MK)
JSON_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.6.2
BUILDLINK_ABI_DEPENDS.json-glib+=	json-glib>=1.4.4nb1
BUILDLINK_PKGSRCDIR.json-glib?=		../../textproc/json-glib

pkgbase := json-glib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.json-glib:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif # JSON_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-glib
