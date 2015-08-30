# $NetBSD: options.mk,v 1.11 2015/08/30 17:52:27 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	ldap sieve
PKG_OPTIONS_NONEMPTY_SETS=	sql
PKG_OPTIONS_SET.sql=	mysql pgsql sqlite
PKG_SUGGESTED_OPTIONS=	mysql sieve

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap mysql pgsql sieve sqlite

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
PLIST.mysql=		yes
INSTALLATION_DIRS+=	${DATADIR}/sql/mysql/upgrades
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
PLIST.pgsql=		yes
INSTALLATION_DIRS+=	${DATADIR}/sql/postgresql/upgrades
.endif

###
### SQLite database support
###
.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite
PLIST.sqlite=		yes
INSTALLATION_DIRS+=	${DATADIR}/sql/sqlite/upgrades
.endif

###
### Sieve support
###
.if !empty(PKG_OPTIONS:Msieve)
.include "../../mail/libsieve/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sieve=${BUILDLINK_PREFIX.libsieve}
PLIST.sieve=		yes
FILES_SUBST+=		TIMSIEVED="dbmailtimsieved"
RCD_SCRIPTS+=		dbmailtimsieved
.else
FILES_SUBST+=		TIMSIEVED=""
.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.endif

###
### Migration scripts
###
post-install: dbmail-install-scripts

.PHONY: dbmail-install-scripts
dbmail-install-scripts:
.if !empty(PKG_OPTIONS:Mmysql)
	${INSTALL_DATA} ${WRKSRC}/sql/mysql/*.* ${DESTDIR}${DATADIR}/sql/mysql
	${INSTALL_DATA} ${WRKSRC}/sql/mysql/upgrades/*.* ${DESTDIR}${DATADIR}/sql/mysql/upgrades
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
	${INSTALL_DATA} ${WRKSRC}/sql/postgresql/*.* ${DESTDIR}${DATADIR}/sql/postgresql
	${INSTALL_DATA} ${WRKSRC}/sql/postgresql/upgrades/*.* ${DESTDIR}${DATADIR}/sql/postgresql/upgrades
.endif
.if !empty(PKG_OPTIONS:Msqlite)
	${INSTALL_DATA} ${WRKSRC}/sql/sqlite/*.* ${DESTDIR}${DATADIR}/sql/sqlite
	${INSTALL_DATA} ${WRKSRC}/sql/sqlite/upgrades/*.* ${DESTDIR}${DATADIR}/sql/sqlite/upgrades
.endif
