# $NetBSD: options.mk,v 1.5 2017/04/13 19:04:53 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		erlang-sqlite3>=1.1.5:../../databases/erlang-sqlite3
.endif
