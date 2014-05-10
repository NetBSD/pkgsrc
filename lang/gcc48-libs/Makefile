# $NetBSD: Makefile,v 1.13 2014/05/10 14:14:59 richard Exp $

PKGNAME=	${GCC_PKGNAME}-libs-${GCC48_DIST_VERSION}
PKGREVISION=	5

COMMENT=	Runtime libraries from the GNU Compiler Collection (GCC) 4.8

DISTINFO_FILE=		${.CURDIR}/../../lang/gcc48/distinfo
PATCHDIR=		${.CURDIR}/../../lang/gcc48/patches

LANGS=			fortran

.include "../../lang/gcc48/options.mk"

.include "../../lang/gcc48/c++.mk"

INSTALLATION_DIRS=	${GCC_PKGNAME}/lib \
			${GCC_PKGNAME}/lib/gcj-${GCC48_DIST_VERSION}-14 \
			${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}

.if !empty(PKG_OPTIONS:Mgcc-java)
INSTALLATION_DIRS+=	java/${GCC_PKGNAME}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/client \
			java/${GCC_PKGNAME}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/server
.endif

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libatomic/libatomic.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

# libgcc_s has no libtool la file.
	${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libgcc/libgcc_s.so* \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libgfortran/libgfortran.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libgomp/libgomp.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libitm/libitm.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libobjc/libobjc.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libstdc++-v3/src/libstdc++.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libssp/libssp.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/lto-plugin/liblto_plugin.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}

	${INSTALL_PROGRAM} ${WRKSRC}/${OBJDIR}/gcc/lto1 \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}

	${INSTALL_PROGRAM} ${WRKSRC}/${OBJDIR}/gcc/lto-wrapper \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/libexec/gcc/${MACHINE_GNU_PLATFORM}/${GCC48_DIST_VERSION}

.if !empty(PKG_OPTIONS:Mgcc-java)
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libjava/libjvm.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib/gcj-${GCC48_DIST_VERSION}-14

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libjava/libgcj.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libjava/libgij.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${OBJDIR}/${MACHINE_GNU_PLATFORM}/libjava/libgcj-tools.la \
		${DESTDIR}${PREFIX}/${GCC_PKGNAME}/lib

	cd ${DESTDIR}${PREFIX}/java/${GCC_PKGNAME}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/client && \
		${LN} -sf ../../../../../../${GCC_PKGNAME}/lib/gcj-${GCC48_DIST_VERSION}-14/libjvm.so .

	cd ${DESTDIR}${PREFIX}/java/${GCC_PKGNAME}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/server && \
		${LN} -sf ../../../../../../${GCC_PKGNAME}/lib/gcj-${GCC48_DIST_VERSION}-14/libjvm.so .
.endif

.include	"../../lang/gcc48/Makefile.common"
