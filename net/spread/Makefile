# $NetBSD: Makefile,v 1.29 2013/11/01 13:26:53 jperkin Exp $
#

DISTNAME=	spread-src-3.17.3
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	perl
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--includedir=${PREFIX:Q}/include/spread
CONFIGURE_ARGS+=	--with-pid-dir=${RUNTIME_DIR:Q}
MAKE_FLAGS+=	LD=${CC:Q}

BUILD_DEFS+=	SPREAD_DIR

PKG_GROUPS_VARS+=	SPREAD_GROUP
PKG_USERS_VARS+=	SPREAD_USER

SPREAD_USER=	spread
SPREAD_GROUP=	spread
SPREAD_DIR?=	${VARBASE}/run/spread

FILES_SUBST+=	SPREAD_USER=${SPREAD_USER:Q}
FILES_SUBST+=	SPREAD_GROUP=${SPREAD_GROUP:Q}
FILES_SUBST+=	RUNTIME_DIR=${RUNTIME_DIR:Q}

SUBST_CLASSES+=		spread
SUBST_STAGE.spread=	pre-configure
SUBST_MESSAGE.spread=	Fix default config
SUBST_FILES.spread=	sample.spread.conf spread_params.h
SUBST_VARS.spread=	SPREAD_USER SPREAD_GROUP RUNTIME_DIR

DOCSDIR=	${PREFIX}/share/doc/spread
EXAMPLEDIR=	${PREFIX}/share/examples/spread
RUNTIME_DIR=	${SPREAD_DIR}

RCD_SCRIPTS=	spread
PKG_GROUPS=	${SPREAD_USER}
PKG_USERS=	${SPREAD_USER}:${SPREAD_GROUP}
CONF_FILES=	${EXAMPLEDIR}/spread.access_ip.sample ${PKG_SYSCONFDIR}/spread.access_ip
CONF_FILES+=	${EXAMPLEDIR}/spread.conf.sample ${PKG_SYSCONFDIR}/spread.conf

OWN_DIRS_PERMS=	${RUNTIME_DIR} ${SPREAD_USER} ${SPREAD_GROUP} 0750

INSTALLATION_DIRS=	${DOCSDIR} ${EXAMPLEDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${DESTDIR}${EXAMPLEDIR}/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${DESTDIR}${EXAMPLEDIR}/spread.access_ip.sample
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${DOCSDIR}/Readme.txt
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/Short_Buffer_Handling.txt ${DESTDIR}${DOCSDIR}/Short_Buffer_Handling.txt

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
