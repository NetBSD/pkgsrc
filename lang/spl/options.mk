# $NetBSD: options.mk,v 1.1 2011/12/18 16:57:22 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spl

PKG_SUPPORTED_OPTIONS=	sqlite

PLIST_VARS+=	sqlite

.include "../../mk/bsd.options.mk"

###
### Use mysql or sqlite backend
###
.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite=	yes
.else
MAKE_FLAGS=	ENABLE_SQLITE_SUPPORT=0
.endif
