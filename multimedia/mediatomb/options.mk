# $NetBSD: options.mk,v 1.1 2008/04/11 14:41:27 agc Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.mediatomb

PKG_SUPPORTED_OPTIONS=	javascript

PKG_SUGGESTED_OPTIONS=	javascript

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjavascript)
.include "../../lang/spidermonkey/buildlink3.mk"
.endif
