# $NetBSD: Makefile,v 1.15 2004/12/03 15:14:51 wiz Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/PPUnpack
USE_BUILDLINK3=	yes

MAKE_FLAGS=	CC="${CC}" COPTS="${CFLAGS}"
BUILD_TARGET=	ppunpack
LICENSE=	no-commercial-use

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
