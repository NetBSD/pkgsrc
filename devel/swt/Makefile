# $NetBSD: Makefile,v 1.49 2018/11/12 03:51:55 ryoon Exp $
#

SWTREL=		3.5.1
SWTVER=		3555
SWTDATE=	200909170800

PKGNAME=	swt-${SWTREL}.${SWTVER}
DISTNAME=	swt-${SWTREL}-gtk-linux-x86
PKGREVISION=	40
CATEGORIES=	devel
MASTER_SITES=	http://download.eclipse.org/eclipse/downloads/drops/R-${SWTREL}-${SWTDATE}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/swt/
COMMENT=	Open source widget toolkit for Java
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
USE_JAVA2=	yes

BUILD_DEPENDS+=	apache-ant>=1.7.1:../../devel/apache-ant

BUILD_TARGETS=	all make_awt make_cairo make_xulrunner
BUILD_LIBS=	swt-atk-gtk swt-awt-gtk swt-cairo-gtk swt-glx-gtk \
		swt-gnome-gtk swt-gtk swt-pi-gtk swt-xulrunner-gtk

PLIST_SUBST+=	SWTVER=${SWTVER}

INSTALLATION_DIRS+=	share/java
INSTALLATION_DIRS+=	lib/jni

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
MY_LOWER_ARCH=	amd64
.endif
MY_LOWER_ARCH?=	${MACHINE_ARCH}

post-extract:
	cd ${WRKSRC} && jar -xf ${WRKSRC}/src.zip
	cp ${FILESDIR}/make_pkgsrc.mak ${WRKSRC}

MAKE_FILE=	make_pkgsrc.mak
BUILD_TARGET=	${BUILD_TARGETS}

BUILDLINK_PASSTHRU_RPATHDIRS+=	${PKG_JAVA_HOME}/jre/lib/${MY_LOWER_ARCH}

MAKE_FLAGS+=	JAVA_HOME=${PKG_JAVA_HOME} \
	    LOWER_OPSYS=${LOWER_OPSYS} \
	    LOWER_ARCH=${MY_LOWER_ARCH}

post-build:
	${TEST} -d ${WRKSRC}/bin || mkdir ${WRKSRC}/bin
	cd ${WRKSRC} && find org/eclipse/swt -type f -name \*.java | \
	    xargs ${JAVA_BINPREFIX}-javac -source 1.4 -target 1.4 -d bin
	cd ${WRKSRC}/bin && ${JAVA_BINPREFIX}-jar -cf ${WRKSRC}/swt.jar .

do-install:
	${INSTALL_DATA} ${WRKSRC}/swt.jar \
	    ${DESTDIR}${PREFIX}/share/java/swt.jar
.for libname in ${BUILD_LIBS}
	${INSTALL_LIB} ${WRKSRC}/lib${libname}-${SWTVER}.so \
	    ${DESTDIR}${PREFIX}/lib/jni/lib${libname}-${SWTVER}.so
.endfor

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/xulrunner192/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt+=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
