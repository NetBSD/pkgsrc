# $NetBSD: options.mk,v 1.1 2014/08/17 10:45:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.notmuch
PKG_SUPPORTED_OPTIONS=	notmuch-emacs

.include "../../mk/bsd.options.mk"

###
### emacs support
###
PLIST_VARS+=		emacs
.if !empty(PKG_OPTIONS:Mnotmuch-emacs)
BUILD_DEPENDS+=		emacs>=24.0:../../editors/emacs
PLIST.emacs=		yes
.else
CONFIGURE_ARGS+=	--without-emacs
.endif
