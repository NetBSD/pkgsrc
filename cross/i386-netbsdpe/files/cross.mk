#	$NetBSD: cross.mk,v 1.17 2003/09/21 20:44:13 wiz Exp $
#	based on pkgsrc/cross/COMMON/cross.mk
#	NetBSD: cross.mk,v 1.16 2000/11/09 13:04:55 wiz Exp 

DISTNAME=		cross-${TARGET_ARCH}-${DISTVERSION}
CATEGORIES+=		cross lang
USE_CROSSBASE=		yes
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
MESSAGE_SUBST+=		CROSSBASE=${CROSSBASE}

HOMEPAGE?=		http://gcc.gnu.org/

TARGET_DIR=		${PREFIX}/${TARGET_ARCH}
COMMON_DIR=		${_PKGSRCDIR}/cross/COMMON
GCC_PLIST_DIR=		files
PLIST_PRE?=		${PKGDIR}/PLIST

pre-install: pre-install-dirs
pre-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}
	${INSTALL_DATA_DIR} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/bin
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib

.if defined(USE_CROSS_BINUTILS)
BINUTILS_DISTNAME=	binutils-030425
DISTFILES+=		${BINUTILS_DISTNAME}.tar.bz2
SITES_binutils-030425.tar.bz2=	ftp://ftp.netbsd.org/pub/NetBSD/misc/kent/
MASTER_SITES+=		${MASTER_SITE_GNU:=binutils/}
#MASTER_SITES+=		http://prdownloads.sourceforge.net/mingw/
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld --data-dir=${TARGET_DIR}/share
PLIST_PRE+=		${COMMON_DIR}/PLIST-binutils

AS_FOR_TARGET=		${WRKOBJ}/gas/as-new
AR_FOR_TARGET=		${WRKOBJ}/binutils/ar
NM_FOR_TARGET=		${WRKOBJ}/binutils/nm-new
RANLIB_FOR_TARGET=	${WRKOBJ}/binutils/ranlib
LD_FOR_TARGET=		${WRKOBJ}/ld/ld-new

do-install: binutils-install

binutils-install:
	${INSTALL_PROGRAM} ${WRKOBJ}/gas/as-new ${TARGET_DIR}/bin/as
	${INSTALL_PROGRAM} ${WRKOBJ}/ld/ld-new ${TARGET_DIR}/bin/ld
	${INSTALL_PROGRAM} ${WRKOBJ}/binutils/nm-new ${TARGET_DIR}/bin/nm
	${INSTALL_PROGRAM} ${WRKOBJ}/binutils/strip-new ${TARGET_DIR}/bin/strip
	for i in addr2line ar objcopy objdump ranlib size strings ${BINUTILS_EXTRAS}; do \
		${INSTALL_PROGRAM} ${WRKOBJ}/binutils/$$i ${TARGET_DIR}/bin/$$i; \
	done
	for i in addr2line ar as ld nm objcopy objdump ranlib size strings strip ${BINUTILS_EXTRAS}; do \
		${LN} -f ${TARGET_DIR}/bin/$$i ${PREFIX}/bin/${TARGET_ARCH}-$$i; \
	done
.endif # USE_CROSS_BINUTILS

.if defined(USE_CROSS_GCC)
GCC_DISTNAME=		gcc-2.95.2
GCC_INTVERSION=		2.95.2
MASTER_SITES+=		${MASTER_SITE_GNU:=gcc/}
GCC_LANGUAGES=		c # add to these below
AUTOCONF_REQD=		2.13
USE_MAKEINFO=		YES

.  if defined(GCC_CXX)
CXX_CONFIGURE_ARGS+=	--with-gxx-include-dir=${TARGET_DIR}/include/c++
GCC_LANGUAGES+=		c++
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-cxx
.    if defined(GCC_CXX_RUNTIME)
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-cxx-runtime
.    endif
.  endif # GCC_CXX

# the main PLIST needs to go last to get the @dirrm's right
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc
DISTFILES+=		${GCC_DISTNAME}.tar.gz
USE_GMAKE=		yes

CC_FOR_TARGET=		${WRKOBJ}/gcc/xgcc -B${WRKOBJ}/gcc/ ${CFLAGS_FOR_TARGET}
CXX_FOR_TARGET=		${CC_FOR_TARGET}

GCC_MAKE_FLAGS=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
			CC_FOR_TARGET="${CC_FOR_TARGET}" \
			GCC_FOR_TARGET="${CC_FOR_TARGET}" \
			CXX_FOR_TARGET="${CXX_FOR_TARGET}" \
			AS_FOR_TARGET="${AS_FOR_TARGET}" \
			AR_FOR_TARGET="${AR_FOR_TARGET}" \
			NM_FOR_TARGET="${NM_FOR_TARGET}" \
			RANLIB_FOR_TARGET="${RANLIB_FOR_TARGET}" \
			LDFLAGS_FOR_TARGET="${LDFLAGS_FOR_TARGET}" \
			LANGUAGES="${GCC_LANGUAGES}" \
			INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"
GCC_MAKE=		${SETENV} ${MAKE_ENV} \
	                ${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS}

