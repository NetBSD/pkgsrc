# $NetBSD: Makefile,v 1.3 2001/02/16 13:15:35 wiz Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Decompresses Amiga PowerPacker files

WRKSRC=		${WRKDIR}/PPUnpack
MAKE_FLAGS=	CC="${CC}" COPTS="${CFLAGS}"
ALL_TARGET=	ppunpack
LICENSE=	no-commercial-use

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
