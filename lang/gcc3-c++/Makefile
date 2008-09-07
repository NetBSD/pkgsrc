# $NetBSD: Makefile,v 1.19 2008/09/07 02:10:15 dholland Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - C++ compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTLIBS=	libstdc++-v3/libsupc++/libsupc++.la			\
		libstdc++-v3/src/libstdc++.la

.include "../../lang/gcc3/language.mk"

CONFIGURE_ARGS+=	--enable-languages="c++"

MAKE_ENV+=	ALL_GCC_CXX=${ALL_GCC_CXX:Q}

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} c++
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} g++
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libstdc++-v3

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1plus ${DESTDIR}${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		c++.install-common c++.install-man \
		DESTDIR=${DESTDIR:Q}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libstdc++-v3 \
		DESTDIR=${DESTDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${GCC_PREFIX}/mk
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${DESTDIR:Q}${GCC_PREFIX}/mk/c++.mk

.include "../../mk/bsd.pkg.mk"
