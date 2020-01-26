# $NetBSD: Makefile,v 1.42 2020/01/26 17:31:33 rillig Exp $

DISTNAME=	exim-html-4.93
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/
MASTER_SITES+=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/
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
