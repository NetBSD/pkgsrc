# $NetBSD: Makefile,v 1.16 2005/01/27 04:15:10 kent Exp $

DISTVERSION=		3.3.3
MAINTAINER=		peace-sacrifice@hauN.org
HOMEPAGE=		http://chiharu.hauN.org/peace/
MASTER_SITES=		http://chiharu.hauN.org/peace/dist/
COMMENT=		Cross-compile environment for PEACE/i386
# Need NetBSD headers in /usr/include
ONLY_FOR_PLATFORM=	NetBSD-1.6[Q-Z]*-* NetBSD-[2-9]*-*
CONFLICTS=		pth-[0-9]* pth-current-[0-9]* pth-syscall-[0-9]*
DISTNAME=		cross-${TARGET_ARCH}-${DISTVERSION}
CATEGORIES+=		cross lang
USE_CROSSBASE=		yes

WRKSRC=			${WRKDIR}/${GCC_DISTNAME}
BU_WRKSRC=		${WRKDIR}/${BINUTILS_DISTNAME}
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
TARGET_ARCH=		i386-netbsdpe
GCC_CONFIGURE_ARGS+=	--enable-threads
BINUTILS_EXTRAS=	dlltool dllwrap windres

# Mingw pathes
DISTFILES+=		gcc-3.3.3-20040217-1-src.diff.gz
GCC_WIN32_PATCH=	${WRKDIR}/gcc-3.3.3-20040217-1-src.diff
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=mingw/}

MESSAGE_SUBST+=		CROSSBASE=${CROSSBASE}
TARGET_DIR=		${PREFIX}/${TARGET_ARCH}

GCC_DISTNAME=		gcc-3.3.3
GCC_INTVERSION=		3.3.3
MASTER_SITES+=		${MASTER_SITE_GNU:=gcc/releases/gcc-3.3.3/}
DISTFILES+=		${GCC_DISTNAME}.tar.gz
USE_GMAKE=		yes
USE_MAKEINFO=		YES
GCC_LANGUAGES=		c,c++
CONFIGURE_ENV=		${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"
GCC_CONFIGURE_ARGS=	--with-gnu-ld --with-gnu-as -disable-multilib \
		--enable-threads=posix --disable-shared --with-system-zlib \
		--enable-languages=${GCC_LANGUAGES} --with-headers=yes \
		--target=${TARGET_ARCH} --datadir=${TARGET_DIR}/share
GCC_MAKE_FLAGS=		AS_FOR_TARGET="${AS_FOR_TARGET}" \
			AR_FOR_TARGET="${AR_FOR_TARGET}" \
			NM_FOR_TARGET="${NM_FOR_TARGET}" \
			RANLIB_FOR_TARGET="${RANLIB_FOR_TARGET}"
#			INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
#			INSTALL_PROGRAM="${INSTALL_PROGRAM}"
GCC_MAKE=		${SETENV} ${MAKE_ENV} \
	                ${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS}
WRKOBJ=			${WRKDIR}/obj

BINUTILS_DISTNAME=	binutils-2.15.90-20040222-1
DISTFILES+=		${BINUTILS_DISTNAME}-src.tar.gz
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=mingw/}
#MASTER_SITES+=		${MASTER_SITE_GNU:=binutils/}
#MASTER_SITES+=		http://prdownloads.sourceforge.net/mingw/
#CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld --data-dir=${TARGET_DIR}/share
BU_WRKSRC=		${WRKDIR}/${BINUTILS_DISTNAME}
AS_FOR_TARGET=		${WRKOBJ}/gas/as-new
AR_FOR_TARGET=		${WRKOBJ}/binutils/ar
NM_FOR_TARGET=		${WRKOBJ}/binutils/nm-new
RANLIB_FOR_TARGET=	${WRKOBJ}/binutils/ranlib
LD_FOR_TARGET=		${WRKOBJ}/ld/ld-new

post-extract:
	-${PATCH} -d ${WRKSRC} -p1 --forward --quiet -E < ${GCC_WIN32_PATCH}
	${CP} ${WRKSRC}/gcc/config/i386/mingw32.h ${WRKSRC}/gcc/config/i386/netbsdpe.h
	${CP} ${WRKSRC}/gcc/config/i386/t-cygming ${WRKSRC}/gcc/config/i386/t-netbsdpe

post-patch:
	for i in patches/binutils-??; do \
		${PATCH} -d ${BU_WRKSRC} --forward --quiet -E < $$i; \
	done

CFLAGS_FOR_TARGET+=	-I${WRKDIR}
post-configure:
	${SED} "s/^extern FILE/__declspec(dllimport) FILE/" /usr/include/stdio.h > ${WRKDIR}/stdio.h

do-configure:
#	@-mkdir -p ${WRKOBJ}/libiberty
#	@cd ${WRKOBJ}/libiberty && ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" \
#		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
#		${WRKSRC}/libiberty/configure --prefix=${PREFIX}
	@-mkdir -p ${WRKOBJ} ${WRKOBJ}/binutils ${WRKOBJ}/gas ${WRKOBJ}/ld
	cd ${WRKOBJ} && ${CONFIGURE_ENV} ${BU_WRKSRC}/configure \
		--prefix=${PREFIX} ${GCC_CONFIGURE_ARGS} --disable-nls
	cd ${WRKOBJ}/binutils && ${CONFIGURE_ENV} ${BU_WRKSRC}/binutils/configure \
		--prefix=${PREFIX} ${GCC_CONFIGURE_ARGS} --disable-nls
	cd ${WRKOBJ}/gas && ${CONFIGURE_ENV} ${BU_WRKSRC}/gas/configure \
		--prefix=${PREFIX} ${GCC_CONFIGURE_ARGS} --disable-nls
	cd ${WRKOBJ}/ld && ${CONFIGURE_ENV} ${BU_WRKSRC}/ld/configure \
		--prefix=${PREFIX} ${GCC_CONFIGURE_ARGS} --disable-nls
# Build binutils before configuring gcc so that gcc's configure works correctly
	@cd ${WRKOBJ} && ${GCC_MAKE}
	@-mkdir -p ${WRKOBJ}/gcc
	@cd ${WRKOBJ}/gcc && ${CONFIGURE_ENV} ${WRKSRC}/gcc/configure \
		--prefix=${PREFIX} ${GCC_CONFIGURE_ARGS}

do-build:
	${LN} -sf ${AS_FOR_TARGET} ${WRKOBJ}/gcc/as
	${LN} -sf ${LD_FOR_TARGET} ${WRKOBJ}/gcc/ld
	@cd ${WRKOBJ}/gcc && ${GCC_MAKE}

do-install:
	@cd ${WRKOBJ} && ${GCC_MAKE} installdirs install-binutils \
		install-gas install-ld
	@cd ${WRKOBJ}/gas/doc && ${GCC_MAKE} install-man1
	@cd ${WRKOBJ}/gcc && ${GCC_MAKE} install-common \
		install-libgcc install-cpp install-po \
		lang.install-normal install-driver
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_INTVERSION}/include
	${INSTALL_DATA} ${WRKOBJ}/gcc/include/mmintrin.h \
		${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_INTVERSION}/include
	${INSTALL_DATA} ${WRKOBJ}/gcc/include/xmmintrin.h \
		${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_INTVERSION}/include
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	cd ${PREFIX}/bin && ${LN} -sf ${TARGET_ARCH}-gcc ${TARGET_ARCH}-cc
	cd ${TARGET_DIR}/bin && ${LN} -sf gcc cc

.include "../../mk/bsd.pkg.mk"
