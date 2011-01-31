# $NetBSD: Makefile,v 1.18 2011/01/31 08:42:09 adam Exp $

DISTNAME=	iperf-2.0.5
CATEGORIES=	net benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iperf.sourceforge.net/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=	3.0
.endif

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

PTHREAD_OPTS+=		native optional
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/*.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
