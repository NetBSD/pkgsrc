# $NetBSD: Makefile,v 1.102 2026/04/21 04:53:47 adam Exp $

DISTNAME=	redis-8.6.2
CATEGORIES=	databases
MASTER_SITES=	http://download.redis.io/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redis.io/
COMMENT=	Persistent key-value database with built-in net interface
LICENSE=	server-side-public-license OR gnu-agpl-v3 # OR redis-source-available-license-2.0

TEST_DEPENDS+=	tcl>=8.5:../../lang/tcl

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
# Don't let LTO kick in as it is not supported on all platforms.
MAKE_ENV+=		OPTIMIZATION=${DBG:U-O2:Q}

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

RCD_SCRIPTS+=		redis
RCD_SCRIPT_SRC.redis=	${FILESDIR}/redis.sh

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests

BUILD_DEFS+=		VARBASE REDIS_USER REDIS_GROUP REDIS_DATADIR
BUILD_DEFS+=		REDIS_LOGDIR REDIS_PIDDIR PKG_SYSCONFDIR

REDIS_USER?=		redis
REDIS_GROUP?=		redis
REDIS_DATADIR?=		${VARBASE}/db/redis
REDIS_LOGDIR?=		${VARBASE}/log/redis
REDIS_PIDDIR?=		${VARBASE}/run

OWN_DIRS_PERMS+=	${REDIS_DATADIR} ${REDIS_USER} ${REDIS_GROUP} 0770
OWN_DIRS_PERMS+=	${REDIS_LOGDIR} ${REDIS_USER} ${REDIS_GROUP} 0770

CONF_FILES_PERMS+=	${EGDIR}/redis.conf.example ${PKG_SYSCONFDIR}/redis.conf \
			${REAL_ROOT_USER} ${REDIS_GROUP} 0640

PKG_GROUPS+=			${REDIS_GROUP}
PKG_USERS+=			${REDIS_USER}:${REDIS_GROUP}
PKG_GECOS.${REDIS_USER}=	Redis daemon user
PKG_HOME.${REDIS_USER}=		${REDIS_DBDIR}

FILES_SUBST+=		REDIS_USER=${REDIS_USER}
FILES_SUBST+=		REDIS_GROUP=${REDIS_GROUP}
FILES_SUBST+=		REDIS_DATADIR=${REDIS_DATADIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=		redis.conf
SUBST_VARS.fix-paths=		REDIS_DATADIR REDIS_LOGDIR REDIS_PIDDIR

CHECK_PORTABILITY_SKIP+=	deps/jemalloc/configure

post-extract:
	${CHMOD} -R g-w ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/redis.conf ${DESTDIR}${EGDIR}/redis.conf.example

do-test:
	cd ${WRKSRC} && ${SH} runtest

.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
