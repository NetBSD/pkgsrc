# $NetBSD: buildlink3.mk,v 1.8 2026/07/28 03:10:59 ryoon Exp $

BUILDLINK_TREE+=	libcupsfilters

.if !defined(LIBCUPSFILTERS_BUILDLINK3_MK)
LIBCUPSFILTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcupsfilters+=	libcupsfilters>=2.1.1
BUILDLINK_ABI_DEPENDS.libcupsfilters?=	libcupsfilters>=2.1.1nb7
BUILDLINK_PKGSRCDIR.libcupsfilters?=	../../print/libcupsfilters

pkgbase := libcupsfilters
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libcupsfilters:Mdbus}
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.endif	# LIBCUPSFILTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcupsfilters
