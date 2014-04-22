# $NetBSD: Makefile,v 1.1 2014/04/22 20:46:41 ryoon Exp $

PKGNAME=	${GCC_PKGNAME}-objc-${GCC48_DIST_VERSION}

COMMENT=	Objective C/Objective C++ compiler from the GNU Compiler Collection (GCC) 4.8

DISTINFO_FILE=		${.CURDIR}/../../lang/gcc48/distinfo
PATCHDIR=		${.CURDIR}/../../lang/gcc48/patches

DEPENDS+=		 ${GCC_PKGNAME}-libs-${GCC48_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc48-libs
DEPENDS+=		 ${GCC_PKGNAME}-cc++-${GCC48_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc48-cc++

.include "../../lang/gcc48/options.mk"

.include "../../lang/gcc48/c++.mk"

.include "../../lang/gcc48/Makefile.common"

post-install:
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/lib*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/lib*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/finclude
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include-fixed
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/install-tools
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include/*.h
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/lib*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include/ssp
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/plugin
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/include
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/info
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/man
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/share
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/cc1
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/cc1plus
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/collect2
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/install-tools
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/liblto_plugin.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/lto*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/lib*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/plugin
