# $NetBSD: buildlink3.mk,v 1.45 2025/07/19 05:37:35 wiz Exp $

BUILDLINK_TREE+=	libpeas

.if !defined(LIBPEAS_BUILDLINK3_MK)
LIBPEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.4.0
BUILDLINK_ABI_DEPENDS.libpeas+=	libpeas>=1.26.0nb18
BUILDLINK_PKGSRCDIR.libpeas?=	../../devel/libpeas

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE+= 27
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBPEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpeas
