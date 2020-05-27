# $NetBSD: Makefile,v 1.7 2020/05/27 19:37:38 wiz Exp $
#

DISTNAME=	pgpool-II-3.6.5
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME:S/pgpool-II/pgpool2/}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pgpool.net/mediawiki/
COMMENT=	Middleware between PostgreSQL servers and a PostgreSQL database client
LICENSE=	modified-bsd

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run gmake

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		PGPOOL_USER PGPOOL_GROUP PGGROUP PGHOME VARBASE

EGDIR=			share/examples/pgpool2

PGPOOL_USER?=		pgpool
PGPOOL_GROUP?=		${PGGROUP}
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGGROUP}

PKG_GROUPS=			${PGPOOL_GROUP}
PKG_USERS=			${PGPOOL_USER}:${PGPOOL_GROUP}
PKG_GROUPS_VARS+=		PGPOOL_GROUP
PKG_USERS_VARS=			PGPOOL_USER
PKG_HOME.${PGPOOL_USER}=	${PGHOME}
PKG_SHELL.${PGPOOL_GROUP}=	${SH}

PKG_SYSCONFSUBDIR=	pgpool2
PGPOOL_LOGDIR?=		${VARBASE}/log/pgpool
PGPOOL_PIDDIR?=		${VARBASE}/run/pgpool
OWN_DIRS_PERMS+=	${PGPOOL_LOGDIR} ${PGPOOL_USER} ${PGPOOL_GROUP} 0751
OWN_DIRS_PERMS+=	${PGPOOL_PIDDIR} ${PGPOOL_USER} ${PGPOOL_GROUP} 0751

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing default paths
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/sample/pgpool.conf.sample src/include/pool.h
SUBST_VARS.path=	PGPOOL_LOGDIR PGPOOL_PIDDIR

REPLACE_BASH+=		src/tools/pgpool_setup src/tools/watchdog_setup

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILD_DIRS=		. src/sql

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/${EGDIR}

RCD_SCRIPTS+=		pgpool2
SMF_NAME=		pgpool
FILES_SUBST+=		PGPOOL_USER=${PGPOOL_USER}
FILES_SUBST+=		PGPOOL_GROUP=${PGPOOL_GROUP}

CONF_FILES+=		${EGDIR}/pcp.conf.sample ${PKG_SYSCONFDIR}/pcp.conf
CONF_FILES+=		${EGDIR}/pgpool.conf.sample ${PKG_SYSCONFDIR}/pgpool.conf
CONF_FILES+=		${EGDIR}/pool_hba.conf.sample ${PKG_SYSCONFDIR}/pool_hba.conf
CONF_FILES_PERMS+=	${EGDIR}/pool_passwd ${PKG_SYSCONFDIR}/pool_passwd \
			${PGPOOL_USER} ${PGGROUP} 0640

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/pgpool2/pool_passwd

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