.  if defined(GCC_FAKE_RUNTIME)
CROSS_SYS_INCLUDE=	${WRKDIR}/include
.  endif
.  if defined(CROSS_SYS_INCLUDE)
CFLAGS_FOR_TARGET+=	-idirafter ${CROSS_SYS_INCLUDE}
GCC_MAKE_FLAGS+=	SYSTEM_HEADER_DIR="${CROSS_SYS_INCLUDE}"
.  endif
.  if defined(SYS_LIB)
LDFLAGS_FOR_TARGET+=	-L${SYS_LIB}
.  endif

pre-configure: gcc-configure
do-build: gcc-build
do-install: gcc-install

WRKOBJ=	${WRKDIR}/obj
gcc-configure:
	@-mkdir ${WRKOBJ}
	@cd ${WRKOBJ} && ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		${BU_WRKSRC}/configure --prefix=${PREFIX} \
		--host=${MACHINE_GNU_ARCH}--netbsd  --target=${TARGET_ARCH} \
		${GCC_CONFIGURE_ARGS} ${CXX_CONFIGURE_ARGS}
	@-mkdir ${WRKOBJ}/gcc
	@cd ${WRKOBJ}/gcc && ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		${WRKSRC}/gcc/configure --prefix=${PREFIX} \
		--host=${MACHINE_GNU_ARCH}--netbsd  --target=${TARGET_ARCH} \
		${GCC_CONFIGURE_ARGS} ${CXX_CONFIGURE_ARGS}
.  if defined(GCC_FAKE_RUNTIME)
	@${MKDIR} ${CROSS_SYS_INCLUDE} ${CROSS_SYS_INCLUDE}/machine ${CROSS_SYS_INCLUDE}/sys
	@cd ${CROSS_SYS_INCLUDE} && ${TOUCH} ${TOUCH_FLAGS} machine/ansi.h \
		sys/time.h stdlib.h unistd.h
.  endif

gcc-build:
	${LN} -s ${AS_FOR_TARGET} ${WRKOBJ}/gcc/as
	${LN} -s ${LD_FOR_TARGET} ${WRKOBJ}/gcc/ld
	@cd ${WRKOBJ} && make all-libiberty all-binutils all-gas all-ld
	@cd ${WRKOBJ}/gcc && ${GCC_MAKE} all
.  if defined(GCC_CXX) && defined(GCC_CXX_RUNTIME)
	@cd ${WRKOBJ} && ${GCC_MAKE} configure-target-libio \
		configure-target-libstdc++ all-target-libio all-target-libstdc++
.  endif

gcc-install:
	@cd ${WRKOBJ}/gcc && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS} \
		install-common install-headers install-libgcc install-driver
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_INTVERSION}
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-gcc ${PREFIX}/bin/${TARGET_ARCH}-cc
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-gcc ${TARGET_DIR}/bin/cc
	${RM} ${PREFIX}/bin/${TARGET_ARCH}-gcj # install-driver installs gcj but we need not it
.  if defined(GCC_CXX)
	@${MKDIR} ${TARGET_DIR}/include/c++
	@for file in exception new new.h typeinfo; do \
		${INSTALL_DATA} ${WRKSRC}/gcc/cp/inc/$$file ${TARGET_DIR}/include/c++; \
	done
.    if defined(GCC_CXX_RUNTIME)
	@${MKDIR} ${TARGET_DIR}/include/g++/std
	@cd ${WRKSRC} && ${GCC_MAKE} install-target-libstdc++
.    endif
	for file in c++ c++filt g++; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
.  endif # GCC_CXX
	@${RMDIR} -p ${PREFIX}/info 2>/dev/null || ${TRUE}
	@${RMDIR} -p ${PREFIX}/man/man1 2>/dev/null || ${TRUE}
.endif # USE_CROSS_GCC


.if defined(CROSS_SYS_INCLUDE) && !defined(GCC_FAKE_RUNTIME)
pre-install: pre-install-includes
pre-install-includes:
	cd ${CROSS_SYS_INCLUDE} && ${PAX} -rw . ${TARGET_DIR}/include
.endif

.if defined(SYS_LIB)
pre-install: pre-install-lib
pre-install-lib:
	cd ${SYS_LIB} && ${PAX} -rw . ${TARGET_DIR}/lib
.endif

post-install: post-install-plist
post-install-plist:
	@${SED} -e 's|$${TARGET_ARCH}|${TARGET_ARCH}|' \
		-e 's|$${GCC_INTVERSION}|${GCC_INTVERSION}|' \
		${PLIST_PRE} >${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/bin' >>${PLIST_SRC}
	@${ECHO} '@exec mkdir -p ${TARGET_ARCH}/include' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/include' >>${PLIST_SRC}
	@${ECHO} '@exec mkdir -p ${TARGET_ARCH}/lib' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/lib' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}' >>${PLIST_SRC}

.include "../../../mk/autoconf.mk"
.include "../../../mk/bsd.pkg.mk"

#EXTRACT_BEFORE_ARGS:=	-X ${COMMON_DIR}/exclude ${EXTRACT_BEFORE_ARGS}
