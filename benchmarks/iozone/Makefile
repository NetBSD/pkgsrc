# $NetBSD: Makefile,v 1.31 2005/12/05 20:49:51 rillig Exp $

DISTNAME=	iozone3_248
PKGNAME=	iozone-3.248
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
EXTRACT_SUFX=	.tar

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.iozone.org/
COMMENT=	Benchmark for file read and write speed

RESTRICTED=	"Publication of derivative works not allowed"

NOT_FOR_PLATFORM=	Interix-*-* # has only 32-bit off_t

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src/current
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Linux"
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

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/Iozone_ps.gz \
		${PREFIX}/share/doc/IOzone

benchmark:
	@(cd ${WRKSRC}; ./iozone -Ea | tee iozone.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
