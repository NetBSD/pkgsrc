# $NetBSD: language.mk,v 1.1 2004/02/01 14:05:47 jlam Exp $

GCC_REQD+=	${GCC_VERSION}

.include "../../lang/gcc3-c/Makefile.common"

BUILDLINK_DEPMETHOD.gcc3c+=	full

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
