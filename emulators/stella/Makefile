# $NetBSD: Makefile,v 1.1.1.1 1999/05/18 23:14:16 tv Exp $

DISTNAME=	stella-1.1-src
PKGNAME=	stella-1.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/stella/1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://stellar.atari.org/

USE_X11=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}/src/build
MAKEFILE=	makefile
ALL_TARGET=	unix-x
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
