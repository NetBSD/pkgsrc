# $NetBSD: Makefile,v 1.21 2014/11/28 10:30:52 bsiegert Exp $

DISTNAME=	iperf-2.0.5
PKGREVISION=	1
CATEGORIES=	net benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iperf.sourceforge.net/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

PATCHFILES=	nomaxcpu.patch
PATCH_SITES=	http://sourceforge.net/p/iperf/patches/28/attachment/
PATCH_DIST_STRIP=-p1

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=	3.0
.endif

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

LIBS.SunOS+=		-lrt

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

PTHREAD_OPTS+=		native optional
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/*.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
