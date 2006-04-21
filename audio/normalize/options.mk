# $NetBSD: options.mk,v 1.1 2006/04/21 09:28:47 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.normalize
PKG_SUPPORTED_OPTIONS=	xmms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmms)
PLIST_SUBST+=	XMMS_PLUGIN=
.include "../../audio/xmms/buildlink3.mk"
.else
PLIST_SUBST+=	XMMS_PLUGIN="@comment "
.endif
