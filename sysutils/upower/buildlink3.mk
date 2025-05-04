# $NetBSD: buildlink3.mk,v 1.5 2025/05/04 05:55:49 vins Exp $

BUILDLINK_TREE+=	upower

.if !defined(UPOWER_BUILDLINK3_MK)
UPOWER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.upower+=	upower>=1.90.9
BUILDLINK_ABI_DEPENDS.upower?=	upower>=1.90.9
BUILDLINK_PKGSRCDIR.upower?=	../../sysutils/upower

.include "../../devel/glib2/buildlink3.mk"

pkgbase :=	upower
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.upower:Mpolkit}
.  include "../../security/polkit/buildlink3.mk"
.endif

.endif	# UPOWER_BUILDLINK3_MK

BUILDLINK_TREE+=	-upower
