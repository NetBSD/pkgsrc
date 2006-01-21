# $NetBSD: options.mk,v 1.1.1.1 2006/01/21 08:12:03 agc Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vtcl
PKG_SUPPORTED_OPTIONS=	tk83

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mtk83)
.  include "../../x11/tk/buildlink3.mk"
.else
.  include "../../x11/tk83/buildlink3.mk"
.endif
