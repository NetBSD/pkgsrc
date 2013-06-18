# $NetBSD: options.mk,v 1.3 2013/06/18 09:19:21 mef Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	emacs-w3m
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		emacs-w3m
.if !empty(PKG_OPTIONS:Memacs-w3m)
.include "../../www/emacs-w3m/buildlink3.mk"
PLIST.emacs-w3m=	yes
.endif
