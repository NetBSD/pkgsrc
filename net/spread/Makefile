# $NetBSD: Makefile,v 1.5 2003/05/05 19:05:17 jmmv Exp $
#

DISTNAME=	${BASENAME}-src-${VER}
PKGNAME=	${BASENAME}-${VER}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	net
MASTER_SITES=

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	${ECHO} '======================================================='; \
	${ECHO} 'Distfile has to be manually fetched from'; \
	${ECHO} '   http://www.cnds.jhu.edu/download/download_spread.cgi'; \
	${ECHO} '======================================================='

BASENAME=	spread
VER=		3.17.0
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

BUILD_DEPENDS+=        perl-[0-9]*:../../lang/perl5:build
LDFLAGS	+=	-lutil

SPREAD_USER=	spread
SPREAD_GROUP=	spread

FILES_SUBST+=	SPREAD_USER=${SPREAD_USER}
FILES_SUBST+=	SPREAD_GROUP=${SPREAD_GROUP}

BUILD_DEFS+=	SPREAD_USER SPREAD_GROUP

INCLUDEDIR=	${PREFIX}/include/spread
DOCSDIR=	${PREFIX}/share/doc/spread
EXAMPLEDIR=	${PREFIX}/share/examples/spread
RUNDIR=		/var/run/spread

RCD_SCRIPTS=	spread
PKG_GROUPS=	${SPREAD_USER}
PKG_USERS=	${SPREAD_USER}:${SPREAD_GROUP}
CONF_FILES=	${EXAMPLEDIR}/spread.access_ip.sample ${PKG_SYSCONFBASE}/spread.access_ip
CONF_FILES+=	${EXAMPLEDIR}/spread.conf.sample ${PKG_SYSCONFBASE}/spread.conf

pre-install:
	${INSTALL_DATA_DIR} ${INCLUDEDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${EXAMPLEDIR}/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${EXAMPLEDIR}/spread.access_ip.sample
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}/Readme.txt
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/Short_Buffer_Handling.txt ${DOCSDIR}/Short_Buffer_Handling.txt
	${INSTALL} -d -o ${SPREAD_USER} -g ${SPREAD_GROUP} -m 0750 ${RUNDIR}

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
