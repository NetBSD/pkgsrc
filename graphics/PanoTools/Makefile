# $NetBSD: Makefile,v 1.21 2008/03/04 15:39:09 jlam Exp $
#

DISTNAME=		PanoTools
PKGNAME=		${DISTNAME}-2.6b1
PKGREVISION=		3
CATEGORIES=		graphics java
MASTER_SITES=		http://www.path.unimelb.edu.au/~dersch/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.path.unimelb.edu.au/~dersch/
COMMENT=		View, create, edit, and remap panoramic images

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base jpeg png tiff

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/PTLinux
BUILD_DIRS=		# empty
USE_JAVA=		run

PKG_JVM?=		sun-jdk
PLIST_SUBST+=		JAVA_HOME="${PKG_JAVA_HOME:C/^${PREFIX}\///}"

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpano12.so ${DESTDIR}${EMULDIR}/lib
	${INSTALL_LIB_DIR} ${DESTDIR}${PKG_JAVA_HOME}/lib/${MACHINE_ARCH}
	${LN} -s ${EMULDIR}/lib/libpano12.so				\
		${DESTDIR}${PKG_JAVA_HOME}/lib/${MACHINE_ARCH}/libpano12.lib.so
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/PanoTools
.for jar in ptcrypt pteditor ptpicker
	${INSTALL_DATA} ${WRKSRC}/${jar}.jar				\
		${DESTDIR}${PREFIX}/share/PanoTools
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/PanoTools
.for doc in Readme.html Readme.txt Copyright/COPYRIGHT_TIFF		\
	Copyright/Copying.html Copyright/README_JPEG			\
	Scripts/Optimizer_Script.txt Scripts/Stitcher_Script.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/PanoTools
.endfor
.for bin in ptcrypt pteditor ptpicker
	${SED} < ${FILESDIR}/ptfile.sh > ${WRKDIR}/${bin}		\
		-e 's|@@prefix@@|${PREFIX}|g'				\
		-e 's|@@javahome@@|${PKG_JAVA_HOME}|g'			\
		-e 's|@@ptfile@@|${bin}|g'
	${INSTALL_SCRIPT} ${WRKDIR}/${bin} ${DESTDIR}${PREFIX}/bin
.endfor
	${SED} < ${FILESDIR}/mkpthelpers.sh > ${WRKDIR}/mkpthelpers	\
		-e 's|@@prefix@@|${PREFIX}|g'				\
		-e 's|@@javahome@@|${PKG_JAVA_HOME}|g'			\
		-e 's|@@ptfile@@|${bin}|g'
	${INSTALL_SCRIPT} ${WRKDIR}/mkpthelpers ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec/PanoTools
.for bin in PTAverage PTInterpolate PTMorpher PTOptimizer PTStereo	\
	PTStitcher PTStripe
	${INSTALL_SCRIPT} ${WRKSRC}/Helpers/${bin}			\
		${DESTDIR}${PREFIX}/libexec/PanoTools
	[ ! -f ${WRKSRC}/Helpers/${bin}.txt ] ||			\
	${INSTALL_DATA} ${WRKSRC}/Helpers/${bin}.txt			\
		${DESTDIR}${PREFIX}/share/doc/PanoTools
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/PanoTools/Templates
.for hlp in 3DMF_HEADER 3DMF_TRIMESH INDEXED_FACE_FMT LP_ivr		\
	LPjava_html LPjava_ivr VRML_HEADER vrml_wrl
	${INSTALL_DATA} ${WRKSRC}/Helpers/Templates/${hlp}		\
		${DESTDIR}${PREFIX}/share/PanoTools/Templates
.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
