# $NetBSD: buildaddon.mk,v 1.6 2003/12/03 11:28:55 drochner Exp $

.include "../../lang/gcc3-c/Makefile.common"

pre-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h)
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

BUILDLINK_DEPENDS.gcc3c?=	gcc3${GCC3_PKGMODIF}-c-3.3.2
BUILDLINK_PKGSRCDIR.gcc3c?=	../../lang/gcc3-c

BUILDLINK_PREFIX.gcc3c=	${LOCALBASE}

BUILDLINK_PACKAGES+=	gcc3c

BUILDLINK_FILES.gcc3c+=	${GCC_ARCHSUBDIR}/libgcc.a
BUILDLINK_FILES.gcc3c+=	${GCC_ARCHSUBDIR}/libgcc_eh.a
BUILDLINK_FILES.gcc3c+=	${GCC_SUBPREFIX}/lib/libgcc_s.*

BUILDLINK_TARGETS+=	gcc3c-buildlink

gcc3c-buildlink: _BUILDLINK_USE
