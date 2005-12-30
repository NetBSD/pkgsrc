# $NetBSD: Makefile,v 1.27.2.1 2005/12/30 21:24:23 salo Exp $

DISTNAME=		benchfft-2.0
PKGREVISION=	1
CATEGORIES=		benchmarks math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			ftp://ftp.fftw.org/pub/fftw/old/benchfft/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} fftw-2.0.1${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/benchfft/
COMMENT=		Benchmark your machine with a number of FFT algorithms

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		fortran
USE_LIBTOOL=		yes

LTCONFIG_OVERRIDE=	${WRKDIR}/fftw-2.0.1/ltconfig
CONFIG_GUESS_OVERRIDE=	config.guess ../fftw-*/config.guess
CONFIG_SUB_OVERRIDE=	config.sub ../fftw-*/config.sub
CONFIG_STATUS_OVERRIDE=	config.status ../fftw-*/config.status

INSTALLATION_DIRS=	bin

CONFIGURE_DIRS=		${WRKDIR}/fftw-2.0.1 ${WRKSRC}

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
