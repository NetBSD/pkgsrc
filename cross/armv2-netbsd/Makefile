# $NetBSD: Makefile,v 1.1.1.1 2000/07/13 21:39:11 bjh21 Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

#USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-littlearm
BINUTILS_LDEMULATION=	armelf
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		armv2-netbsd

BUILD_DEPENDS+=		autoconf:../../devel/autoconf

post-patch: egcs-autoconf

egcs-autoconf:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/gcc && autoconf

# FOllowing chunk ripped from cross.mk

BINUTILS_DISTNAME=	binutils-2.10
BINUTILS_WRKSRC=	${WRKDIR}/${BINUTILS_DISTNAME}

CROSS_DISTFILES+=	${BINUTILS_DISTNAME}.tar.gz
MASTER_SITES+=		${MASTER_SITE_GNU:=binutils/}
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
PLIST_PRE+=		${COMMON_DIR}/PLIST-binutils

AS_FOR_TARGET=		${BINUTILS_WRKSRC}/gas/as-new
AR_FOR_TARGET=		${BINUTILS_WRKSRC}/binutils/ar
NM_FOR_TARGET=		${BINUTILS_WRKSRC}/bintuils/nm-new
RANLIB_FOR_TARGET=	${BINUTILS_WRKSRC}/binutils/ranlib
LD_FOR_TARGET=		${BINUTILS_WRKSRC}/ld/ld-new

#pre-patch: binutils-patch
pre-configure: binutils-configure
do-build: binutils-build
do-install: binutils-install

#binutils-patch:
#	@for i in ${COMMON_DIR}/patches-binutils/patch-*; do \
#		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
#	done

#BFD64ARG=	--enable-64-bit-bfd

binutils-configure:
	@cd ${BINUTILS_WRKSRC} && ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
		CFLAGS="${CFLAGS}" ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} --host=${MACHINE_GNU_ARCH}--netbsd \
		--target=arm-unknown-elf ${BFD64ARG}

binutils-build:
	@cd ${BINUTILS_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} all

binutils-install:
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/gas/as-new ${TARGET_DIR}/bin/as
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/ld/ld-new ${TARGET_DIR}/bin/ld
	for i in addr2line ar objcopy objdump ranlib size strings ${BINUTILS_EXTRAS}; do \
		${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/binutils/$$i ${TARGET_DIR}/bin/$$i; \
	done
	for i in nm strip; do \
		${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/binutils/$$i-new ${TARGET_DIR}/bin/$$i; \
	done
	for i in addr2line ar as ld nm objcopy objdump ranlib size strings strip ${BINUTILS_EXTRAS}; do \
		${LN} -f ${TARGET_DIR}/bin/$$i ${PREFIX}/bin/${TARGET_ARCH}-$$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/lib/ldscripts
	for i in x xbn xn xr xs xu; do \
		${INSTALL_DATA} ${BINUTILS_WRKSRC}/ld/ldscripts/armelf.$$i ${PREFIX}/lib/ldscripts/; \
	done

.include "../COMMON/cross.mk"
