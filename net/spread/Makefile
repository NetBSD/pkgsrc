# $NetBSD: Makefile,v 1.1.1.1 2003/02/18 22:11:55 mjl Exp $
#

DISTNAME=	${BASENAME}-src-${VER}
PKGNAME=	${BASENAME}-${VER}
CATEGORIES=	net
MASTER_SITES=	http://www.roughtrade.net/distfiles/
# Also available through manual download at
# http://www.cnds.jhu.edu/download/download_spread.cgi

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.spread.org/
COMMENT=	Group communication system providing a number of messaging services

BASENAME=	spread
VER=		3.17.0
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

BUILD_DEPENDS+=        perl-[0-9]*:../../lang/perl5:build
LDFLAGS	+=	-lutil

INCLUDEDIR=	${PREFIX}/include/spread
DOCSDIR=	${PREFIX}/share/doc/spread
EXAMPLEDIR=	${PREFIX}/share/examples/spread

post-install:
	${INSTALL_DATA_DIR} ${INCLUDEDIR}
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/sp.h		${INCLUDEDIR}/sp.h
	${INSTALL_DATA} ${WRKSRC}/sp_func.h	${INCLUDEDIR}/sp_func.h
	${INSTALL_DATA} ${WRKSRC}/sp_events.h	${INCLUDEDIR}/sp_events.h
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${EXAMPLEDIR}/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${EXAMPLEDIR}/spread.access_ip.sample
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}/Readme.txt
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
