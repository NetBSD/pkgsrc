# $NetBSD: Makefile,v 1.4 2003/05/05 17:45:35 grant Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
WRKSRC=		${WRKDIR}/minivmac
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.gryphel.com/c/minivmac/
COMMENT=	miniature Macintosh emulator

USE_X11BASE=	YES

SCRIPTS_ENV+=	CC="${CC}"

DOCDIR=		${PREFIX}/share/doc/html/minivmac

do-build:
	cd ${WRKSRC}/tool/bash &&
		${SETENV} ${SCRIPTS_ENV} ${SH} build

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
