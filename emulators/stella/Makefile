# $NetBSD: Makefile,v 1.13 2003/09/17 19:40:18 grant Exp $

DISTNAME=	stella-1.1-src
PKGNAME=	stella-1.1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src/build
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/stella/1.1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://stella.atari.org/
COMMENT=	Multi-platform Atari 2600 VCS emulator

USE_X11=	yes

MAKEFILE=	makefile
ALL_TARGET=	unix-x

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

MAKE_ENV=	CXXFLAGS="${CXXFLAGS} -fno-rtti"

post-build:
	@cd ${WRKSRC}/../ui/sound && ${MAKE} oss

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/stella
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stella
	${INSTALL_PROGRAM} ${WRKSRC}/xstella ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/../ui/sound/stella-sound ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../../games/ROMS/* ${PREFIX}/share/stella
	${INSTALL_DATA} ${WRKSRC}/../../games/docs/* ${PREFIX}/share/doc/stella
	${INSTALL_DATA} ${WRKSRC}/../../docs/Stella.pdf ${PREFIX}/share/doc/stella/stella.pdf

.include "../../mk/bsd.pkg.mk"
