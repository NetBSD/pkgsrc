# $NetBSD: Makefile,v 1.18 2005/12/01 16:41:29 rillig Exp $

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

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	COPTS=${CFLAGS:M*:Q}
BUILD_TARGET=	ppunpack
LICENSE=	no-commercial-use

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
