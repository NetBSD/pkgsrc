# $NetBSD: Makefile,v 1.11 2004/02/08 04:03:15 jlam Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

WRKSRC=		${WRKDIR}/PPUnpack
USE_BUILDLINK2=	# defined

MAKE_FLAGS=	CC="${CC}" COPTS="${CFLAGS}"
ALL_TARGET=	ppunpack
LICENSE=	no-commercial-use

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
