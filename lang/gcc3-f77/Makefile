# $NetBSD: Makefile,v 1.16 2005/12/05 20:50:25 rillig Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-f77-${GCC_VERSION}
PKGREVISION=	1
COMMENT=	GNU Compiler Collection, v3 - F77 compiler

INFO_FILES=	g77.info

INSTLIBS=	libf2c/libg2c.la

.include "../../lang/gcc3/language.mk"

USE_TOOLS+=		chmod
MAKE_ENV+=		ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD:Q}
CONFIGURE_ARGS+=	--enable-languages="f77"

ONLY_FOR_COMPILER=	gcc

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} f77
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} g77
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libf2c

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-install:
	${INSTALL_PROGRAM_DIR} ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/f771 ${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		f77.install-common f77.install-info f77.install-man
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libf2c

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/f77.mk
#	${LN} -f ${GCC_PREFIX}/bin/g77 ${GCC_PREFIX}/bin/f77

.include "../../mk/bsd.pkg.mk"
