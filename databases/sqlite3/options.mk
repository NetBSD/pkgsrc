# $NetBSD: options.mk,v 1.10 2025/03/30 06:18:06 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqlite3
PKG_SUPPORTED_OPTIONS=		icu

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Micu}
CONFIGURE_ARGS+=	--icu-collations
CONFIGURE_ARGS+=	--with-icu-ldflags='-licui18n -licuuc -licudata'
.include "../../textproc/icu/buildlink3.mk"
.endif
