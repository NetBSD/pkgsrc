# $NetBSD: buildlink3.mk,v 1.9 2026/09/02 19:02:33 wiz Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.4.8
BUILDLINK_ABI_DEPENDS.colord?=	colord>=1.4.8nb2
BUILDLINK_PKGSRCDIR.colord?=	../../graphics/colord

.include "../../devel/libgusb/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

pkgbase :=      colord
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.colord:Mudev}
.  include "../../devel/libgudev/buildlink3.mk"
.endif

.endif	# COLORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord
