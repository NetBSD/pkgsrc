# $NetBSD: options.mk,v 1.2 2026/09/25 09:48:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	w3m
PKG_SUGGESTED_OPTIONS=	w3m

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		w3m

.if !empty(PKG_OPTIONS:Mw3m)
EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox
.include "../../editors/emacs/modules.mk"
.include "../../www/emacs-w3m-snapshot/buildlink3.mk"
PLIST.w3m=	yes
.endif
