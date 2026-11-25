# $NetBSD: buildlink3.mk,v 1.9 2026/11/25 14:42:13 wiz Exp $

BUILDLINK_TREE+=	libepoxy

.if !defined(LIBEPOXY_BUILDLINK3_MK)
LIBEPOXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.2
BUILDLINK_ABI_DEPENDS.libepoxy+=	libepoxy>=1.5.10nb1
BUILDLINK_PKGSRCDIR.libepoxy?=		../../graphics/libepoxy

pkgbase:=		libepoxy
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libepoxy:Mx11}
.include "../../x11/libX11/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../mk/mesa.buildlink3.mk"
.endif
.endif	# LIBEPOXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoxy
