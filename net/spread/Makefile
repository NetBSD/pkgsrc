# $NetBSD: Makefile,v 1.27 2013/07/12 10:45:00 jperkin Exp $
#

DISTNAME=	spread-src-3.17.3
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	perl
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--includedir=${PREFIX:Q}/include/spread
MAKE_FLAGS+=	LD=${CC:Q}

PKG_GROUPS_VARS+=	SPREAD_GROUP
PKG_USERS_VARS+=	SPREAD_USER

SPREAD_USER=	spread
SPREAD_GROUP=	spread

FILES_SUBST+=	SPREAD_USER=${SPREAD_USER:Q}
FILES_SUBST+=	SPREAD_GROUP=${SPREAD_GROUP:Q}
FILES_SUBST+=	RUNTIME_DIR=${RUNTIME_DIR:Q}

INCLUDEDIR=	${PREFIX}/include/spread
DOCSDIR=	${PREFIX}/share/doc/spread
EXAMPLEDIR=	${PREFIX}/share/examples/spread
RUNTIME_DIR=	${VARBASE}/run/spread

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
