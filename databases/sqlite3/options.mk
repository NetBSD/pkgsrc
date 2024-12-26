# $NetBSD: options.mk,v 1.9 2024/12/26 22:04:28 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqlite3
PKG_SUPPORTED_OPTIONS=		icu

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Micu}
CFLAGS+=	-DSQLITE_ENABLE_ICU=1
LDFLAGS+=	-licui18n -licuuc -licudata
.include "../../textproc/icu/buildlink3.mk"
.endif
