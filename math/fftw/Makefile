# $NetBSD: Makefile,v 1.12 2003/08/09 11:11:30 seb Exp $

.if (${MACHINE_ARCH} == "powerpc")
DISTNAME=		fftw-3.0.1-fma
.else
DISTNAME=		fftw-3.0.1
.endif
PKGNAME=		fftw-3.0.1
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fftw.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared
USE_FORTRAN=		yes
USE_GMAKE=		yes
INFO_FILES=		fftw3.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
