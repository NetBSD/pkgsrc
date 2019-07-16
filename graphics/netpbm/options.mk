# $NetBSD: options.mk,v 1.1 2019/07/16 22:37:17 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netpbm
PKG_SUPPORTED_OPTIONS=	jasper

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jasper
.if !empty(PKG_OPTIONS:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
PLIST.jasper=	yes
.endif
