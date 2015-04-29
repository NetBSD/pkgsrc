# $NetBSD: options.mk,v 1.1 2015/04/29 10:03:58 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ejabberd
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT:Q}

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--enable-sqlite
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
PLIST_SRC+=		PLIST.sqlite
. include "../../databases/sqlite3/buildlink3.mk"
.endif
