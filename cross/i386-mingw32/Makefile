# $NetBSD: Makefile,v 1.13 2003/12/12 07:28:23 reed Exp $

DISTNAME=		cross-${TARGET_ARCH}-1.2
PKGREVISION=		3
WRKSRC=			${WRKDIR} # for the patch target
CROSS_DISTFILES=
MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mingw.org/
COMMENT=		Cross-compile environment for MinGW
CATEGORIES+=		cross lang

USE_CROSSBASE=		yes
TARGET_ARCH=		i386-mingw32
TARGET_DIR=		${PREFIX}/${TARGET_ARCH}

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mingw/}
CROSS_DISTFILES+=	binutils-2.11.92-20011113-src.tar.gz
BINUTILS_WRKSRC=	${WRKDIR}/binutils-2.11.92-20011113
BINUTILS_EXTRAS=	dlltool dllwrap windres
CROSS_DISTFILES+=	gcc-2.95.3-20011106-src.tar.gz
GCC_WRKSRC=		${WRKDIR}/gcc-2.95.3-20011106
GCC_VERSION=		2.95.3-7
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION}
CROSS_DISTFILES+=	mingw-runtime-1.2-src.tar.gz
MINGW_WRKSRC=		${WRKDIR}/mingw-runtime-1.2
CROSS_DISTFILES+=	w32api-1.2-src.tar.gz
W32_WRKSRC=		${WRKDIR}/w32api-1.2
USE_GMAKE=		yes
USE_PERL5=		build

AS_FOR_TARGET=		${BINUTILS_WRKSRC}/gas/as-new
AR_FOR_TARGET=		${BINUTILS_WRKSRC}/binutils/ar
NM_FOR_TARGET=		${BINUTILS_WRKSRC}/binutils/nm-new
RANLIB_FOR_TARGET=	${BINUTILS_WRKSRC}/binutils/ranlib
LD_FOR_TARGET=		${BINUTILS_WRKSRC}/ld/ld-new
CC_FOR_TARGET=		${GCC_WRKSRC}/${TARGET_ARCH}/gcc/xgcc \
		-B${GCC_WRKSRC}/${TARGET_ARCH}/gcc/ ${CFLAGS_FOR_TARGET} \
		-I${MINGW_WRKSRC}/include -I${W32_WRKSRC}/include -L${W32_WRKSRC}/lib
CXX_FOR_TARGET=		${CC_FOR_TARGET}
GCC_MAKE_FLAGS=		\
			CC_FOR_TARGET="${CC_FOR_TARGET}" \
			GCC_FOR_TARGET="${CC_FOR_TARGET}" \
			CXX_FOR_TARGET="${CXX_FOR_TARGET}" \
			AS_FOR_TARGET="${AS_FOR_TARGET}" \
			AR_FOR_TARGET="${AR_FOR_TARGET}" \
			NM_FOR_TARGET="${NM_FOR_TARGET}" \
			RANLIB_FOR_TARGET="${RANLIB_FOR_TARGET}" \
			LD_FOR_TARGET="${LD_FOR_TARGET}" \
			LANGUAGES="c c++" \
			INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"
TARGET_CONFIGURE_ENV=	CC="${CC_FOR_TARGET}" \
			AR="${AR_FOR_TARGET}" \
			AS="${AS_FOR_TARGET}" \
			RANLIB="${RANLIB_FOR_TARGET}" \
			LD="${LD_FOR_TARGET}" \
			DLLTOOL="${BINUTILS_WRKSRC}/binutils/dlltool" \
			WINDRES="${BINUTILS_WRKSRC}/binutils/windres"

DISTFILES+=	${CROSS_DISTFILES}


do-configure: bu-configure gcc-configure
bu-configure:
	cd ${BINUTILS_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} --target=${TARGET_ARCH} --disable-nls
