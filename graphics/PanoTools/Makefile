# $NetBSD: Makefile,v 1.2 2003/04/19 08:03:09 rh Exp $
#

DISTNAME=		PanoTools
PKGNAME=		${DISTNAME}-2.6b1
WRKSRC=			${WRKDIR}/PTLinux
CATEGORIES=		graphics
MASTER_SITES=		http://www.path.unimelb.edu.au/~dersch/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.path.unimelb.edu.au/~dersch/
COMMENT=		view, create, edit, and remap panoramic images

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

USE_BUILDLINK2=		YES
USE_X11=		YES
NO_BUILD=		YES

.include "../../mk/bsd.prefs.mk"

PKG_JVM?=		sun-jdk
PLIST_SUBST+=		JAVA_HOME="${PKG_JAVA_HOME:C/^${PREFIX}\///}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpano12.so				\
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

.include "../../emulators/suse_linux/Makefile.application"

.if ${OPSYS} == NetBSD
DEPENDS+=		suse_base>=SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=		suse_libjpeg>=SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=		suse_libpng>=SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=		suse_libtiff>=SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_libtiff
.endif

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
