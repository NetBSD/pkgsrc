# $NetBSD: Makefile,v 1.1.1.1 1999/05/22 18:09:12 tv Exp $

DISTNAME=		cbmconvert-2.0.5
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/crossplatform/converters/unix/

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=		http://www.cs.cmu.edu/~dsladic/vice/vice.html

ALL_TARGET=		unix

# override in Makefile
MAKE_FLAGS=		CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
.for file in cbmconvert disk2zip zip2disk
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cbmconvert
.for file in README README.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cbmconvert/
.endfor

.include "../../mk/bsd.pkg.mk"
