# $NetBSD: Makefile,v 1.26 2017/01/19 18:52:17 agc Exp $

DISTNAME=	fftw-2.1.5
PKGNAME=	fftw2-2.1.5
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/
MASTER_SITES+=	http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--enable-shared
USE_LANGUAGES=		c fortran77
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

.include "../../mk/bsd.pkg.mk"
