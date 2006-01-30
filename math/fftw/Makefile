# $NetBSD: Makefile,v 1.21 2006/01/30 09:25:09 adam Exp $

DISTNAME=	fftw-3.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		http://www.fftw.org/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		fftw3.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
