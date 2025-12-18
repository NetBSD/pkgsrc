# $NetBSD: Makefile,v 1.50 2025/12/18 15:19:40 adam Exp $

DISTNAME=	exim-html-4.99.1
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

NO_BUILD=		yes
INSTALLATION_DIRS=	share/doc/exim/html

USE_TOOLS+=	pax

do-install:
	cd ${WRKSRC}/${DISTNAME}/doc && \
	${PAX} -rw html ${DESTDIR}${PREFIX}/share/doc/exim

.include "../../mk/bsd.pkg.mk"
