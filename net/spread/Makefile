# $NetBSD: Makefile,v 1.10 2003/09/14 18:13:50 recht Exp $
#

DISTNAME=	spread-src-3.17.1
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

USE_PERL5=	build
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/spread
MAKE_FLAGS=	LD="${CC}"

SPREAD_USER=	spread
SPREAD_GROUP=	spread

FILES_SUBST+=	SPREAD_USER=${SPREAD_USER}
FILES_SUBST+=	SPREAD_GROUP=${SPREAD_GROUP}
FILES_SUBST+=	RUNTIME_DIR=${RUNTIME_DIR}

BUILD_DEFS+=	SPREAD_USER SPREAD_GROUP

INCLUDEDIR=	${PREFIX}/include/spread
DOCSDIR=	${PREFIX}/share/doc/spread
EXAMPLEDIR=	${PREFIX}/share/examples/spread
RUNTIME_DIR=	/var/run/spread

RCD_SCRIPTS=	spread
PKG_GROUPS=	${SPREAD_USER}
PKG_USERS=	${SPREAD_USER}:${SPREAD_GROUP}
CONF_FILES=	${EXAMPLEDIR}/spread.access_ip.sample ${PKG_SYSCONFBASE}/spread.access_ip
CONF_FILES+=	${EXAMPLEDIR}/spread.conf.sample ${PKG_SYSCONFBASE}/spread.conf

OWN_DIRS_PERMS=	${RUNTIME_DIR} ${SPREAD_USER} ${SPREAD_GROUP} 0750

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${EXAMPLEDIR}/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${EXAMPLEDIR}/spread.access_ip.sample
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}/Readme.txt
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/Short_Buffer_Handling.txt ${DOCSDIR}/Short_Buffer_Handling.txt

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
