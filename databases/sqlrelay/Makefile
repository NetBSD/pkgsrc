# $NetBSD: Makefile,v 1.75 2022/06/28 11:31:38 wiz Exp $

COMMENT=	Database connection pooling middleware and API
PKGREVISION=	5

.include "../../databases/sqlrelay/Makefile.common"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-db2
CONFIGURE_ARGS+=	--disable-erlang
CONFIGURE_ARGS+=	--disable-firebird
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-mdbtools
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--disable-nodejs
CONFIGURE_ARGS+=	--disable-odbc
CONFIGURE_ARGS+=	--disable-oracle
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-sap
CONFIGURE_ARGS+=	--disable-tcl

INSTALL_MAKE_FLAGS+=	EXAMPLEDIR=${DESTDIR}${EGDIR}

CONF_FILES+=		${EGDIR}/sqlrelay.conf ${PKG_SYSCONFDIR}/sqlrelay.conf
CONF_FILES+=		${EGDIR}/sqlrelay.xsd ${PKG_SYSCONFDIR}/sqlrelay.xsd

SQLR_USER?=		sqlrelay
SQLR_GROUP?=		${SQLR_USER}
SQLR_DATA?=		${VARBASE}/sqlrelay

PKG_GROUPS+=		${SQLR_USER}
PKG_USERS+=		${SQLR_USER}:${SQLR_GROUP}
PKG_GECOS.${SQLR_USER}=	SQL Relay daemon user
PKG_HOME.${SQLR_USER}=	${SQLR_DATA}

OWN_DIRS_PERMS+=	${SQLR_DATA} ${SQLR_USER} ${SQLR_GROUP} 0775
OWN_DIRS_PERMS+=	${SQLR_DATA}/tmp ${SQLR_USER} ${SQLR_GROUP} 0775
OWN_DIRS_PERMS+=	${SQLR_DATA}/tmp/ipc ${SQLR_USER} ${SQLR_GROUP} 0775
OWN_DIRS_PERMS+=	${SQLR_DATA}/tmp/pids ${SQLR_USER} ${SQLR_GROUP} 0775
OWN_DIRS_PERMS+=	${SQLR_DATA}/tmp/sockets ${SQLR_USER} ${SQLR_GROUP} 0775
MAKE_DIRS+=		${PKG_SYSCONFDIR}/sqlrelay.conf.d

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		bundle
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

FILES_SUBST+=		SQLR_USER=${SQLR_USER}
FILES_SUBST+=		SQLR_GROUP=${SQLR_GROUP}
FILES_SUBST+=		SQLR_DATA=${SQLR_DATA}

RCD_SCRIPTS+=				sqlrelay sqlrcachemanager
RCD_SCRIPT_SRC.sqlrelay=		${WRKSRC}/init/rc.sqlrelay
RCD_SCRIPT_SRC.sqlrcachemanager=	${WRKSRC}/init/rc.sqlrcachemanager

.include "../../mk/bsd.pkg.mk"
