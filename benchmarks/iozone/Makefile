# $NetBSD: Makefile,v 1.27 2004/11/10 14:13:21 adam Exp $

DISTNAME=	iozone3_226
PKGNAME=	iozone-3.226
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
EXTRACT_SUFX=	.tar

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.iozone.org/
COMMENT=	Benchmark for file read and write speed

RESTRICTED=	"Publication of derivative works not allowed"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/src/current
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "Linux"
  ALL_TARGET=		${LOWER_OPSYS}
.elif (${OPSYS} == "SunOS")
  ALL_TARGET=		Solaris
.elif (${OPSYS} == "Darwin")
  ALL_TARGET=		macosx
.elif (${OPSYS} == "IRIX")
  ALL_TARGET=		${OPSYS}${ABI:M64}
.elif (${OPSYS} == "BSDOS")
  ALL_TARGET=		bsdi
.elif (${OPSYS} == "AIX")
  ALL_TARGET=		${OPSYS}
.else
  # XXX: generic should work, but specific target would be better
  ALL_TARGET=		generic
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/docs/iozone.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/docs/Iozone_ps.gz ${PREFIX}/share/doc/IOzone

benchmark:
	@(cd ${WRKSRC}; ./iozone -Ea | tee iozone.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
