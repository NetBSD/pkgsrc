# $NetBSD: Makefile,v 1.44 2021/04/21 08:11:16 wiz Exp $

DISTNAME=	exim-html-4.94
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
