# $NetBSD: Makefile,v 1.41 2010/12/30 07:41:27 obache Exp $

DISTNAME=	iozone3_308
PKGNAME=	iozone-3.308
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iozone.org/
COMMENT=	Benchmark for file read and write speed
# No derivative works
LICENSE=	iozone-license

NOT_FOR_PLATFORM=	Interix-*-* # has only 32-bit off_t

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src/current
MAKE_FILE=		makefile
USE_TOOLS+=		tee

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly"
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

IOZONE_TEST_ARGS=		-Ea
.if !empty(PKG_OPTIONS:Mthreads)
IOZONE_TEST_ARGS+=		-T -t4
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/Iozone_ps.gz \
		${DESTDIR}${PREFIX}/share/doc/IOzone

benchmark:
	cd ${WRKSRC}; ./iozone ${IOZONE_TEST_ARGS} | ${TEE} iozone.out

results:
	${MKDIR} /tmp/benches/`domainname`
	${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
