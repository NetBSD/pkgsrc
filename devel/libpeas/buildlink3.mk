# $NetBSD: buildlink3.mk,v 1.26 2018/11/14 22:21:17 kleink Exp $

BUILDLINK_TREE+=	libpeas

.if !defined(LIBPEAS_BUILDLINK3_MK)
LIBPEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.4.0
BUILDLINK_ABI_DEPENDS.libpeas+=	libpeas>=1.20.0nb5
BUILDLINK_PKGSRCDIR.libpeas?=	../../devel/libpeas

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE+= 27
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBPEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpeas
