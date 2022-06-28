# $NetBSD: Makefile,v 1.63 2022/06/28 11:30:59 wiz Exp $

DISTNAME=	iozone3_493
PKGNAME=	${DISTNAME:S/3_/-3./}
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iozone.org/
COMMENT=	Benchmark for file read and write speed
# No derivative works
LICENSE=	iozone-license

NOT_FOR_PLATFORM=	Interix-*-* # has only 32-bit off_t

WRKSRC=			${WRKDIR}/${DISTNAME}/src/current
MAKE_FILE=		makefile
USE_TOOLS+=		gmake perl tee
MAKE_JOBS_SAFE=		no

CPPFLAGS.SunOS+=	-Dsolaris

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_TARGET=		netbsd
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
BUILD_TARGET=		netbsd-AMD64
.elif !empty(OPSYS:M*BSD) || ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly"
BUILD_TARGET=		${LOWER_OPSYS}
.elif (${OPSYS} == "SunOS")
BUILD_TARGET=		Solaris
.elif (${OPSYS} == "Darwin")
BUILD_TARGET=		macosx
.elif (${OPSYS} == "IRIX")
BUILD_TARGET=		${OPSYS}${ABI:M64}
.elif (${OPSYS} == "BSDOS")
BUILD_TARGET=		bsdi
.elif (${OPSYS} == "AIX")
BUILD_TARGET=		${OPSYS}
.else
# XXX: generic should work, but specific target would be better
BUILD_TARGET=		generic
.endif

REPLACE_PERL=		iozone_visualizer.pl report.pl

EGDIR=			share/examples/IOzone
DOCDIR=			share/doc/IOzone
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR} ${DOCDIR}

#.include "options.mk"

IOZONE_TEST_ARGS=		-Ea
.if !empty(PKG_OPTIONS:Mthreads)
IOZONE_TEST_ARGS+=		-T -t4
.endif

do-install:
.for bb in fileop iozone pit_server
	${INSTALL_PROGRAM} ${WRKSRC}/${bb} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/iozone_visualizer.pl \
		${DESTDIR}${PREFIX}/bin/iozone_visualizer
	${INSTALL_SCRIPT} ${WRKSRC}/report.pl \
		${DESTDIR}${PREFIX}/bin/iozone_report
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for dd in IOzone_msword_98.pdf Iozone_ps.gz Run_rules.doc
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/${dd} \
		${DESTDIR}${PREFIX}/${DOCDIR}/
.endfor
.for ee in Generate_Graphs Gnuplot.txt client_list gengnuplot.sh \
	gnu3d.dem gnuplot.dem gnuplotps.dem read_telemetry write_telemetry
	${INSTALL_DATA} ${WRKSRC}/${ee} \
		${DESTDIR}${PREFIX}/${EGDIR}/
.endfor

benchmark:
	cd ${WRKSRC} && ./iozone ${IOZONE_TEST_ARGS} | ${TEE} iozone.out

results:
	${MKDIR} /tmp/benches/`domainname`
	${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
