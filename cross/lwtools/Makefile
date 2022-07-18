# $NetBSD: Makefile,v 1.1 2022/07/18 03:43:05 thorpej Exp $

DISTNAME=	lwtools-4.19
CATEGORIES=	cross
MASTER_SITES=	http://www.lwtools.ca/releases/lwtools/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.lwtools.ca/
COMMENT=	Cross-development tools for the Motorola 6809 Hitachi 6309
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	share/doc/lwtools

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual/* \
	    ${DESTDIR}${PREFIX}/share/doc/lwtools

.include "../../mk/bsd.pkg.mk"
