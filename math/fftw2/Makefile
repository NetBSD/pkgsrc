# $NetBSD: Makefile,v 1.12 2005/12/05 20:50:36 rillig Exp $

DISTNAME=		fftw-2.1.5
PKGNAME=		fftw2-2.1.5
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif
USE_LANGUAGES=		fortran
USE_TOOLS+=		gmake
USE_MAKEINFO=		yes
INFO_FILES=		fftw.info

.include "../../mk/bsd.pkg.mk"
