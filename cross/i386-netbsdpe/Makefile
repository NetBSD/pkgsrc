# $NetBSD: Makefile,v 1.10 2002/08/21 12:42:44 kent Exp $
# $PEACE: Makefile,v 1.21 2002/08/21 02:48:23 kent Exp $

DISTVERSION=		1.3.4
CROSS_DISTFILES=		# none

MAINTAINER=		peace-sacrifice@hauN.org
HOMEPAGE=		http://chiharu.hauN.org/peace/
COMMENT=		Cross-compile environment for PEACE/i386
# Need NetBSD headers in /usr/include
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}/toolchain

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_GCC=		yes
GCC_FAKE_RUNTIME=	yes
GCC_CXX=		yes
#GCC_CXX_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdpe
GCC_CONFIGURE_ARGS+=	--enable-threads

BINUTILS_EXTRAS=	dlltool dllwrap windres

# Mingw pathes
GCC_WIN32_PATCHBUNDLE=	${GCC_DISTNAME}-x86-win32-patches.tar.gz
GCC_WIN32_PATCH=	${WRKDIR}/${GCC_DISTNAME}-patches/${GCC_DISTNAME}-x86-win32.diff
MASTER_SITES+=		ftp://ftp.xraylith.wisc.edu/pub/khan/gnu-win32/mingw32/${GCC_DISTNAME}/patches/
DISTFILES+=		${GCC_WIN32_PATCHBUNDLE}

# SSP patch
MASTER_SITES+=		http://www.trl.ibm.com/projects/security/ssp/gcc2_95_2/
SSP_PATCH=		protector-2.95.2-2.tar.gz
DISTFILES+=		${SSP_PATCH}

# pthread
PTHREAD_DISTNAME=	unproven-pthreads-0.17
PTHREAD_DISTFILE=	${PTHREAD_DISTNAME}.tar.gz
MASTER_SITES+=		ftp://ftp.flame.org/pub/netbsd/
DISTFILES+=		${PTHREAD_DISTFILE}

EXTRACT_ONLY=		${GCC_WIN32_PATCHBUNDLE} ${SSP_PATCH} ${PTHREAD_DISTFILE}

post-extract:
	cd ${WRKDIR} && ${PAX} -rz -s /${GCC_DISTNAME}/toolchain/ \
		-f ${_DISTDIR}/${GCC_DISTNAME}.tar.gz
	${PATCH} -d ${WRKSRC} -p1 --forward --quiet -E < ${GCC_WIN32_PATCH}
	cd ${WRKDIR} && ${PAX} -rz -s /${BINUTILS_DISTNAME}/toolchain/ \
		-f ${_DISTDIR}/${BINUTILS_DISTNAME}.tar.bz2

post-patch:
	for i in patches/binutils-*; do \
		${PATCH} -d ${WRKSRC} --forward --quiet -E < $$i; \
	done
	cd ${WRKSRC}/gcc && ${LOCALBASE}/bin/autoconf
	cd ${WRKSRC}/gcc && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread.h . && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread .
	${CP} ${WRKDIR}/protector.c ${WRKDIR}/protector.h ${WRKSRC}/gcc/
	${PATCH} -d ${WRKSRC} --forward --quiet -E < ${WRKDIR}/protector.dif
#	${PATCH} -d ${WRKSRC} --forward --quiet -E < ${WRKDIR}/protectonly.dif

CFLAGS_FOR_TARGET+=	-I${WRKDIR}
post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${CROSS_SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${CROSS_SYS_INCLUDE}/
	${SED} "s/^extern FILE/__declspec(dllimport) FILE/" /usr/include/stdio.h > ${WRKDIR}/stdio.h

#.include "../COMMON/cross.mk"
.include "files/cross.mk"
