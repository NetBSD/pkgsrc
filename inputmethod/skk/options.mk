# $NetBSD: options.mk,v 1.1 2005/03/05 11:19:10 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup)
BUILD_DEPENDS+=	${PKGNAME_PREFIX}lookup-*:../../misc/lookup
PLIST_SUBST+=	FOR_LOOKUP=""
.else
PLIST_SUBST+=	FOR_LOOKUP="@comment "
.endif
