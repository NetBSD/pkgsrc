# $NetBSD: buildlink3.mk,v 1.35 2023/10/21 17:11:27 gdt Exp $

BUILDLINK_TREE+=	libnotify

.if !defined(LIBNOTIFY_BUILDLINK3_MK)
LIBNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.7.0
BUILDLINK_ABI_DEPENDS.libnotify+=	libnotify>=0.8.1nb2
BUILDLINK_PKGSRCDIR.libnotify?=		../../sysutils/libnotify

pkgbase := libnotify
.include "../../mk/pkg-build-options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif # LIBNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify
