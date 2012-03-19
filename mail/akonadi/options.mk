# $NetBSD: options.mk,v 1.1 2012/03/19 11:39:16 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.akonadi

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite

PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

###
### Use mysql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	qt4-mysql-[0-9]*:../../x11/qt4-mysql
CMAKE_ARGS+=	-DAKONADI_BUILD_QSQLITE=off
.  if ${_MYSQL_VERSION} == "55"
.    include "../../databases/mysql55-server/buildlink3.mk"
.  elif ${_MYSQL_VERSION} == "51"
.    include "../../databases/mysql51-server/buildlink3.mk"
.  else
.    include "../../databases/mysql5-server/buildlink3.mk"
.  endif
SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fix mysqld path.
SUBST_FILES.mysql=	server/CMakeLists.txt
SUBST_SED.mysql=	-e "s:MYSQLD_EXECUTABLE mysqld:MYSQLD_EXECUTABLE mysqld ${PREFIX}/libexec:"
.endif

###
### Use postgresql backend
###
.if !empty(PKG_OPTIONS:Mpgsql)
.	include "../../mk/pgsql.buildlink3.mk"
# XXX Not yet tested in pkgsrc
.endif

###
### Use sqlite backend
###
PLIST_VARS+=	sqlite
.if !empty(PKG_OPTIONS:Msqlite)
.	include "../../databases/sqlite3/buildlink3.mk"
CMAKE_ARGS+=	-DDATABASE_BACKEND=SQLITE
CMAKE_ARGS+=	-DINSTALL_QSQLITE_IN_QT_PREFIX=true
PLIST.sqlite=	yes
.endif
