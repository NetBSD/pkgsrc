# $NetBSD: buildlink3.mk,v 1.15 2014/05/05 00:47:45 ryoon Exp $

BUILDLINK_TREE+=	libpeas

.if !defined(LIBPEAS_BUILDLINK3_MK)
LIBPEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.4.0
BUILDLINK_ABI_DEPENDS.libpeas+=	libpeas>=1.8.1nb1
BUILDLINK_PKGSRCDIR.libpeas?=	../../devel/libpeas

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE+= 26 27
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBPEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpeas
