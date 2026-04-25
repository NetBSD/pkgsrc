# $NetBSD: buildlink3.mk,v 1.6 2026/04/25 19:35:46 vins Exp $

BUILDLINK_TREE+=	libgudev

.if !defined(LIBGUDEV_BUILDLINK3_MK)
LIBGUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgudev+=	libgudev>=238
BUILDLINK_ABI_DEPENDS.libgudev?=	libgudev>=238nb4
BUILDLINK_PKGSRCDIR.libgudev?=		../../devel/libgudev

BUILDLINK_INCDIRS.libgudev?=	include/gudev-1.0/gudev

.include "../../mk/bsd.fast.prefs.mk"

.include "../../mk/udev.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

pkgbase :=      libgudev
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libgudev:Mintrospection}
.  include "../../devel/gobject-introspection/buildlink3.mk"
.endif

.endif	# LIBGUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgudev
