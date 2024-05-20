# $NetBSD: Makefile,v 1.91 2024/05/20 04:21:44 adam Exp $

DISTNAME=	redis-7.2.5
CATEGORIES=	databases
MASTER_SITES=	http://download.redis.io/releases/

# NB: upsteram has changed to a proprietary license.  Probably (absent
# discussion), this should not be updated until a license-ok version
# is in pkgsrc.  Existing forks are:
# 1. Redict https://codeberg.org/redict/redict
# 2. KeyDB, an older redis fork (in terms of features) BSD3 licensed
# version maintained by Snapchat.
# 3. PlaceholderKV (name to be changed?) by former redis contributors
# and AWS employees, BSD3 licensed.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redis.io/
COMMENT=	Persistent key-value database with built-in net interface
LICENSE=	modified-bsd

TEST_DEPENDS+=	tcl>=8.5:../../lang/tcl

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake pkg-config
# Don't let LTO kick in as it is not supported on all platforms.
MAKE_ENV+=		OPTIMIZATION=${DBG:U-O2:Q}

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

RCD_SCRIPTS+=		redis
RCD_SCRIPT_SRC.redis=	${FILESDIR}/redis.sh

DOCDIR=			share/doc/redis
DOCFILES+=		00-RELEASENOTES BUGS COPYING README.md
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests

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
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${DOCDIR}/${file}
.endfor

do-test:
	cd ${WRKSRC} && ${SH} runtest

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
