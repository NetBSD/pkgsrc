# $NetBSD: Makefile,v 1.39 2012/09/11 23:04:19 asau Exp $

DISTNAME=	fftw-3.3.2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
.endif

.include "../../mk/bsd.pkg.mk"
