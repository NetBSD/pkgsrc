# $NetBSD: options.mk,v 1.7 2025/04/28 12:38:17 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

# \todo Decide on a plan for options for databases, probably one of:
#   - always include erlang module if it doesn't force a dependency,
#     and never depend on the db package, and hence not having options
#
#   - for each, depend on db package and erlang module if option enabled
#
#   - for each, depend on db package if option enabled, and always
#     depend on erlang module


#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--enable-sqlite
DEPENDS+=		erlang-sqlite3>=1.1.13:../../databases/erlang-sqlite3
.endif
