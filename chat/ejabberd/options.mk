# $NetBSD: options.mk,v 1.2 2015/11/05 12:23:50 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	redis sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# Add Redis support
#
.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=		erlang-eredis-[0-9]*:../../databases/erlang-eredis
.endif

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		erlang-sqlite3-[0-9]*:../../databases/erlang-sqlite3
.endif
