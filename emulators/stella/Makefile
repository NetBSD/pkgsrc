# $NetBSD: Makefile,v 1.4.2.1 2002/06/23 18:45:37 jlam Exp $

DISTNAME=	stella-1.1-src
PKGNAME=	stella-1.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/stella/1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://stella.atari.org/
COMMENT=	Multi-platform Atari 2600 VCS emulator

USE_X11=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}/src/build
MAKEFILE=	makefile
ALL_TARGET=	unix-x

.if (${MACHINE_ARCH} == arm32 || ${MACHINE_ARCH} == arm)
.if (${CXXFLAGS:M-O2} == "-O2")
CXXFLAGS:=        ${CXXFLAGS:S/-O2/-O0/}
.endif
.endif

MAKE_ENV=	CXXFLAGS="${CXXFLAGS} -fno-rtti"

post-build:
	@cd ${WRKSRC}/../ui/sound && ${MAKE} oss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xstella ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/../ui/sound/stella-sound ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/stella ${PREFIX}/share/doc/stella
	${INSTALL_DATA} ${WRKSRC}/../../games/ROMS/* ${PREFIX}/share/stella/
	${INSTALL_DATA} ${WRKSRC}/../../games/docs/* ${PREFIX}/share/doc/stella/
	${INSTALL_DATA} ${WRKSRC}/../../docs/Stella.pdf ${PREFIX}/share/doc/stella/stella.pdf

.include "../../mk/bsd.pkg.mk"
