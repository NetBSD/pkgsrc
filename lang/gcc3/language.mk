# $NetBSD: language.mk,v 1.3 2004/09/10 19:53:51 jlam Exp $

BUILDLINK_DEPENDS.gcc3-c+=	gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3-c+=	full

.include "../../lang/gcc3/Makefile.common"

LIBTOOLIZE_PLIST=	yes

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${RM} -f ${WRKSRC}/libiberty/libiberty.a ${WRKSRC}/gcc/xgcc
	${LN} -s ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -s ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

.include "../../lang/gcc3-c/buildlink3.mk"
