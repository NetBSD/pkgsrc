# $NetBSD: buildlink3.mk,v 1.2 2013/04/22 12:33:47 obache Exp $

BUILDLINK_TREE+=	libnotify07

.if !defined(LIBNOTIFY07_BUILDLINK3_MK)
LIBNOTIFY07_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify07+=	libnotify07>=0.3.2
BUILDLINK_ABI_DEPENDS.libnotify07+=	libnotify07>=0.7.0
BUILDLINK_PKGSRCDIR.libnotify07?=	../../sysutils/libnotify07

pkgbase := libnotify07
.include "../../mk/pkg-build-options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif # LIBNOTIFY07_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify07
