# $NetBSD: Makefile,v 1.9 2003/07/17 21:21:34 grant Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
WRKSRC=		${WRKDIR}/PPUnpack
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

USE_BUILDLINK2=	# defined

MAKE_FLAGS=	CC="${BUILDLINK_CC}" COPTS="${CFLAGS}"
ALL_TARGET=	ppunpack
LICENSE=	no-commercial-use

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
