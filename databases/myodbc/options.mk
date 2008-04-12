# $NetBSD: options.mk,v 1.4 2008/04/12 22:42:59 jlam Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.myodbc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	myodbc-iodbc myodbc-unixodbc
PKG_SUPPORTED_OPTIONS=	myodbc-gui
PKG_SUGGESTED_OPTIONS=	myodbc-iodbc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gui

.if !empty(PKG_OPTIONS:Mmyodbc-gui)
.  include "../../x11/qt3-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gui
USE_LANGUAGES=		c c++
PLIST.gui=		yes
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !empty(PKG_OPTIONS:Mmyodbc-iodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iODBC=${BUILDLINK_PREFIX.iodbc}
CONFIGURE_ARGS+=	--with-odbc-ini=${PKG_SYSCONFDIR.iodbc}/odbc.ini
.endif

.if !empty(PKG_OPTIONS:Mmyodbc-unixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-unixODBC=${BUILDLINK_PREFIX.unixodbc}
CONFIGURE_ARGS+=	--with-odbc-ini=${PKG_SYSCONFDIR.unixodbc}/odbc.ini
.endif
