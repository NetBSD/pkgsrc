# $NetBSD: options.mk,v 1.2 2005/03/05 11:26:48 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup)
BUILD_DEPENDS+=	${PKGNAME_PREFIX}lookup-[0-9]*:../../misc/lookup
PLIST_SUBST+=	FOR_LOOKUP=""
.else
PLIST_SUBST+=	FOR_LOOKUP="@comment "
.endif
