# $NetBSD: Makefile,v 1.24 2006/05/24 19:24:40 adam Exp $

DISTNAME=	fftw-3.1.1
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
INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
