# $NetBSD: Makefile,v 1.9 2005/01/12 15:32:01 jlam Exp $

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
CONFIGURE_ARGS=		--enable-shared
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif
USE_BUILDLINK3=		yes
USE_LANGUAGES=		fortran
USE_GNU_TOOLS+=		make
USE_MAKEINFO=		yes
INFO_FILES=		fftw.info

.include "../../mk/bsd.pkg.mk"
