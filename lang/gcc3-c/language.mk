# $NetBSD: language.mk,v 1.8 2004/02/22 04:51:25 kristerw Exp $

BUILDLINK_DEPENDS.gcc3c+=	gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3c+=	full

.include "../gcc3-c/Makefile.common"

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${RM} -f ${WRKSRC}/libiberty/libiberty.a ${WRKSRC}/gcc/xgcc
	${LN} -s ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -s ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

.include "../gcc3-c/buildlink3.mk"
