# $NetBSD: Makefile,v 1.11 2004/04/10 16:37:22 seb Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}
PKGREVISION=	1
COMMENT=	GNU Compiler Collection, v3 - C compiler

INFO_FILES=	cpp.info gcc.info gccint.info cppinternals.info

.include "../../lang/gcc3/Makefile.common"

# The "gcc" frontend knows all languages (by patch)
CONFIGURE_ARGS+=	--enable-languages=c
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

MAKE_ENV+=	ALL_GCC=${ALL_GCC:Q}
MAKE_ENV+=	ALL_GCC_C=${ALL_GCC_C:Q}
MAKE_ENV+=	ALL_GCC_CCC=${ALL_GCCXX_C:Q}

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc-*)
ALL_TARGET=	bootstrap
.endif

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

post-install:
.if ${OPSYS} == "SunOS"
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.endif
	${INSTALL_DATA_DIR} ${GCC_PREFIX}/mk
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/c.mk
	${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
