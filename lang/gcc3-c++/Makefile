# $NetBSD: Makefile,v 1.16 2006/02/05 23:09:44 joerg Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}
PKGREVISION=	1
COMMENT=	GNU Compiler Collection, v3 - C++ compiler

INSTLIBS=	libstdc++-v3/libsupc++/libsupc++.la			\
		libstdc++-v3/src/libstdc++.la

.include "../../lang/gcc3/language.mk"

CONFIGURE_ARGS+=	--enable-languages="c++"

MAKE_ENV+=	ALL_GCC_CXX=${ALL_GCC_CXX:Q}
USE_PKGINSTALL=	yes

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
