# $NetBSD: Makefile,v 1.27 2022/01/05 15:41:19 wiz Exp $

DISTNAME=	prelude-correlator-0.9.0-beta8
PKGNAME=	prelude-correlator-${DISTNAME:S/-beta/beta/:C/.*-//}
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/prelude-correlator/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.prelude-ids.com/download/releases/prelude-correlator/
COMMENT=	Intrusion event correlation engine

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=			preludecorrelator
PRELUDE_CORRELATOR_PID_DIR=	${VARBASE}/run/prelude-correlator
PRELUDE_USER?=			_prelude
PRELUDE_GROUP?=			_prelude
PRELUDE_HOME?=			${VARBASE}/db/prelude-correlator
INSTALLATION_DIRS=		sbin
OWN_DIRS=			${PKG_SYSCONFDIR}/prelude-correlator
EGDIR=				${PREFIX}/share/examples

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS correlator
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

FILES_SUBST+=		PRELUDE_CORRELATOR_PID_DIR=${PRELUDE_CORRELATOR_PID_DIR:Q}
FILES_SUBST+=		PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=		PRELUDE_GROUP=${PRELUDE_USER:Q}

SUBST_CLASSES+=		code
SUBST_STAGE.code=	pre-configure
SUBST_FILES.code=	run-prelude-correlator.c
SUBST_FILES.code+=	${WRKSRC}/*.py
SUBST_VARS.code=	PREFIX
SUBST_VARS.code+=	PRELUDE_USER
SUBST_VARS.code+=	PRELUDE_HOME

CONF_FILES+=		${EGDIR}/prelude-correlator.conf ${PKG_SYSCONFDIR}/prelude-correlator/prelude-correlator.conf
CONF_FILES+=		${EGDIR}/dshield.dat ${PRELUDE_HOME}/dshield.dat
CONF_FILES+=		${EGDIR}/spamhaus_drop.dat ${PRELUDE_HOME}/spamhaus_drop.dat

REQD_DIRS+=		${PRELUDE_HOME}
REQD_DIRS_PERMS+=	${PRELUDE_HOME} ${PRELUDE_USER} ${PRELUDE_GROUP} 0700

REPLACE_PYTHON=		PreludeCorrelator/main.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9.0beta8
EGG_NAME=		prelude_correlator-0.9.0b8

USE_PKG_RESOURCES=	yes

pre-patch:
	${CP} ${FILESDIR}/run-prelude-correlator.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-correlator run-prelude-correlator.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-correlator ${DESTDIR}${PREFIX}/sbin/run-prelude-correlator
	${INSTALL_DATA} ${WRKSRC}/prelude-correlator.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/PreludeCorrelator/plugins/dshield.dat \
	    ${WRKSRC}/PreludeCorrelator/plugins/spamhaus_drop.dat \
	    ${DESTDIR}${EGDIR}

.include "../../security/libprelude-python/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
