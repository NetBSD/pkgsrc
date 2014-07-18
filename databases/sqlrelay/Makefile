# $NetBSD: Makefile,v 1.39 2014/07/18 18:16:30 fhajny Exp $

COMMENT=		Database connection pooling middleware and API

.include "../../databases/sqlrelay/Makefile.common"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-db2 --disable-erlang --disable-firebird	\
			--disable-freetds --disable-java --disable-mdbtools	\
			--disable-mysql --disable-odbc --disable-oracle		\
			--disable-perl --disable-php --disable-postgresql	\
			--disable-python --disable-ruby --disable-sqlite	\
			--disable-sybase --disable-tcl

PKG_SYSCONFSUBDIR=	sqlrelay
EGDIR=			${PREFIX}/share/examples/sqlrelay
INSTALL_MAKE_FLAGS+=	EXAMPLEDIR=${DESTDIR}${EGDIR}

CONF_FILES+=		${EGDIR}/sqlrelay.conf ${PKG_SYSCONFDIR}/sqlrelay.conf
CONF_FILES+=		${EGDIR}/sqlrelay.dtd ${PKG_SYSCONFDIR}/sqlrelay.dtd
CONF_FILES+=		${EGDIR}/sqlrelay ${PKG_SYSCONFDIR}/sqlrelay

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

SUBST_CLASSES+=		user
SUBST_STAGE.user=	pre-configure
SUBST_MESSAGE.user=	Fixing default nonprivileged user
SUBST_FILES.user=	etc/sqlrelay.* src/common/defaults.h
SUBST_SED.user=		-e '/runasuser/s/nobody/${SQLR_USER}/'
SUBST_SED.user+=	-e '/runasgroup/s/nobody/${SQLR_GROUP}/'
SUBST_SED.user+=	-e '/RUNASUSER/s/nobody/${SQLR_USER}/'
SUBST_SED.user+=	-e '/RUNASGROUP/s/nobody/${SQLR_GROUP}/'

FILES_SUBST+=		SQLR_USER=${SQLR_USER}
FILES_SUBST+=		SQLR_GROUP=${SQLR_GROUP}
FILES_SUBST+=		SQLR_DATA=${SQLR_DATA}

RCD_SCRIPTS+=				sqlrelay sqlrcachemanager
RCD_SCRIPT_SRC.sqlrelay=		${WRKSRC}/init/rc.sqlrelay
RCD_SCRIPT_SRC.sqlrcachemanager=	${WRKSRC}/init/rc.sqlrcachemanager

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-error=unused-private-field -Wno-error=mismatched-tags
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/init/sqlrelay ${DESTDIR}${EGDIR}/sqlrelay

.include "../../mk/bsd.pkg.mk"
