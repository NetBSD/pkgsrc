# $NetBSD: Makefile,v 1.60 2019/07/01 04:07:46 ryoon Exp $

COMMENT=		Database connection pooling middleware and API
PKGREVISION=		8

.include "../../databases/sqlrelay/Makefile.common"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-db2 --disable-erlang --disable-firebird	\
			--disable-freetds --disable-java --disable-mdbtools	\
			--disable-mysql --disable-odbc --disable-oracle		\
			--disable-perl --disable-php --disable-postgresql	\
			--disable-python --disable-ruby --disable-sqlite	\
			--disable-sap --disable-tcl --disable-nodejs

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

SUBST_CLASSES+=		user
SUBST_STAGE.user=	pre-configure
SUBST_MESSAGE.user=	Fixing default nonprivileged user
SUBST_FILES.user=	etc/sqlrelay.* src/common/defaults.h
SUBST_SED.user=		-e '/runasuser/s/nobody/${SQLR_USER}/'
SUBST_SED.user+=	-e '/runasgroup/s/nobody/${SQLR_GROUP}/'
SUBST_SED.user+=	-e '/RUNASUSER/s/nobody/${SQLR_USER}/'
SUBST_SED.user+=	-e '/RUNASGROUP/s/nobody/${SQLR_GROUP}/'

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
