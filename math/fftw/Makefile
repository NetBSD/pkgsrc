# $NetBSD: Makefile,v 1.7 2003/04/29 22:48:45 jtb Exp $

PKGNAME=		fftw-3.0
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

.if (${MACHINE_ARCH} == "i386")
DISTNAME=		fftw-3.0
.else
DISTNAME=		fftw-3.0-fma
.endif

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
TEXINFO_OVERRIDE=	yes

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
