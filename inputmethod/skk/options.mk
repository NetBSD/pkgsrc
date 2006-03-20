# $NetBSD: options.mk,v 1.3 2006/03/20 05:30:33 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup)
BUILD_DEPENDS+=	${EMACS_PKGNAME_PREFIX}lookup-[0-9]*:../../misc/lookup
PLIST_SUBST+=	FOR_LOOKUP=""
.else
PLIST_SUBST+=	FOR_LOOKUP="@comment "
.endif
