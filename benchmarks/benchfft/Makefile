# $NetBSD: Makefile,v 1.2 1998/12/03 01:27:04 hubertf Exp $

DISTNAME=		benchfft-2.0
CATEGORIES=		benchmarks math
MASTER_SITES=		ftp://theory.lcs.mit.edu/pub/fftw/benchfft/ ftp://theory.lcs.mit.edu/pub/fftw/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} fftw-2.0.1${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://theory.lcs.mit.edu/~benchfft/download.html

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

do-configure:
	(cd ${WRKDIR}/fftw-2.0.1 && ./configure)

do-build:
	(cd ${WRKDIR}/fftw-2.0.1 && gmake)
	(cd ${WRKSRC} && ./configure)
	(cd ${WRKSRC} && gmake)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bench ${PREFIX}/bin/bench-fft
	${INSTALL_SCRIPT} ${WRKSRC}/submit-script ${PREFIX}/bin/run-fftbench

.include "../../mk/bsd.prefs.mk"

benchmark:
.if defined(BATCH)
	@${ECHO} "*** This benchmark may only be run in non-batch mode" ; \
	exit 1
.else
	@${WRKSRC}/submit-script
	@${ECHO} ${PKGNAME} results:
	${CAT} submit.txt
.endif

.include "../../mk/bsd.pkg.mk"
