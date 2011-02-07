# $NetBSD: options.mk,v 1.1.1.1 2011/02/07 06:31:22 schnoebe Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spectrum
PKG_OPTIONS_REQUIRED_GROUPS=	storage
PKG_OPTIONS_OPTIONAL_GROUPS=	debug
PKG_OPTIONS_GROUP.storage=	mysql sqlite
PKG_OPTIONS_GROUP.debug=	debug cppunit

PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			sqlite mysql

.if !empty(PKG_OPTIONS:Msqlite)
. include "../../databases/poco-data-sqlite/buildlink3.mk"
PLIST.sqlite=	yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
. include "../../databases/poco-data-mysql/buildlink3.mk"
PLIST.mysql=	yes
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

.if !empty(PKG_OPTIONS:Mcppunit)
. include "../../devel/cppunit/buildlink3.mk"
.endif
