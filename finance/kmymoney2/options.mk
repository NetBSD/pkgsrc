# $NetBSD: options.mk,v 1.5 2014/01/06 09:19:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmymoney2
PKG_SUPPORTED_OPTIONS=	libofx sqlite3
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libofx sqlite3

.if !empty(PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
PLIST.libofx=		yes
.endif

# sqlite3 support builds but does not function properly
.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite3=		yes
CONFIGURE_ARGS+=	--enable-sqlite3
.else
CONFIGURE_ARGS+=	--disable-sqlite3
.endif
