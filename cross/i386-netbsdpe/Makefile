# $NetBSD: Makefile,v 1.9 2002/03/18 03:04:40 kent Exp $
# $PEACE: Makefile,v 1.18 2001/12/05 07:13:57 kent Exp $

DISTVERSION=		1.3.0
CROSS_DISTFILES=		# none

MAINTAINER=		peace-sacrifice@hauN.org
HOMEPAGE=		http://chiharu.hauN.org/peace/
COMMENT=		Cross-compile environment for PEACE/i386

WRKSRC=			${WRKDIR}/${GCC_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_GCC=		yes
GCC_FAKE_RUNTIME=	yes
GCC_CXX=		yes
#GCC_F77=		yes
#GCC_OBJC=		yes
#GCC_CXX_RUNTIME=	yes
#GCC_F77_RUNTIME=	yes
#GCC_OBJC_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdpe
GCC_CONFIGURE_ARGS+=	--enable-threads

BINUTILS_EXTRAS=	dlltool windres

# Mingw pathes
GCC_WIN32_PATCHBUNDLE=	${GCC_DISTNAME}-x86-win32-patches.tar.gz
GCC_WIN32_PATCH=	${WRKDIR}/${GCC_DISTNAME}-patches/${GCC_DISTNAME}-x86-win32.diff
MASTER_SITES+=		ftp://ftp.xraylith.wisc.edu/pub/khan/gnu-win32/mingw32/${GCC_DISTNAME}/patches/
CROSS_DISTFILES+=	${GCC_WIN32_PATCHBUNDLE}

# SSP patch
MASTER_SITES+=		http://www.trl.ibm.com/projects/security/ssp/gcc2_95_2/
SSP_PATCH=		protector-2.95.2-2.tar.gz
CROSS_DISTFILES+=	${SSP_PATCH}

# pthread
PTHREAD_DISTNAME=	unproven-pthreads-0.17
PTHREAD_DISTFILE=	${PTHREAD_DISTNAME}.tar.gz
MASTER_SITES+=		ftp://ftp.flame.org/pub/netbsd/
CROSS_DISTFILES+=	${PTHREAD_DISTFILE}

pre-patch: gcc-patchbundle

gcc-patchbundle:
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${GCC_WIN32_PATCHBUNDLE}
	${PATCH} -d ${WRKDIR} --forward --quiet -E < ${GCC_WIN32_PATCH}

post-patch:
	for i in patches/binutils-*; do \
		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
	done
	cd ${BINUTILS_WRKSRC}/bfd && ${LOCALBASE}/bin/autoconf
	cd ${BINUTILS_WRKSRC}/gas && ${LOCALBASE}/bin/autoconf
	cd ${WRKDIR}/${GCC_DISTNAME}/gcc && ${LOCALBASE}/bin/autoconf
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${PTHREAD_DISTFILE}
	cd ${WRKDIR}/${GCC_DISTNAME}/gcc && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread.h . && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread .
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${SSP_PATCH}
	${CP} ${WRKDIR}/protector.c ${WRKDIR}/protector.h ${WRKDIR}/${GCC_DISTNAME}/gcc/
	${PATCH} -d ${WRKDIR}/${GCC_DISTNAME} --forward --quiet -E < ${WRKDIR}/protector.dif
#	${PATCH} -d ${WRKDIR}/${GCC_DISTNAME} --forward --quiet -E < ${WRKDIR}/protectonly.dif

CFLAGS_FOR_TARGET+=	-I${WRKDIR}
post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${CROSS_SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${CROSS_SYS_INCLUDE}/
	${RM} ${WRKDIR}/${GCC_DISTNAME}/texinfo/makeinfo/Makefile
	${SED} "s/extern FILE/__declspec(dllimport) FILE/" /usr/include/stdio.h > ${WRKDIR}/stdio.h

#.include "../COMMON/cross.mk"
.include "files/cross.mk"
