# $NetBSD: Makefile,v 1.15 2003/10/26 14:54:54 mrauch Exp $

DISTNAME=		benchfft-2.0
CATEGORIES=		benchmarks math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/benchfft/ \
			ftp://ftp.fftw.org/pub/fftw/old/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} fftw-2.0.1${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/benchfft/
COMMENT=		Benchmark your machine with a number of FFT algorithims

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_FORTRAN=		yes
USE_LIBTOOL=		yes

LTCONFIG_OVERRIDE=	${WRKDIR}/fftw-2.0.1/ltconfig
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/fftw-2.0.1/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub ${WRKDIR}/fftw-2.0.1/config.sub

pre-configure:
	CONFIGURE_DIRS=${WRKDIR}/fftw-2.0.1 ${MAKE} ${MAKEFLAGS} do-configure
	BUILD_DIRS=${WRKDIR}/fftw-2.0.1 ${MAKE} ${MAKEFLAGS} do-build

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
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/submit.txt /tmp/benches/`domainname`/fft.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
