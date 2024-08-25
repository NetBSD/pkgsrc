# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:11 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xpdf4

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS=		cups
PKG_SUGGESTED_OPTIONS=		cups
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
CMAKE_CONFIGURE_ARGS+=	-DXPDFWIDGET_PRINTING=ON
.include "../../print/libcups/buildlink3.mk"
.elif ${OPSYS} != "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DXPDFWIDGET_PRINTING=OFF
.endif
