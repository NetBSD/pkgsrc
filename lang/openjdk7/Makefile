# $NetBSD: Makefile,v 1.17 2010/02/11 09:44:26 tnn Exp $

DISTNAME=	openjdk-7-ea-src-b78-17_dec_2009
PKGNAME=	openjdk7-1.7.0.78.20100102
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL:=openjdk7/}
EXTRACT_SUFX=	.tar.bz2

OWNER=		tnn@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/
COMMENT=	Open-source implementation of the Java Platform, Standard Edition

PKG_DESTDIR_SUPPORT=	user-destdir

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# diff between distfile and bsd-port branch. To check out, use:
# "hg fclone http://hg.openjdk.java.net/bsd-port/bsd-port/"
PATCHFILES+=	jdk-7-bsd-port-78.20100102.diff.bz2
PATCH_SITES+=	${MASTER_SITE_LOCAL:=openjdk7/}

CACERTS=	cacerts-20091013.tar.bz2
DISTFILES+=	${CACERTS}
EXTRACT_ONLY+=	${CACERTS}

JAVA_NAME=	openjdk7
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	jar java javac javadoc javah javap keytool orbd \
		policytool rmid rmiregistry servertool tnameserv

BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
MAKE_ENV+=		PKGSRC_ZIPEXE=${PREFIX}/bin/zip
MAKE_ENV+=		PKGSRC_UNZIP=${PREFIX}/bin/unzip
MAKE_ENV+=		PKGSRC_UNZIPSFX=${PREFIX}/bin/unzipsfv

DEPENDS+=		dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
#DEPENDS+=		ja-sazanami-ttf-[0-9]*:../../fonts/ja-sazanami-ttf
#DEPENDS+=		baekmuk-ttf-[0-9]*:../../fonts/baekmuk-ttf

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax
UNLIMIT_RESOURCES=	datasize stacksize
WRKSRC=			${WRKDIR}/openjdk

BUILDLINK_PASSTHRU_DIRS+=	${ALT_BOOTDIR}
PREPEND_PATH+=			${ALT_BOOTDIR}/bin

MAKE_ENV+=	ALT_BOOTDIR=${ALT_BOOTDIR}
MAKE_ENV+=	ALT_FREETYPE_LIB_PATH=${BUILDLINK_PREFIX.freetype2}/lib
MAKE_ENV+=	ALT_FREETYPE_HEADERS_PATH=${BUILDLINK_PREFIX.freetype2}/include
MAKE_ENV+=	ALT_CUPS_HEADERS_PATH=${BUILDLINK_PREFIX.cups}/include
MAKE_ENV+=	ALT_COMPILER_PATH=${WRAPPER_DIR}/bin
MAKE_ENV+=	ALT_PACKAGE_PATH=${PREFIX}
MAKE_ENV+=	ALT_X11_PATH=${X11BASE}

MAKE_ENV+=	ALT_PARALLEL_COMPILE_JOBS=${MAKE_JOBS:U1}

MAKE_ENV+=	HOTSPOT_BUILD_USER=pkgsrc
MAKE_ENV+=	NO_DOCS=true
MAKE_ENV+=	SKIP_COMPARE_IMAGES=true
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=yes
MAKE_ENV+=	SKIP_DEBUG_BUILD=yes

MAKE_ENV+=	EXTRA_CFLAGS="-DDEFAULT_LIBPATH=\\\"${PREFIX}/lib/jni:${PREFIX}/lib:/lib:/usr/lib\\\""

BUILDDIR=	${WRKSRC}/build/${OPSYS:C/.*BSD/bsd/:S/DragonFly/bsd/}-${MACHINE_ARCH:S/i386/i586/:S/x86_64/amd64/}
PLIST_SUBST+=	ARCH=${MACHINE_ARCH:S/x86_64/amd64/}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS}

.include "../../mk/bsd.prefs.mk"
.include "bootstrap.mk"
.include "icedtea-extras.mk"

