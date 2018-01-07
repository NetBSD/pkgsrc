# $NetBSD: buildlink3.mk,v 1.28 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	libnotify

.if !defined(LIBNOTIFY_BUILDLINK3_MK)
LIBNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.7.0
BUILDLINK_ABI_DEPENDS.libnotify?=	libnotify>=0.7.6nb3
BUILDLINK_PKGSRCDIR.libnotify?=		../../sysutils/libnotify

pkgbase := libnotify
.include "../../mk/pkg-build-options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif # LIBNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify
