# $NetBSD: Makefile,v 1.18 2005/02/23 04:21:33 minskim Exp $

.if (${MACHINE_ARCH} == "powerpc")
DISTNAME=		fftw-3.0.1-fma
.else
DISTNAME=		fftw-3.0.1
.endif
PKGNAME=		fftw-3.0.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	fftw.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared
USE_LANGUAGES=		fortran
USE_GNU_TOOLS+=		make
INFO_FILES=		fftw3.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
