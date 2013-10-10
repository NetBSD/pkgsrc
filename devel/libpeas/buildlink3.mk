# $NetBSD: buildlink3.mk,v 1.13 2013/10/10 14:41:56 ryoon Exp $

BUILDLINK_TREE+=	libpeas

.if !defined(LIBPEAS_BUILDLINK3_MK)
LIBPEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.4.0
BUILDLINK_ABI_DEPENDS.libpeas+=	libpeas>=1.6.2nb6
BUILDLINK_PKGSRCDIR.libpeas?=	../../devel/libpeas

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBPEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpeas
