# $NetBSD: Makefile,v 1.3 2001/02/16 13:59:23 wiz Exp $

DISTNAME=		cbmconvert-2.0.5
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/crossplatform/converters/unix/

MAINTAINER=		packages@netbsd.org
COMMENT=		Converts files to and from various C64/C128/CBM formats

ALL_TARGET=		unix
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
