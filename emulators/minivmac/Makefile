# $NetBSD: Makefile,v 1.20 2018/01/07 21:46:55 rillig Exp $

DISTNAME=	minivmac-0.1.7.src
PKGNAME=	minivmac-0.1.7
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minivmac/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minivmac.sourceforge.net/
COMMENT=	Miniature Macintosh emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/minivmac
SCRIPTS_ENV+=	CC=${CC:Q}
AUTO_MKDIRS=	yes

do-build:
	cd ${WRKSRC}/tool/bash; ${SETENV} ${SCRIPTS_ENV} ${SH} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drv/minivmac ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${PREFIX}/share/doc/minivmac

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
