# $NetBSD: Makefile,v 1.8 2012/10/08 13:45:44 asau Exp $

DISTNAME=	poster-20060221
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/printing/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://printing.kde.org/downloads/
COMMENT=	Resize a ps image to print on larger media and/or multiple sheets

BUILD_TARGET=	poster

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poster ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/poster.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
