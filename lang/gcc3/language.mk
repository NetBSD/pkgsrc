# $NetBSD: language.mk,v 1.2 2004/09/08 10:22:01 jlam Exp $

BUILDLINK_DEPENDS.gcc3-c+=	gcc3${GCC3_PKGMODIF}-c-${GCC_VERSION}{,nb*}
BUILDLINK_DEPMETHOD.gcc3-c+=	full

.include "../../lang/gcc3/Makefile.common"

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${RM} -f ${WRKSRC}/libiberty/libiberty.a ${WRKSRC}/gcc/xgcc
	${LN} -s ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -s ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

.if exists(${PKGDIR}/PLIST)
GCC_PLIST_AWK_SCRIPT=	'
GCC_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_SUBST}
GCC_PLIST_AWK_SCRIPT+=	\
	/\.la$$/ {							\
		lafile = "${PREFIX}/" $$0;				\
		dir = $$0;						\
		sub("/[^/]*\.la$$", "", dir);				\
		system("( . " lafile "; for lib in $$library_names $$old_library; do ${ECHO} " dir "/$$lib; done; ${ECHO} " $$0 " ) | ${SORT} -u"); \
		next;							\
	}
GCC_PLIST_AWK_SCRIPT+=	{ print $$0; }
GCC_PLIST_AWK_SCRIPT+=	'
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

post-install: gcc-plist
gcc-plist:
	@${CAT} ${PKGDIR}/PLIST | ${AWK} ${GCC_PLIST_AWK_SCRIPT} > ${PLIST_SRC}
.endif

.include "../../lang/gcc3-c/buildlink3.mk"
