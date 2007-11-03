# $NetBSD: options.mk,v 1.6 2007/11/03 11:39:50 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	ldap sieve
PKG_OPTIONS_REQUIRED_GROUPS=	sql
PKG_OPTIONS_GROUP.sql=	mysql pgsql sqlite
PKG_SUGGESTED_OPTIONS=	mysql sieve

.include "../../mk/bsd.options.mk"

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUBST+=		MYSQL=""
INSTALLATION_DIRS+=	${DATADIR:Q}/sql/mysql
.else
PLIST_SUBST+=		MYSQL="@comment "
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUBST+=		PGSQL=""
INSTALLATION_DIRS+=	${DATADIR:Q}/sql/pgsql
.else
PLIST_SUBST+=		PGSQL="@comment "
.endif

###
### SQLite database support
###
.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUBST+=		SQLITE=""
INSTALLATION_DIRS+=	${DATADIR:Q}/sql/sqlite
.else
PLIST_SUBST+=		SQLITE="@comment "	
.endif

###
### Sieve support
###
.if !empty(PKG_OPTIONS:Msieve)
.include "../../mail/libsieve/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sieve=${BUILDLINK_PREFIX.libsieve:Q}
PLIST_SUBST+=		SIEVE=""
FILES_SUBST+=		TIMSIEVED="dbmailtimsieved"
RCD_SCRIPTS+=		dbmailtimsieved
.else
PLIST_SUBST+=		SIEVE="@comment "
FILES_SUBST+=		TIMSIEVED=""
.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client:Q}
PLIST_SUBST+=		LDAP=""
.else
PLIST_SUBST+=		LDAP="@comment "
.endif

###
### Migration scripts
###
post-install: dbmail-install-scripts

dbmail-install-scripts:
.for d in ${PKG_OPTIONS_GROUP.sql}
.  if !empty(PKG_OPTIONS:M${d})
	${INSTALL_DATA} ${WRKSRC:Q}/sql/$d/* ${DATADIR:Q}/sql/$d
.  endif
.endfor
