# $NetBSD: Makefile,v 1.2 2001/01/30 03:08:56 minoura Exp $
#

DISTVERSION=		1.1.2
DISTFILES=		# none

MAINTAINER=		peace-sacrifice@hauN.org
HOMEPAGE=		http://chiharu.hauN.org/peace/

WRKSRC=			${WRKDIR}/${GCC_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_GCC=		yes
GCC_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdpe
GCC_CONFIGURE_ARGS+=	--enable-threads

BINUTILS_EXTRAS=	dlltool windres

GCC_WIN32_PATCHBUNDLE=	${GCC_DISTNAME}-x86-win32-patches.tar.gz
GCC_WIN32_PATCH=	${WRKDIR}/${GCC_DISTNAME}-patches/${GCC_DISTNAME}-x86-win32.diff
MASTER_SITES+=		ftp://ftp.xraylith.wisc.edu/pub/khan/gnu-win32/mingw32/${GCC_DISTNAME}/patches/
CROSS_DISTFILES+=	${GCC_WIN32_PATCHBUNDLE}

PTHREAD_DISTNAME=	unproven-pthreads-0.17
PTHREAD_DISTFILE=	${PTHREAD_DISTNAME}.tar.gz
MASTER_SITES+=		ftp://ftp.flame.org/pub/netbsd/

pre-patch: gcc-patchbundle

gcc-patchbundle:
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${GCC_WIN32_PATCHBUNDLE}
	${PATCH} -d ${WRKDIR} --forward --quiet -E < ${GCC_WIN32_PATCH}

post-patch:
	for i in patches/binutils-*; do \
		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
	done
	cd ${BINUTILS_WRKSRC}/bfd && autoconf
	cd ${BINUTILS_WRKSRC}/gas && autoconf
	cd ${WRKDIR}/${GCC_DISTNAME}/gcc && autoconf
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${PTHREAD_DISTFILE}
	cd ${WRKDIR}/${GCC_DISTNAME}/gcc && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread.h . && \
		${LN} -s ../../${PTHREAD_DISTNAME}/include/pthread .


post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${SYS_INCLUDE}/
	${RM} ${WRKDIR}/${GCC_DISTNAME}/texinfo/makeinfo/Makefile

#.include "../COMMON/cross.mk"
.include "files/cross.mk"
