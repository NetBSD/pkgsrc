# $NetBSD: Makefile,v 1.4 2001/09/27 23:17:52 jlam Exp $

DISTNAME=	cross-${TARGET_ARCH}-${DISTVERSION}
TARGET_ARCH=	mipsEEel-netbsd
DISTVERSION=	1.0.0
CATEGORIES+=	cross lang
MAINTAINER=	kent@netbsd.org
COMMENT=	Cross-compiler for NetBSD/PlayStation2 kernel

BZCAT=		/usr/bin/bzcat
USE_GMAKE=	yes

# We don't use CROSSBASE because the binutils are not the same as binutils
# for other cross compilers.
#USE_CROSSBASE=	yes
TARGET_DIR=	${PREFIX}/cross-ps2
PLIST_SUBST+=	SUBDIR="cross-ps2" TARGET_ARCH="${TARGET_ARCH}" \
		GCC_VERSION="${GCC_VERSION}"

#
# binutils
#
MASTER_SITES+=		ftp://ftp.netbsd.org/pub/NetBSD/misc/tshiozak/PlayStation2/GPLed-from-SCEI/binutils-2.9EE/
DISTFILES+=		binutils-2.9EE.linux.patch.bz2
BINUTILS_PATCH1=	${_DISTDIR}/binutils-2.9EE.linux.patch.bz2
DISTFILES+=		binutils-ps2linux-0.9.patch.bz2
BINUTILS_PATCH2=	${_DISTDIR}/binutils-ps2linux-0.9.patch.bz2

BINUTILS_DISTNAME=	binutils-2.9EE
BINUTILS_WRKSRC=	${WRKDIR}/${BINUTILS_DISTNAME}
DISTFILES+=		${BINUTILS_DISTNAME}.tar.gz
EXTRACT_ONLY=		${BINUTILS_DISTNAME}.tar.gz

#
# gcc
#
MASTER_SITES+=		ftp://ftp.netbsd.org/pub/NetBSD/misc/tshiozak/PlayStation2/GPLed-from-SCEI/gcc-2.95.2EE/
GCC_VERSION=		2.95.2
GCC_DISTNAME=		gcc-${GCC_VERSION}
GCC_WRKSRC=		${WRKDIR}/${GCC_DISTNAME}
DISTFILES+=		${GCC_DISTNAME}.tar.gz
EXTRACT_ONLY+=		${GCC_DISTNAME}.tar.gz
DISTFILES+=		gcc-${GCC_VERSION}.EE-linux.patch.bz2
GCC_PATCH1=		${_DISTDIR}/gcc-${GCC_VERSION}.EE-linux.patch.bz2
DISTFILES+=		gcc-ps2linux-0.9.1.patch.bz2
GCC_PATCH2=		${_DISTDIR}/gcc-ps2linux-0.9.1.patch.bz2
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf


pre-patch: binutils-patch gcc-patch
do-configure: binutils-configure gcc-configure
do-build: binutils-build gcc-build
do-install: binutils-install gcc-install


binutils-patch:
	${BZCAT} ${BINUTILS_PATCH1} | ${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -p1 -E
	${BZCAT} ${BINUTILS_PATCH2} | ${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -p1 -E
	for i in patches/binutils-*; do \
		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
	done

binutils-configure:
	${MKDIR} ${BINUTILS_WRKSRC}/obj
	cd ${BINUTILS_WRKSRC}/obj && ../configure --prefix=${TARGET_DIR} \
		--target=${TARGET_ARCH}

binutils-build:
	${GMAKE} -C ${BINUTILS_WRKSRC}/obj

binutils-install:
	${GMAKE} -C ${BINUTILS_WRKSRC}/obj install


gcc-patch:
	${BZCAT} ${GCC_PATCH1} | ${PATCH} -d ${GCC_WRKSRC} --forward --quiet -p1 -E
	${BZCAT} ${GCC_PATCH2} | ${PATCH} -d ${GCC_WRKSRC} --forward --quiet -p1 -E
	for i in patches/gcc-*; do \
		${PATCH} -d ${GCC_WRKSRC} --forward --quiet -E < $$i; \
	done

gcc-configure:
	${MKDIR} ${GCC_WRKSRC}/obj
	cd ${GCC_WRKSRC}/obj && ../configure --prefix=${TARGET_DIR} \
		--enable-shared --target=${TARGET_ARCH} \
		--enable-languages=c,c++ --with-gnu-as \
		--with-gnu-ld --disable-nls
	-${RM} ${GCC_WRKSRC}/obj/texinfo/makeinfo/Makefile

gcc-build:
	-${RM} ${GCC_WRKSRC}/obj/gcc/as
	-${RM} ${GCC_WRKSRC}/obj/gcc/ld
	${LN} -s ${BINUTILS_WRKSRC}/obj/gas/as-new ${GCC_WRKSRC}/obj/gcc/as
	${LN} -s ${BINUTILS_WRKSRC}/obj/ld/ld-new ${GCC_WRKSRC}/obj/gcc/ld
	${GMAKE} -C ${GCC_WRKSRC}/obj/libiberty
#	${GMAKE} -C ${GCC_WRKSRC}/obj/texinfo
	${GMAKE} -C ${GCC_WRKSRC}/obj/gcc LIBGCC="" LIBGCC1_TEST="" INSTALL_LIBGCC=""

gcc-install:
	${GMAKE} -C ${GCC_WRKSRC}/obj/gcc install-common install-headers install-cpp lang.install-normal install-driver

.include "../../mk/bsd.pkg.mk"

