# $NetBSD: Makefile,v 1.21 2007/06/08 18:30:31 wiz Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

LICENSE=	ppunpack-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/PPUnpack

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	COPTS=${CFLAGS:M*:Q}
BUILD_TARGET=	ppunpack

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
