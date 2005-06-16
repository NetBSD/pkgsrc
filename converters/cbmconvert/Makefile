# $NetBSD: Makefile,v 1.13 2005/06/16 06:57:43 jlam Exp $

DISTNAME=		cbmconvert-2.0.5
CATEGORIES=		converters archivers
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/crossplatform/converters/unix/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Converts files to and from various C64/C128/CBM formats

BUILD_TARGET=		unix
MAKE_FLAGS=		CFLAGS="${CFLAGS}"
INSTALLATION_DIRS=	bin

do-install:
.for f in cbmconvert disk2zip zip2disk
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cbmconvert
.for f in README README.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/cbmconvert/
.endfor

.include "../../mk/bsd.pkg.mk"
