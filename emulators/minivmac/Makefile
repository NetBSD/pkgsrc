# $NetBSD: Makefile,v 1.10 2004/05/23 20:58:41 danw Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.gryphel.com/c/minivmac/
COMMENT=	Miniature Macintosh emulator

WRKSRC=		${WRKDIR}/minivmac
USE_X11=	YES
USE_BUILDLINK3=	YES

SCRIPTS_ENV+=	CC="${CC}"

DOCDIR=		${PREFIX}/share/doc/html/minivmac

do-build:
	cd ${WRKSRC}/tool/bash; ${SETENV} ${SCRIPTS_ENV} ${SH} build

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
