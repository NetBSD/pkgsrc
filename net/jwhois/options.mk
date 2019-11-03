# $NetBSD: options.mk,v 1.3 2019/11/03 11:45:38 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jwhois
PKG_SUPPORTED_OPTIONS=		jwhois-enable-cache
PKG_OPTIONS_LEGACY_VARS+=	JWHOIS_ENABLE_CACHE:jwhois-enable-cache

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjwhois-enable-cache)
CONFIGURE_ARGS+=	--with-cache
CONF_FILES_PERMS+=	/dev/null /${VARBASE}/db/jwhois.db	\
			${ROOT_USER} nogroup 0666
.else
CONFIGURE_ARGS+=	--without-cache
.endif
