# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:02 joerg Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://minivmac.sourceforge.net/
COMMENT=	Miniature Macintosh emulator

WRKSRC=		${WRKDIR}/minivmac

SCRIPTS_ENV+=	CC="${CC}"

DOCDIR=		${PREFIX}/share/doc/html/minivmac

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-build:
	cd ${WRKSRC}/tool/bash; ${SETENV} ${SCRIPTS_ENV} ${SH} build

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
