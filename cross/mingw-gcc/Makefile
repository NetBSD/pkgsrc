# $NetBSD: Makefile,v 1.3 2012/10/03 00:10:30 asau Exp $
#

DISTNAME=		mingw-gcc-${DIST_VERSION}
PKGNAME=		${DISTNAME:S/-${DIST_VERSION}/-${GCC_VERSION}/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}
DISTFILES=		gcc-core-${DIST_VERSION}-src.tar.gz \
			gcc-g++-${DIST_VERSION}-src.tar.gz \
			gcc-objc-${DIST_VERSION}-src.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GNU C Compiler for win32 cross-development

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes

WRKSRC=			${WRKDIR}/gcc-${DIST_VERSION}

GCC_VERSION=		3.4.5
DIST_VERSION=		${GCC_VERSION}-20060117-2

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		all-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		all-target-libstdc++-v3

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${GMAKE} \
		${MAKE_FLAGS} install-target-libobjc
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${GMAKE} \
		${MAKE_FLAGS} install-target-libstdc++-v3
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${CROSSBASE}/${MINGW_TARGET}/bin
	cd ${DESTDIR}${CROSSBASE}/bin && ${LN} -fs ${MINGW_TARGET}-gcc ${MINGW_TARGET}-cc
	cd ${DESTDIR}${CROSSBASE} && ${LN} -fs bin/${MINGW_TARGET}-cpp ${MINGW_TARGET}/bin/cpp
	cd ${DESTDIR}${CROSSBASE} && ${LN} -fs bin/${MINGW_TARGET}-cc  ${MINGW_TARGET}/bin/cc
	cd ${DESTDIR}${CROSSBASE} && ${LN} -fs bin/${MINGW_TARGET}-gcc ${MINGW_TARGET}/bin/gcc
	cd ${DESTDIR}${CROSSBASE} && ${LN} -fs bin/${MINGW_TARGET}-c++ ${MINGW_TARGET}/bin/c++
	cd ${DESTDIR}${CROSSBASE} && ${LN} -fs bin/${MINGW_TARGET}-g++ ${MINGW_TARGET}/bin/g++

.include "../../cross/mingw/Makefile.common"
.include "../../cross/mingw-binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
