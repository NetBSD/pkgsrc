# $NetBSD: Makefile,v 1.1.1.1 1999/05/23 02:01:25 tv Exp $

DISTNAME=	ppsmall-1.0
PKGNAME=	ppunpack-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.germany.aminet.org/pub/aminet/misc/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/PPUnpack
MAKE_FLAGS=	CC="${CC}" COPTS="${CFLAGS}"
ALL_TARGET=	ppunpack
LICENSE=	no-commercial-use

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