SUBST_CLASSES+=			add-rpaths
SUBST_STAGE.add-rpaths=		pre-build
SUBST_MESSAGE.add-rpaths=	adding X11 run path flags to Makefiles
SUBST_FILES.add-rpaths=		jdk/make/sun/awt/Makefile		\
				jdk/make/sun/awt/mawt.gmk		\
				jdk/make/sun/jawt/Makefile		\
				jdk/make/sun/jdga/Makefile		\
				jdk/make/sun/splashscreen/Makefile	\
				jdk/make/sun/xawt/Makefile
SUBST_SED.add-rpaths=		-e 's|-L$$(OPENWIN_LIB)|-L$$(OPENWIN_LIB) -Wl,-R$$(OPENWIN_LIB)|g'

SUBST_CLASSES+=			fontpaths
SUBST_STAGE.fontpaths=		pre-build
SUBST_MESSAGE.fontpaths=	fixing font paths
SUBST_FILES.fontpaths=		jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
SUBST_FILES.fontpaths+=		jdk/src/solaris/native/sun/awt/fontpath.c
SUBST_SED.fontpaths=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.fontpaths+=		-e 's|@BUILDLINK_PREFIX.fontconfig@|${BUILDLINK_PREFIX.fontconfig}|g'

PLIST_VARS+=	i386
.if ${MACHINE_ARCH} == "i386"
PLIST.i386=	yes
.endif

post-extract:
	chmod +x ${ANT_BIN}/ant
	cd ${WRKDIR}/${ICEDTEA}/plugin/icedteanp/java && pax -rw . \
	  ${WRKSRC}/jdk/src/share/classes
	cd ${WRKDIR}/${ICEDTEA}/netx && pax -rw . \
	  ${WRKSRC}/jdk/src/share/classes

do-build: ${WRKDIR}/stage3-done

# stage 1 builds a native JDK using the bootstrap binaries
${WRKDIR}/stage1-done:
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	rm -rf ${WRKDIR}/bootstrap
	cd ${BUILDDIR} && mv j2sdk-image ${WRKDIR}/bootstrap
	rm -rf ${BUILDDIR}
	touch ${WRKDIR}/stage1-done

# stage 2 rebuilds the JDK using native tools
${WRKDIR}/stage2-done: ${WRKDIR}/stage1-done
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	touch ${BUILDDIR}/j2sdk-image/jre/lib/applet/.keep
	touch ${WRKDIR}/stage2-done

# stage 3 builds third party add-ons
${WRKDIR}/stage3-done: ${WRKDIR}/stage2-done ${WRKDIR}/cacerts.out
	touch ${WRKDIR}/stage3-done

${WRKDIR}/cacerts.out:
	for cert in ${WRKDIR}/cacerts/*.crt; do			\
		${ECHO} yes | LC_ALL=C ${BUILDDIR}/bin/keytool		\
		  -importcert						\
		  -keystore ${.TARGET}					\
		  -alias `${ECHO} $$cert | sed 's,.*/\\([^/]*\\)\\.crt,\\1,'` \
		  -file $$cert						\
		  -storepass pkgsrc;					\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${BUILDDIR}/j2sdk-image && pax -rwpp .			\
	  ${DESTDIR}${JAVA_HOME}/.
	${INSTALL_DATA} ${WRKDIR}/cacerts.out				\
	  ${DESTDIR}${JAVA_HOME}/jre/lib/security/cacerts
	rm -f ${DESTDIR}${JAVA_HOME}/include/jni_md.h
	ln -s ${LOWER_OPSYS}/jni_md.h					\
	  ${DESTDIR}${JAVA_HOME}/include/jni_md.h

.if !empty(MACHINE_PLATFORM:MNetBSD-4.*-*)
MAKE_ENV+=	PTHREAD_STACKSIZE=1024
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_DEPMETHOD.cups?=	build
.include "../../print/cups/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXp?=	build
.include "../../x11/libXp/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
