# $NetBSD: Makefile,v 1.1.1.1 2002/10/15 12:39:12 kei Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.gryphel.com/c/minivmac/
COMMENT=	miniature Macintosh emulator

WRKSRC=		${WRKDIR}/minivmac

USE_X11BASE=	YES

SCRIPTS_ENV+=	CC="${CC}"

DOCDIR=		${PREFIX}/share/doc/html/minivmac

do-build:
		cd ${WRKSRC}/tool/bash; \
		${SETENV} ${SCRIPTS_ENV} ${SHELL} build

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${PREFIX}/bin; \
		${INSTALL_DATA_DIR} ${DOCDIR}; \
		${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
