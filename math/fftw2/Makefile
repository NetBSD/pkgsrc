# $NetBSD: Makefile,v 1.3 2003/07/31 23:58:20 seb Exp $

DISTNAME=		fftw-2.1.5
PKGNAME=		fftw2-2.1.5
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif
USE_FORTRAN=		yes
USE_GMAKE=		yes
USE_NEW_TEXINFO=	yes
USE_MAKEINFO=		yes
INFO_FILES=		fftw.info

.include "../../mk/bsd.pkg.mk"
