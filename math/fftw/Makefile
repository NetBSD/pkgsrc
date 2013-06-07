# $NetBSD: Makefile,v 1.44 2013/06/07 13:28:56 gdt Exp $

DISTNAME=	fftw-3.3.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared

# The next lines are fodder for a fortran option.
# Swapping the comments doesn't change the PLIST.  So what's the
# benefit of not?
USE_LANGUAGES+=		fortran77
# CONFIGURE_ARGS+=	--disable-fortran

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
.endif

PLIST_VARS+=		pthreads

PTHREAD_OPTS=		native
.include "../../mk/pthread.buildlink3.mk"
.if !empty(PTHREAD_TYPE:Mnative)
CONFIGURE_ARGS+=	--enable-threads
PLIST.pthreads=		yes
.endif

.include "../../mk/bsd.pkg.mk"
