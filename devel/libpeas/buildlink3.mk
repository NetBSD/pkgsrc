# $NetBSD: buildlink3.mk,v 1.52 2026/09/02 19:01:38 wiz Exp $

BUILDLINK_TREE+=	libpeas

.if !defined(LIBPEAS_BUILDLINK3_MK)
LIBPEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.4.0
BUILDLINK_ABI_DEPENDS.libpeas+=	libpeas>=1.26.0nb23
BUILDLINK_PKGSRCDIR.libpeas?=	../../devel/libpeas

BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBPEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpeas
