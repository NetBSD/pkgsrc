# $NetBSD: options.mk,v 1.1 2023/08/31 15:55:38 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.meli

PKG_SUPPORTED_OPTIONS+=	dbus debug gpgme notmuch sqlite3 w3m
PKG_SUGGESTED_OPTIONS=	dbus gpgme notmuch sqlite3

.include "../../mk/bsd.options.mk"

##
## D-Bus support
## Enable showing notification via dbus.
##
.if !empty(PKG_OPTIONS:Mdbus)
CARGO_FEATURES+=	dbus-notifications
.include "../../sysutils/dbus/buildlink3.mk"
.endif

##
## GPG support
##
.if !empty(PKG_OPTIONS:Mgpgme)
CARGO_FEATURES+=	gpgme
.include "../../security/gpgme/buildlink3.mk"
.endif

##
## Notmuch support
## Use notmuch database as a mail backend.
##
.if !empty(PKG_OPTIONS:Mnotmuch)
CARGO_FEATURES+=	notmuch
.include "../../mail/notmuch/buildlink3.mk"
.endif

##
## SQLite support
## Build fast search indexes in local sqlite3 databases.
##
.if !empty(PKG_OPTIONS:Msqlite3)
CARGO_FEATURES+=	sqlite3
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib
RUSTFLAGS+=             -C link-arg=-L${BUILDLINK_PREFIX.sqlite3}/lib
.include "../../databases/sqlite3/buildlink3.mk"
.endif

##
## Debug
## Enable various trace debug logs
##
.if !empty(PKG_OPTIONS:Mdebug)
CARGO_FEATURES+=	debug-tracing
.endif

##
## HTML Rendering
## Use w3m to render HTML pages.
##
.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-[0-9]*:../../www/w3m
.endif
