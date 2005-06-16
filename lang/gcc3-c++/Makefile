# $NetBSD: Makefile,v 1.14 2005/06/16 06:58:00 jlam Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - C++ compiler

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
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-install:
	${INSTALL_PROGRAM_DIR} ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1plus ${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		c++.install-common c++.install-man
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libstdc++-v3

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/c++.mk

.include "../../mk/bsd.pkg.mk"
