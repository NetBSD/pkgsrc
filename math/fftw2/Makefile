# $NetBSD: Makefile,v 1.17 2008/01/19 09:16:25 wiz Exp $

DISTNAME=		fftw-2.1.5
PKGNAME=		fftw2-2.1.5
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif
USE_LANGUAGES=		c fortran
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
