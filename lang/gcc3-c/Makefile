# $NetBSD: Makefile,v 1.7 2003/08/11 14:16:00 drochner Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}
COMMENT=		GNU Compiler Collection, version 3, C compiler

INFO_FILES=	cpp.info gcc.info gccint.info cppinternals.info

.include "Makefile.common"

# the "gcc" frontend knows all languages (by patch)
CONFIGURE_ARGS+=	--enable-languages=c
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

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
