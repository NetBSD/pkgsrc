# $NetBSD: Makefile,v 1.73 2021/05/16 08:44:33 nia Exp $

DISTNAME=	fftw-3.3.9
PKGREVISION=	6
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/
MASTER_SITES+=	http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs
LICENSE=	gnu-gpl-v2

SUPERSEDES=	fftwf-[0-9]*
CONFLICTS+=	fftwf-[0-9]*

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		perl
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
USE_TOOLS+=		perl:test sed

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
.  if   ${d} == "build/float"
	printf '#!/bin/sh\nexec ../../configure "$$@" --enable-${d:S,build/,,} ${FFTW_FLOAT_OPTS}' \
	> ${WRKSRC:Q}/${d}/configure
.  elif ${d} == "build/double"
	printf '#!/bin/sh\nexec ../../configure "$$@" ${FFTW_DOUBLE_OPTS}' \
	> ${WRKSRC:Q}/${d}/configure
.  elif ${d} == "build/quad-precision"
	printf '#!/bin/sh\nexec ../../configure "$$@" --enable-${d:S,build/,,} --disable-mpi\n' \
	> ${WRKSRC:Q}/${d}/configure
.  else
	printf '#!/bin/sh\nexec ../../configure "$$@" --enable-${d:S,build/,,}\n' \
	> ${WRKSRC:Q}/${d}/configure
.  endif
	chmod +x ${WRKSRC:Q}/${d}/configure
.endfor

.include "../../mk/bsd.pkg.mk"
