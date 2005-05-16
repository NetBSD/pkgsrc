# $NetBSD: Makefile,v 1.19 2005/05/16 01:32:22 jlam Exp $

DISTNAME=		cross-${TARGET_ARCH}-3.2
CROSS_DISTFILES=
MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mingw.org/
COMMENT=		Cross-compile environment for MinGW
CATEGORIES+=		cross lang

USE_CROSSBASE=		yes
TARGET_ARCH=		i386-mingw32
TARGET_DIR=		${PREFIX}/${TARGET_ARCH}

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mingw/}
CROSS_DISTFILES+=	binutils-2.15.90-20040222-1-src.tar.gz
BINUTILS_WRKSRC=	${WRKDIR}/binutils-2.15.90-20040222-1
BINUTILS_EXTRAS=	dlltool dllwrap windres
GCC_VERSION=		3.3.3
CROSS_DISTFILES+=	gcc-${GCC_VERSION}.tar.gz gcc-3.3.3-20040217-1-src.diff.gz \
			gcc-g++-3.3.3-20040217-1.tar.gz
MASTER_SITES+=		${MASTER_SITE_GNU:=gcc/releases/gcc-3.3.3/}
GCC_WIN32_PATCH=	${WRKDIR}/gcc-3.3.3-20040217-1-src.diff
GCC_WRKSRC=		${WRKDIR}/gcc-${GCC_VERSION}
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION}
CROSS_DISTFILES+=	mingw-runtime-3.2.tar.gz
MINGW_WRKSRC=		${WRKDIR}/mingw-runtime-3.2
CROSS_DISTFILES+=	w32api-2.5.tar.gz
W32_WRKSRC=		${WRKDIR}/w32api-2.5
USE_GNU_TOOLS+=		make
PKGSRC_USE_TOOLS+=	tar
USE_PERL5=		build

WRKSRC=			${WRKDIR} # for the patch target
AS_FOR_TARGET=		${BINUTILS_WRKSRC}/gas/as-new
AR_FOR_TARGET=		${BINUTILS_WRKSRC}/binutils/ar
NM_FOR_TARGET=		${BINUTILS_WRKSRC}/binutils/nm-new
RANLIB_FOR_TARGET=	${BINUTILS_WRKSRC}/binutils/ranlib
LD_FOR_TARGET=		${BINUTILS_WRKSRC}/ld/ld-new
CC_FOR_TARGET=		${GCC_WRKSRC}/${TARGET_ARCH}/gcc/xgcc \
		-B${GCC_WRKSRC}/${TARGET_ARCH}/gcc/ ${CFLAGS_FOR_TARGET} \
		-I${WRKSRC}/include -L${WRKSRC}/lib
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

post-extract:
	-${PATCH} -d ${GCC_WRKSRC} -p1 --forward --quiet -E < ${GCC_WIN32_PATCH}

do-configure: bu-configure gcc-configure
bu-configure:
	cd ${BINUTILS_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} --target=${TARGET_ARCH} --disable-nls
gcc-configure:
	-${MKDIR} ${GCC_WRKSRC}/${TARGET_ARCH}
	cd ${GCC_WRKSRC}/${TARGET_ARCH} && ${SETENV} ${CONFIGURE_ENV} ../configure \
		--prefix=${PREFIX} --target=${TARGET_ARCH} \
		--with-gnu-as --with-gnu-ld --disable-multilib --disable-nls \
		--enable-sjlj-exceptions \
		--with-gxx-include-dir=${TARGET_DIR}/include/c++/${GCC_VERSION}

do-build:
	cd ${BINUTILS_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	@${LN} -sf ${AS_FOR_TARGET} ${GCC_WRKSRC}/${TARGET_ARCH}/gcc/as
	@${LN} -sf ${LD_FOR_TARGET} ${GCC_WRKSRC}/${TARGET_ARCH}/gcc/ld
	cd ${GCC_WRKSRC}/${TARGET_ARCH} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS} all-gcc

do-install: bu-install gcc-install mingw-install
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
	for file in c++ g++; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
	${RM} ${PREFIX}/bin/${TARGET_ARCH}-gcj
mingw-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	cd ${WRKSRC}/include && ${TAR} cf - * | ${TAR} xf - -C ${TARGET_DIR}/include
	${MV} ${TARGET_DIR}/include/c++/${GCC_VERSION}/mingw32 \
		${TARGET_DIR}/include/c++/${GCC_VERSION}/i386-mingw32
	${CHMOD} a-wx `${FIND} ${TARGET_DIR}/include -type f`
	${CHMOD} a-w `${FIND} ${TARGET_DIR}/include -type d`
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib
	-rm -r ${WRKSRC}/lib/gcc-lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/bin/mingwm10.dll ${TARGET_DIR}/lib

.include "../../mk/bsd.pkg.mk"
