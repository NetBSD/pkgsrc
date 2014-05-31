# $NetBSD: Makefile,v 1.2 2014/05/31 13:06:25 ryoon Exp $

PKGNAME=	${GCC_PKGNAME}-cc++-${GCC48_DIST_VERSION}

COMMENT=	C/C++ compilers from the GNU Compiler Collection (GCC) 4.8

DISTINFO_FILE=		${.CURDIR}/../../lang/gcc48/distinfo
PATCHDIR=		${.CURDIR}/../../lang/gcc48/patches

DEPENDS+=		 ${GCC_PKGNAME}-libs-${GCC48_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc48-libs

.include "../../lang/gcc48/options.mk"

.include "../../lang/gcc48/c++.mk"

.include "../../lang/gcc48/Makefile.common"

post-install:
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libatomic.a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libatomic.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libatomic.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgcc_s.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgomp.a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgomp.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libgomp.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libitm.a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libitm.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libitm.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libssp.a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libquadmath*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libssp.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libssp.so*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libstdc++.a
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libstdc++.la
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libstdc++.so
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libstdc++.so.6
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libstdc++.so.6.19
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/libobjc.*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/*lto*
	rm -f ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/cc1obj*
	rm -rf ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}/include/objc
	cd ${DESTDIR}${PREFIX}/${GCC_PKGNAME}/bin && \
		${LN} -sf gcc cc
