# $NetBSD: options.mk,v 1.2 2008/04/12 22:42:58 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.normalize
PKG_SUPPORTED_OPTIONS=	xmms

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		xmms

.if !empty(PKG_OPTIONS:Mxmms)
PLIST.xmms=		yes
.include "../../audio/xmms/buildlink3.mk"
.endif
