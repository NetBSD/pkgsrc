# $NetBSD: Makefile,v 1.7 2000/11/07 20:28:23 skrll Exp $

DISTNAME=		benchfft-2.0
CATEGORIES=		benchmarks math
MASTER_SITES=		ftp://theory.lcs.mit.edu/pub/fftw/benchfft/ ftp://theory.lcs.mit.edu/pub/fftw/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} fftw-2.0.1${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://theory.lcs.mit.edu/~benchfft/download.html

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_FORTRAN=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

do-configure:
	(cd ${WRKDIR}/fftw-2.0.1 && ./configure)

do-build:
	(cd ${WRKDIR}/fftw-2.0.1 && ${GMAKE})
	(cd ${WRKSRC} && ./configure)
	(cd ${WRKSRC} && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bench ${PREFIX}/bin/bench-fft
	${INSTALL_SCRIPT} ${WRKSRC}/submit-script ${PREFIX}/bin/run-fftbench

.include "../../mk/bsd.prefs.mk"

benchmark:
.if defined(BATCH)
	@${ECHO} "*** This benchmark should be run in non-batch mode"
	@${SED} -e 's|bench-fft|./bench|g' <${WRKSRC}/submit-script> ${WRKSRC}/run_bench
	@${CHMOD} 755 ${WRKSRC}/run_bench
	@${SED} -e 's|@machine@|'`uname -m`'|'				\
	${FILESDIR}/setup.answers | (cd ${WRKSRC} ; ./run_bench)
.else
	@${SED} -e 's|bench-fft|./bench|g' <${WRKSRC}/submit-script> ${WRKSRC}/run_bench
	@${CHMOD} 755 ${WRKSRC}/run_bench
	@(cd ${WRKSRC} ; ./run_bench)
	@${ECHO} ${PKGNAME} results:
	${CAT} submit.txt
.endif

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/submit.txt /tmp/benches/`domainname`/fft.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
