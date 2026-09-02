# $NetBSD: buildlink3.mk,v 1.8 2026/09/02 19:04:38 wiz Exp $

BUILDLINK_TREE+=	upower

.if !defined(UPOWER_BUILDLINK3_MK)
UPOWER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.upower+=	upower>=1.90.9
BUILDLINK_ABI_DEPENDS.upower?=	upower>=1.91.2nb3
BUILDLINK_PKGSRCDIR.upower?=	../../sysutils/upower

.include "../../devel/glib2/buildlink3.mk"

pkgbase :=	upower
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.upower:Mpolkit}
.  include "../../security/polkit/buildlink3.mk"
.endif

.endif	# UPOWER_BUILDLINK3_MK

BUILDLINK_TREE+=	-upower
