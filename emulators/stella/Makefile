# $NetBSD: Makefile,v 1.18 2004/08/13 16:12:25 dillo Exp $

STELLA_VERSION=	1.4
DISTNAME=	stella-${STELLA_VERSION}-src
PKGNAME=	stella-${STELLA_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stella/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://stella.sourceforge.net/
COMMENT=	Multi-platform Atari 2600 VCS emulator

PATCHDIR=               ${.CURDIR}/../stella/patches
DISTINFO_FILE=          ${.CURDIR}/../stella/distinfo

WRKSRC=		${WRKDIR}/stella-${STELLA_VERSION}/src/build
USE_LANGUAGES=	c c++
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	YES
USE_INSTALL=	YES
UNLIMIT_RESOURCES=datasize

MAKEFILE=	makefile
ALL_TARGET=	linux

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

MAKE_ENV=	CXXFLAGS="${CXXFLAGS} -fno-rtti"

DOCDIR=${PREFIX}/share/doc/html/stella
DATADIR=${PREFIX}/share/stella

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stella ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/../../docs/stella.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../../docs/graphics/* ${DOCDIR}/graphics
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../emucore/stella.pro ${DATADIR}

.include "../../mk/bsd.pkg.mk"
