#	$NetBSD: cross.mk,v 1.3 1998/08/20 15:16:44 tsarna Exp $

# Shared definitions for building a cross-compile environment.

DISTNAME=		cross-${TARGET_ARCH}-${DISTVERSION}
CATEGORIES+=		cross lang
USE_CROSSBASE=		yes
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

HOMEPAGE?=		http://egcs.cygnus.com/

TARGET_DIR=		${PREFIX}/${TARGET_ARCH}
COMMON_DIR=		${PKGSRCDIR}/cross/COMMON
PLIST_PRE?=		${PKGDIR}/PLIST

do-install: do-install-dirs
do-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}
	${INSTALL_DATA_DIR} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/bin
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib

.if defined(USE_CROSS_GNU)
BINUTILS_DISTNAME=	binutils-2.9.1
CROSS_DISTFILES+=	${BINUTILS_DISTNAME}.tar.gz
MASTER_SITES+=		${MASTER_SITE_GNU}
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
PLIST_PRE+=		${COMMON_DIR}/PLIST-binutils
#CROSS_PATCHFILES+=	${COMMON_DIR}/patches-binutils/patch-*
USE_CROSS_EGCS=		yes

post-extract: post-extract-binutils
post-extract-binutils:
	@cd ${WRKSRC} && \
		${LN} -sf ../${BINUTILS_DISTNAME}/bfd && \
		${LN} -sf ../${BINUTILS_DISTNAME}/binutils && \
		${LN} -sf ../${BINUTILS_DISTNAME}/gas && \
		${LN} -sf ../${BINUTILS_DISTNAME}/ld && \
		${LN} -sf ../${BINUTILS_DISTNAME}/opcodes && \
		${LN} -sf ../gas/as-new gcc/as && \
		${LN} -sf ../ld/ld-new gcc/ld
	@cd ${WRKDIR}/${BINUTILS_DISTNAME} && \
		${RM} -rf libiberty texinfo && \
		${LN} -sf ../${EGCS_DISTNAME}/libiberty

do-install: do-install-binutils
do-install-binutils:
	@cd ${WRKSRC}/binutils && ${GMAKE} install-exec
	@cd ${WRKSRC}/gas && ${GMAKE} install-exec
	@cd ${WRKSRC}/ld && ${GMAKE} install-exec
	for file in addr2line c++filt gasp objcopy objdump size strings; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
.endif

.if defined(USE_CROSS_EGCS)
#.if defined(USE_CROSS_EGCS_SNAPSHOT)
EGCS_DISTNAME=		egcs-19980803
EGCS_DISTDIR=		snapshots/1998-08-03
EGCS_INTVERSION=	egcs-2.91.53
EGCS_PLIST_PRE=		${COMMON_DIR}/PLIST-egcs-ss
CROSS_PATCHFILES+=	${COMMON_DIR}/patches-egcs-ss/patch-*
#.else
#EGCS_DISTNAME=		egcs-1.1
#EGCS_DISTDIR=		releases/egcs-1.1
#EGCS_INTVERSION=	egcs-2.??.??
#.endif

CROSS_DISTFILES+=	${EGCS_DISTNAME}.tar.gz
MASTER_SITES+=		ftp://egcs.cygnus.com/pub/egcs/${EGCS_DISTDIR}/
WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}
PLIST_PRE+=		${EGCS_PLIST_PRE}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--target=${TARGET_ARCH} \
			--enable-version-specific-runtime-libs
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
USE_GMAKE=		yes
MAKE_FLAGS+=		CC_FOR_TARGET="${WRKSRC}/gcc/xgcc -B${WRKSRC}/gcc/ ${CFLAGS_FOR_TARGET}" \
			GCC_FOR_TARGET='$${CC_FOR_TARGET}' \
			CXX_FOR_TARGET='$${CC_FOR_TARGET}' \
			LDFLAGS_FOR_TARGET="${LDFLAGS_FOR_TARGET}" \
			LANGUAGES="c c++ f77 objc"

.if defined(SYS_INCLUDE)
CFLAGS_FOR_TARGET+=	-idirafter ${SYS_INCLUDE}
MAKE_FLAGS+=		SYSTEM_HEADER_DIR="${SYS_INCLUDE}"
.endif
.if defined(SYS_LIB)
LDFLAGS_FOR_TARGET+=	-L${SYS_LIB}
.endif

post-extract: post-extract-egcs
post-extract-egcs:
	@cd ${WRKSRC} && ${RM} -rf texinfo

do-install: do-install-egcs
do-install-egcs:
	@cd ${WRKSRC}/gcc && ${GMAKE} ${MAKE_FLAGS} install-common install-headers install-libgcc install-driver
	chown -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${EGCS_INTVERSION}
	@cd ${WRKSRC} && ${GMAKE} ${MAKE_FLAGS} install-target-libf2c install-target-libstdc++
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-gcc ${PREFIX}/bin/${TARGET_ARCH}-cc
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-g77 ${PREFIX}/bin/${TARGET_ARCH}-f77
	for file in cc c++ f77 g++ g77; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
	@${RMDIR} -p ${PREFIX}/info 2>/dev/null || ${TRUE}
	@${RMDIR} -p ${PREFIX}/man/man1 2>/dev/null || ${TRUE}
.endif

.if defined(SYS_INCLUDE)
do-install: do-install-includes
do-install-includes:
	cd ${SYS_INCLUDE} && pax -rw . ${TARGET_DIR}/include
.endif

.if defined(SYS_LIB)
do-install: do-install-lib
do-install-lib:
	cd ${SYS_LIB} && pax -rw . ${TARGET_DIR}/lib
.endif

post-install: post-install-plist
post-install-plist:
	@${SED} -e 's|$${TARGET_ARCH}|${TARGET_ARCH}|' \
		-e 's|$${EGCS_INTVERSION}|${EGCS_INTVERSION}|' \
		${PLIST_PRE} >${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/bin' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/include' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/lib' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}' >>${PLIST_SRC}

.if defined(CROSS_PATCHFILES)
PATCHFILES+=		${CROSS_PATCHFILES}
ALLFILES=		${DISTFILES}	# don't checksum shared patches
.endif

.if defined(CROSS_DISTFILES)
DISTFILES+=		${CROSS_DISTFILES}
.if defined(EXTRACT_ONLY)
EXTRACT_ONLY+=		${CROSS_DISTFILES}
.endif
.endif

.include "../../mk/bsd.pkg.mk"
