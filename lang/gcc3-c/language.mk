# $NetBSD: language.mk,v 1.3 2004/02/10 19:31:27 jlam Exp $

.include "../../lang/gcc3-c/Makefile.common"

DEPENDS+=	gcc3${GCC3_PKGMODIF}-c>=${GCC_VERSION}:../../lang/gcc3-c

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
