# $NetBSD: Makefile,v 1.12 2005/10/07 20:29:52 markd Exp $

DISTNAME=	iperf-2.0.2
CATEGORIES=	net
MASTER_SITES=	http://dast.nlanr.net/Projects/Iperf2.0/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://dast.nlanr.net/Projects/Iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=	3.0
.endif

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
#CONFIGURE_DIRS=		${WRKSRC}/cfg
#INSTALL_DIRS=		${WRKSRC}/src
#MAKE_ENV+=		INSTALL_DIR=${PREFIX}/bin

INSTALLATION_DIRS+=	share/doc/html/${PKGBASE}

PTHREAD_OPTS=	native optional
.include "../../mk/pthread.buildlink3.mk"

post-install:
	for f in ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/html/${PKGBASE}; \
	done

.include "../../mk/bsd.pkg.mk"
