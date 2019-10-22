# $NetBSD: options.mk,v 1.1 2019/10/22 22:21:26 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xpdf4

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS=		cups
PKG_SUGGESTED_OPTIONS=		cups
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
CMAKE_ARGS+=	-DXPDFWIDGET_PRINTING=ON
.include "../../print/cups-base/buildlink3.mk"
.elif ${OPSYS} != "Darwin"
CMAKE_ARGS+=	-DXPDFWIDGET_PRINTING=OFF
.endif
