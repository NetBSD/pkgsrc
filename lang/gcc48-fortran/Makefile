# $NetBSD: Makefile,v 1.1 2014/04/22 20:46:41 ryoon Exp $

PKGNAME=	${GCC_PKGNAME}-fortran-${GCC48_DIST_VERSION}

COMMENT=	Fortran 95/2003/2008 compiler from the GNU Compiler Collection (GCC) 4.8

DISTINFO_FILE=		${.CURDIR}/../../lang/gcc48/distinfo
PATCHDIR=		${.CURDIR}/../../lang/gcc48/patches

DEPENDS+=		 ${GCC_PKGNAME}-libs-${GCC48_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc48-libs

# c,c++ are specified by default.
LANGS+=			fortran

.include "../../lang/gcc48/options.mk"

.include "../../lang/gcc48/Makefile.common"

post-install:
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin/*c++*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin/*cpp*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin/*gcc*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin/*g++
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin/gcov
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/include
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/cc1*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/collect2
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/install-tools
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/install-tools
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include-fixed
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/plugin
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/libgc*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/*lto*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/plugin
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libatomic.*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgc*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgfortran.*a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgfortran.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgomp*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libiberty*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libitm*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libs*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/info
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/man
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/share

	cd ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin && \
		${LN} -sf gfortran f77 && \
		${LN} -sf gfortran g77 && \
		${LN} -sf gfortran g95
