# $NetBSD: options.mk,v 1.4 2016/04/25 20:24:14 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	redis sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# Add Redis support
#
.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=		erlang-eredis>=1.0.8.20150910:../../databases/erlang-eredis
.endif

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		erlang-sqlite3>=1.1.5:../../databases/erlang-sqlite3
.endif
