# $NetBSD: options.mk,v 1.1.1.1 2009/08/05 22:23:57 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	w3m
PKG_SUGGESTED_OPTIONS=	w3m

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		w3m

.if !empty(PKG_OPTIONS:Mw3m)
.include "../../www/emacs-w3m-snapshot/buildlink3.mk"
PLIST.w3m=	yes
.endif
