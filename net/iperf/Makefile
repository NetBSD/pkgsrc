# $NetBSD: Makefile,v 1.9 2004/04/12 13:36:37 seb Exp $
#

DISTNAME=	iperf-1.7.0-source
PKGNAME=	${DISTNAME:C/-source//}
CATEGORIES=	net
MASTER_SITES=	http://dast.nlanr.net/Projects/Iperf/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://dast.nlanr.net/Projects/Iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=	3.0
.endif

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		YES
CONFIGURE_DIRS=		${WRKSRC}/cfg
INSTALL_DIRS=		${WRKSRC}/src
GNU_CONFIGURE=		YES
MAKE_ENV+=		INSTALL_DIR=${PREFIX}/bin
USE_LANGUAGES=		c c++

INSTALLATION_DIRS+=	share/doc/html/${PKGBASE}

PTHREAD_OPTS=	native optional
.include "../../mk/pthread.buildlink3.mk"

post-install:
	for f in ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/html/${PKGBASE}; \
	done

.include "../../mk/bsd.pkg.mk"
