# $NetBSD: Makefile,v 1.19 2016/03/04 08:58:58 wiz Exp $

DISTNAME=	redis-3.0.7
CATEGORIES=	databases
MASTER_SITES=	http://download.redis.io/releases/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://redis.io/
COMMENT=	Persistent key-value database with built-in net interface
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_TOOLS+=		gmake pax
DIST_SUBDIR=	redis-3.0.7v2

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS+=		redis
RCD_SCRIPT_SRC.redis=	${FILESDIR}/redis.sh

DOCDIR=			share/doc/redis
DOCFILES+=		00-RELEASENOTES BUGS COPYING README
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests
CONF_FILES=		${EGDIR}/redis.conf.example ${PKG_SYSCONFDIR}/redis.conf

BUILD_DEFS+=		VARBASE REDIS_USER REDIS_GROUP REDIS_DATADIR
BUILD_DEFS+=		REDIS_LOGDIR REDIS_PIDDIR

REDIS_USER?=		redis
REDIS_GROUP?=		redis
REDIS_DATADIR?=		${VARBASE}/db/redis
REDIS_LOGDIR?=		${VARBASE}/log/redis
REDIS_PIDDIR?=		${VARBASE}/run

OWN_DIRS+=		${REDIS_DATADIR} ${REDIS_LOGDIR}
OWN_DIRS_PERMS+=	${REDIS_DATADIR} ${REDIS_USER} ${REDIS_GROUP} 0770
OWN_DIRS_PERMS+=	${REDIS_LOGDIR} ${REDIS_USER} ${REDIS_GROUP} 0770

PKG_GROUPS+=		${REDIS_GROUP}
PKG_USERS+=		${REDIS_USER}:${REDIS_GROUP}
PKG_GECOS.${REDIS_USER}= Redis daemon user
PKG_HOME.${REDIS_USER}=	${REDIS_DBDIR}

FILES_SUBST+=		REDIS_USER=${REDIS_USER}
FILES_SUBST+=		REDIS_GROUP=${REDIS_GROUP}
FILES_SUBST+=		REDIS_DATADIR=${REDIS_DATADIR}

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths= Fixing paths.
SUBST_FILES.fix-paths=	redis.conf
SUBST_VARS.fix-paths=	REDIS_DATADIR REDIS_LOGDIR REDIS_PIDDIR

CHECK_PORTABILITY_SKIP+=	deps/jemalloc/configure

post-extract:
	${CHMOD} -R g-w ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/redis.conf ${DESTDIR}${EGDIR}/redis.conf.example
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${DOCDIR}/${file}
.endfor
	cd ${WRKSRC}/utils && pax -rwpp . ${DESTDIR}${EGDIR}/utils/
	cd ${WRKSRC}/tests && pax -rwpp . ${DESTDIR}${EGDIR}/tests/

do-test:
	cd ${WRKSRC} && ${SH} runtest

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
