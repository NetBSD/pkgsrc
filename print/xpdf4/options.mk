# $NetBSD: options.mk,v 1.2 2020/11/05 12:24:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xpdf4

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS=		cups
PKG_SUGGESTED_OPTIONS=		cups
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
CMAKE_ARGS+=	-DXPDFWIDGET_PRINTING=ON
.include "../../print/libcups/buildlink3.mk"
.elif ${OPSYS} != "Darwin"
CMAKE_ARGS+=	-DXPDFWIDGET_PRINTING=OFF
.endif
