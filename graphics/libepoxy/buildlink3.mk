# $NetBSD: buildlink3.mk,v 1.7 2023/08/14 05:24:35 wiz Exp $

BUILDLINK_TREE+=	libepoxy

.if !defined(LIBEPOXY_BUILDLINK3_MK)
LIBEPOXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.2
BUILDLINK_ABI_DEPENDS.libepoxy?=		libepoxy>=1.5.10nb1
BUILDLINK_PKGSRCDIR.libepoxy?=		../../graphics/libepoxy

pkgbase:=		libepoxy
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libepoxy:Mx11}
.include "../../x11/libX11/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.endif	# LIBEPOXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoxy
