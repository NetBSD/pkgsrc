# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 20:50:29 wiz Exp $

DISTNAME=		fftw-2.1.3
PKGNAME=		fftw2-2.1.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/

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
INFO_FILES=		fftw.info
TEXINFO_OVERRIDE=	YES

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
