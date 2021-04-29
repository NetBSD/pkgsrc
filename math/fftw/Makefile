# $NetBSD: Makefile,v 1.62 2021/04/29 23:30:15 thor Exp $

PKGREVISION=	4

COMMENT=	Collection of fast C routines to compute DFTs

DISTNAME=	fftw-3.3.9
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/
MASTER_SITES+=	http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
LICENSE=	gnu-gpl-v2

SUPERSEDES=	fftwf
CONFLICTS+=	fftwf-[0-9]*

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

# The standard precision is double. We always build at least
# single in addition. Others enabled by options.
FFTW_PRECISION=	double float
.include "options.mk"

# Test will only use the default build.
.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
.endif

PLIST_VARS+=		pthreads
PTHREAD_OPTS=		native
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--enable-threads
PLIST.pthreads=		yes
.endif

CONFIGURE_SCRIPT=	./configure
.for p in ${FFTW_PRECISION}
CONFIGURE_DIRS+=	build/${p}
MAKE_DIRS+=		build/${p}
.endfor

pre-configure:
.for d in ${CONFIGURE_DIRS}
	mkdir -p ${WRKSRC:Q}/${d}
.if ${d} == "build/quad-precision"
	printf '#!/bin/sh\nexec ../../configure "$$@" --enable-${d:S,build/,,} --disable-mpi\n' \
	> ${WRKSRC:Q}/${d}/configure
.else
	printf '#!/bin/sh\nexec ../../configure "$$@" --enable-${d:S,build/,,}\n' \
	> ${WRKSRC:Q}/${d}/configure
.endif
	chmod +x ${WRKSRC:Q}/${d}/configure
.endfor

.include "../../mk/bsd.pkg.mk"

