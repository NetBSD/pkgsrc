# $NetBSD: language.mk,v 1.5 2004/02/13 15:13:01 jlam Exp $

BUILDLINK_DEPENDS.gcc3c+=	gcc3${GCC3_PKGMODIF}-c>=${GCC_VERSION}
BUILDLINK_DEPMETHOD.gcc3c+=	full

.include "../gcc3-c/Makefile.common"

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

.include "../gcc3-c/buildlink3.mk"
