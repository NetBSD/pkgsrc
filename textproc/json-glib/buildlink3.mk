# $NetBSD: buildlink3.mk,v 1.16 2023/08/14 05:25:23 wiz Exp $
#

BUILDLINK_TREE+=	json-glib

.if !defined(JSON_GLIB_BUILDLINK3_MK)
JSON_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.6.2
BUILDLINK_ABI_DEPENDS.json-glib+=	json-glib>=1.6.2nb3
BUILDLINK_PKGSRCDIR.json-glib?=		../../textproc/json-glib

pkgbase := json-glib
.include "../../mk/pkg-build-options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # JSON_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-json-glib
