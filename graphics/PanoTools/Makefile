# $NetBSD: Makefile,v 1.15 2005/06/16 06:57:57 jlam Exp $
#

DISTNAME=		PanoTools
PKGNAME=		${DISTNAME}-2.6b1
PKGREVISION=		1
CATEGORIES=		graphics java
MASTER_SITES=		http://www.path.unimelb.edu.au/~dersch/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.path.unimelb.edu.au/~dersch/
COMMENT=		View, create, edit, and remap panoramic images

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

WRKSRC=			${WRKDIR}/PTLinux
USE_JAVA=		run
NO_BUILD=		YES

.include "../../mk/bsd.prefs.mk"

PKG_JVM?=		sun-jdk
PLIST_SUBST+=		JAVA_HOME="${PKG_JAVA_HOME:C/^${PREFIX}\///}"
INSTALLATION_DIRS=	bin lib

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpano12.so ${EMULDIR}/lib
	${LN} -s ${EMULDIR}/lib/libpano12.so				\
		${PKG_JAVA_HOME}/lib/${MACHINE_ARCH}/libpano12.lib.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/PanoTools
.for jar in ptcrypt pteditor ptpicker
	${INSTALL_DATA} ${WRKSRC}/${jar}.jar ${PREFIX}/share/PanoTools
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/PanoTools
.for doc in Readme.html Readme.txt Copyright/COPYRIGHT_TIFF		\
	Copyright/Copying.html Copyright/README_JPEG			\
	Scripts/Optimizer_Script.txt Scripts/Stitcher_Script.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/PanoTools
.endfor
.for bin in ptcrypt pteditor ptpicker
	${SED} < ${FILESDIR}/ptfile.sh > ${WRKDIR}/${bin}		\
		-e 's|@@prefix@@|${PREFIX}|g'				\
		-e 's|@@javahome@@|${PKG_JAVA_HOME}|g'			\
		-e 's|@@ptfile@@|${bin}|g'
	${INSTALL_SCRIPT} ${WRKDIR}/${bin} ${PREFIX}/bin
.endfor
	${SED} < ${FILESDIR}/mkpthelpers.sh > ${WRKDIR}/mkpthelpers	\
		-e 's|@@prefix@@|${PREFIX}|g'				\
		-e 's|@@javahome@@|${PKG_JAVA_HOME}|g'			\
		-e 's|@@ptfile@@|${bin}|g'
	${INSTALL_SCRIPT} ${WRKDIR}/mkpthelpers ${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/PanoTools
.for bin in PTAverage PTInterpolate PTMorpher PTOptimizer PTStereo	\
	PTStitcher PTStripe
	${INSTALL_SCRIPT} ${WRKSRC}/Helpers/${bin} ${PREFIX}/libexec/PanoTools
	[ ! -f ${WRKSRC}/Helpers/${bin}.txt ] ||			\
	${INSTALL_DATA} ${WRKSRC}/Helpers/${bin}.txt			\
		${PREFIX}/share/doc/PanoTools
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/PanoTools/Templates
.for hlp in 3DMF_HEADER 3DMF_TRIMESH INDEXED_FACE_FMT LP_ivr		\
	LPjava_html LPjava_ivr VRML_HEADER vrml_wrl
	${INSTALL_DATA} ${WRKSRC}/Helpers/Templates/${hlp}		\
		${PREFIX}/share/PanoTools/Templates
.endfor

.include "../../emulators/suse_linux/Makefile.application"

.if ${OPSYS} == NetBSD && ${SUSE_VERSION} != "6.4"
DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=		suse_libjpeg>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=		suse_libpng>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=		suse_libtiff>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libtiff

EMULSUBDIR=		emul/linux
LDD=			${EMULDIR}/usr/bin/ldd
.else
EMULSUBDIR=
.endif

EMULDIR=		${PREFIX}/${EMULSUBDIR}
PLIST_SUBST+=		EMULSUBDIR="${EMULSUBDIR}"

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
