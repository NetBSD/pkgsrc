# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 20:52:18 xtraeme Exp $
#

DISTNAME=	mdf2iso-0.2.2-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/mdf2iso/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mdf2iso.berlios.de/
COMMENT=	Utility to convert Alcohol 120% images to ISO-9660 format

INSTALLATION_DIRS=	bin

do-build:
	${PKGSRC_COMPILER} ${CFLAGS} \
		${WRKSRC}/src/mdf2iso.c -o ${WRKSRC}/mdf2iso

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdf2iso ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
