# $NetBSD: language.mk,v 1.7 2004/02/21 08:38:45 seb Exp $

BUILDLINK_DEPENDS.gcc3c+=	gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3c+=	full

.include "../gcc3-c/Makefile.common"

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${RM} -f ${WRKSRC}/libiberty ${WRKSRC}/gcc/xgcc
	${LN} -s ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -s ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

.include "../gcc3-c/buildlink3.mk"
