# $NetBSD: Makefile,v 1.3 2006/10/02 21:49:55 rillig Exp $
#

DISTNAME=	mdf2iso-0.2.2-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/mdf2iso/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mdf2iso.berlios.de/
COMMENT=	Utility to convert Alcohol 120% images to ISO-9660 format

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && cc ${CFLAGS} src/mdf2iso.c -o mdf2iso

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdf2iso ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
