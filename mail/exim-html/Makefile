# $NetBSD: Makefile,v 1.41 2019/12/09 18:46:01 adam Exp $

DISTNAME=	exim-html-4.93
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/
MASTER_SITES+=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

NO_BUILD=		yes
INSTALLATION_DIRS=	share/doc/exim/html

USE_TOOLS+=	pax

do-install:
	cd ${WRKSRC}/${DISTNAME}/doc && \
	${PAX} -rw html ${DESTDIR}${PREFIX}/share/doc/exim

.include "../../mk/bsd.pkg.mk"
