# $NetBSD: Makefile,v 1.2 2021/03/15 17:00:06 gdt Exp $

# Upstream has newer files but no newer actual releases.
# https://sourceforge.net/p/iperf2/tickets/102/
DISTNAME=	iperf-2.0.13
CATEGORIES=	net benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iperf2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/iperf2/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

LIBS.SunOS+=		-lrt

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/*.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