gcc-configure:
	-${MKDIR} ${GCC_WRKSRC}/${TARGET_ARCH}
	cd ${GCC_WRKSRC}/${TARGET_ARCH} && ${SETENV} ${CONFIGURE_ENV} ../configure \
		--prefix=${PREFIX} --target=${TARGET_ARCH} \
		--with-gnu-as --with-gnu-ld --disable-multilib --disable-nls
	-${MKDIR} ${GCC_WRKSRC}/${TARGET_ARCH}/${TARGET_ARCH}/libiberty
	cd ${GCC_WRKSRC}/${TARGET_ARCH}/${TARGET_ARCH}/libiberty && ${SETENV} \
		${CONFIGURE_ENV} ../../../libiberty/configure \
		--prefix=${PREFIX} --target=${TARGET_ARCH} --disable-nls
	${CP} ${FILESDIR}/config.h ${GCC_WRKSRC}/${TARGET_ARCH}/${TARGET_ARCH}/libiberty


do-build: bu-build gcc-build w32-build mingw-build
bu-build:
	cd ${BINUTILS_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
gcc-build:
	@${LN} -sf ${AS_FOR_TARGET} ${GCC_WRKSRC}/${TARGET_ARCH}/gcc/as
	@${LN} -sf ${LD_FOR_TARGET} ${GCC_WRKSRC}/${TARGET_ARCH}/gcc/ld
	cd ${GCC_WRKSRC}/${TARGET_ARCH} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS}
w32-build:
	cd ${W32_WRKSRC} && ${SETENV} ${TARGET_CONFIGURE_ENV} ${CONFIGURE_ENV} \
		./configure --target=${TARGET_ARCH}
	cd ${W32_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
mingw-build:
	cd ${MINGW_WRKSRC} && ${SETENV} ${TARGET_CONFIGURE_ENV} ${CONFIGURE_ENV} \
		./configure --target=${TARGET_ARCH}
	cd ${MINGW_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}


do-install: bu-install gcc-install w32-install mingw-install
bu-install:
	${INSTALL_PROGRAM_DIR} ${TARGET_DIR}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/gas/as-new ${TARGET_DIR}/bin/as
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/ld/ld-new ${TARGET_DIR}/bin/ld
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/binutils/nm-new ${TARGET_DIR}/bin/nm
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/binutils/strip-new ${TARGET_DIR}/bin/strip
	for i in addr2line ar objcopy objdump ranlib size strings ${BINUTILS_EXTRAS}; do \
		${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/binutils/$$i ${TARGET_DIR}/bin/$$i; \
	done
	for i in addr2line ar as ld nm objcopy objdump ranlib size strings strip \
	${BINUTILS_EXTRAS}; do \
		${LN} -f ${TARGET_DIR}/bin/$$i ${PREFIX}/bin/${TARGET_ARCH}-$$i; \
	done
gcc-install:
	@cd ${GCC_WRKSRC}/${TARGET_ARCH}/gcc && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS} \
		install-common install-headers install-libgcc install-driver
	@${MKDIR} ${TARGET_DIR}/include/g++-3
	@${MKDIR} ${TARGET_DIR}/include/g++-3/std
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib
	@cd ${GCC_WRKSRC}/${TARGET_ARCH} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} ${GCC_MAKE_FLAGS} prefix="${TARGET_DIR}" \
		tooldir="${TARGET_DIR}" \
		libsubdir="${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_VERSION}" \
		install-target-libstdc++
	for file in c++ c++filt g++; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
w32-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	${INSTALL_DATA} ${W32_WRKSRC}/include/*.h ${TARGET_DIR}/include
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${W32_WRKSRC}/lib/lib*.a ${TARGET_DIR}/lib
mingw-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include/sys
	${INSTALL_DATA} ${MINGW_WRKSRC}/include/*.h ${TARGET_DIR}/include
	${INSTALL_DATA} ${MINGW_WRKSRC}/include/sys/*.h ${TARGET_DIR}/include/sys
	for file in libcrtdll libmsvcrt libmsvcrt20 libmsvcrt40 libmingw32 \
	libcoldname libmoldname libm libmingwthrd profile/libgmon ; do \
		${INSTALL_DATA} ${MINGW_WRKSRC}/$$file.a ${TARGET_DIR}/lib; \
	done
	${INSTALL_DATA} ${MINGW_WRKSRC}/mingwm10.dll ${TARGET_DIR}/lib
	for file in crt1 dllcrt1 crt2 dllcrt2  CRT_noglob crtmt crtst \
	profile/gcrt1 profile/gcrt2; do \
		${INSTALL_DATA} ${MINGW_WRKSRC}/$$file.o ${TARGET_DIR}/lib; \
	done

.include "../../mk/bsd.pkg.mk"
