# $NetBSD: Makefile,v 1.7 2024/05/14 16:07:26 gdt Exp $

DISTNAME=	iperf-2.1.9
CATEGORIES=	net benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iperf2/}

MAINTAINER=	gdt@NetBSD.org
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
