# $NetBSD: Makefile,v 1.7 2004/02/01 14:05:47 jlam Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-f77-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - F77 compiler

INFO_FILES=	g77.info

.include "../gcc3-c/language.mk"

CONFIGURE_ARGS+=	--enable-languages="f77"

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} f77
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} g77
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libf2c

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/f771 ${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		f77.install-common f77.install-info f77.install-man
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libf2c

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/f77.mk
#	${LN} -f ${GCC_PREFIX}/bin/g77 ${GCC_PREFIX}/bin/f77

.include "../../mk/bsd.pkg.mk"
