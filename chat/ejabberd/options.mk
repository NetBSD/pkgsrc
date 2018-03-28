# $NetBSD: options.mk,v 1.6 2018/03/28 21:51:09 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		erlang-sqlite3>=1.1.6:../../databases/erlang-sqlite3
.endif
