# $NetBSD: Makefile,v 1.7 2004/01/19 10:00:40 adam Exp $
#

DISTNAME=	iperf-1.7.0-source
PKGNAME=	${DISTNAME:C/-source//}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	net
MASTER_SITES=	http://dast.nlanr.net/Projects/Iperf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dast.nlanr.net/Projects/Iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool

NOT_FOR_PLATFORM=	*-*-sparc64	# internal g++ error

USE_BUILDLINK2=		YES
CONFIGURE_DIRS=		${WRKSRC}/cfg
INSTALL_DIRS=		${WRKSRC}/src
GNU_CONFIGURE=		YES
MAKE_ENV+=		INSTALL_DIR=${PREFIX}/bin
USE_GCC_SHLIB=		YES

PTHREAD_OPTS=	native optional
.include "../../mk/pthread.buildlink2.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${PREFIX}/share/doc/html/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
