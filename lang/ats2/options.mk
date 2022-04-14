# $NetBSD: options.mk,v 1.1 2022/04/14 20:13:19 nikita Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ats2

PKG_SUPPORTED_OPTIONS+=		emacs
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Memacs}
PLIST_VARS+=	emacs
PLIST.emacs=	yes
.endif
