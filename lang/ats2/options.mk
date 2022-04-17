# $NetBSD: options.mk,v 1.2 2022/04/17 18:48:17 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ats2

PKG_SUPPORTED_OPTIONS+=		emacs
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=	emacs

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Memacs}
PLIST.emacs=	yes
.endif
