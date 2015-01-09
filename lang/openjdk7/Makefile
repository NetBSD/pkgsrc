# $NetBSD: Makefile,v 1.82 2015/01/09 16:29:04 rumko Exp $

DISTNAME=	openjdk-1.7.71-20141102
PKGNAME=	openjdk7-1.7.71
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL:=openjdk7/}
EXTRACT_SUFX=	.tar.bz2

# Note: Remember to set sun-jre-jce when updating distinfo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/
COMMENT=	Open-source implementation of the Java Platform, Standard Edition
LICENSE=	gnu-gpl-v2

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# diff between distfile and bsd-port branch. To check out, use:
# "hg fclone http://hg.openjdk.java.net/bsd-port/bsd-port/"
#PATCH_DIST_STRIP=	-p1
#PATCHFILES+=	jdk-7u21-20130526.diff
#PATCH_SITES+=	${MASTER_SITE_LOCAL:=openjdk7/}
PATCH_DIST_STRIP=	-p1
PATCHFILES+=	patches-74a70385c21d
PATCH_SITES+=	${MASTER_SITE_LOCAL:=openjdk7/}


CACERTS=	cacerts-20091013.tar.bz2
DISTFILES+=	${CACERTS}
EXTRACT_ONLY+=	${CACERTS}

JAVA_NAME=	openjdk7
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	jar java javac javadoc javah javap keytool orbd \
		policytool rmid rmiregistry servertool tnameserv

MAKE_ENV+=		PKGSRC_ZIPEXE=${TOOLS_PATH.zip}
MAKE_ENV+=		PKGSRC_UNZIP=${TOOLS_PATH.unzip}
MAKE_ENV+=		PKGSRC_UNZIPSFX=${TOOLS_PATH.unzip}sfx

DEPENDS+=		dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
#DEPENDS+=		ja-sazanami-ttf-[0-9]*:../../fonts/ja-sazanami-ttf
#DEPENDS+=		baekmuk-ttf-[0-9]*:../../fonts/baekmuk-ttf

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax unzip:run zip:run # patch
UNLIMIT_RESOURCES=	datasize stacksize
WRKSRC=			${WRKDIR}/openjdk

BUILDLINK_PASSTHRU_DIRS+=	${ALT_BOOTDIR}
PREPEND_PATH+=			${ALT_BOOTDIR}/bin

MAKE_ENV+=	ALT_BOOTDIR=${ALT_BOOTDIR}
MAKE_ENV+=	ALT_DROPS_DIR=${DISTDIR}/${DIST_SUBDIR}
MAKE_ENV+=	ALT_FREETYPE_LIB_PATH=${BUILDLINK_PREFIX.freetype2}/lib
MAKE_ENV+=	ALT_FREETYPE_HEADERS_PATH=${BUILDLINK_PREFIX.freetype2}/include
MAKE_ENV+=	ALT_CUPS_HEADERS_PATH=${BUILDLINK_PREFIX.cups}/include
MAKE_ENV+=	ALT_COMPILER_PATH=${WRAPPER_DIR}/bin
MAKE_ENV+=	ALT_PACKAGE_PATH=${PREFIX}
MAKE_ENV+=	ALT_X11_PATH=${X11BASE}
MAKE_ENV+=	RHINO_JAR=${WRKDIR}/${RHINO}/js.jar

MAKE_ENV+=	ALT_PARALLEL_COMPILE_JOBS=${MAKE_JOBS:U1}
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${MAKE_JOBS}

MAKE_ENV+=	HOTSPOT_BUILD_USER=pkgsrc
MAKE_ENV+=	NO_DOCS=true
MAKE_ENV+=	SKIP_COMPARE_IMAGES=true
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=yes
MAKE_ENV+=	SKIP_DEBUG_BUILD=yes

# Avoid build errors when JAVA_HOME and CLASSPATH are defined by user.
MAKE_ENV+=	JAVA_HOME=
MAKE_ENV+=	CLASSPATH=

MAKE_ENV+=	EXTRA_CFLAGS="-DDEFAULT_LIBPATH=\\\"${PREFIX}/lib/jni:${PREFIX}/lib:/lib:/usr/lib\\\""
BUILDDIR=	${WRKSRC}/build/${OPSYS:C/.*BSD/bsd/:S/DragonFly/bsd/:S/SunOS/solaris/}-${MACHINE_ARCH:S/i386/i586/:S/x86_64/amd64/}
LD_LIBRARY_PATH=	${BUILDDIR}/lib/${MACHINE_ARCH:S/x86_64/amd64/}:${BUILDDIR}/lib/${MACHINE_ARCH:S/x86_64/amd64/}/jli:${BUILDDIR}/lib/${MACHINE_ARCH:S/x86_64/amd64/}/server:${WRKDIR}/bootstrap/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}:${WRKDIR}/bootstrap/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/jli:${WRKDIR}/bootstrap/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}/server
MAKE_ENV+=	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/java/openjdk7/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}

PLIST_SUBST+=	ARCH=${MACHINE_ARCH:S/x86_64/amd64/}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS}

.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV+=	USE_GCC=1
MAKE_ENV+=	ARCH_DATA_MODEL=${ABI:Q}
.endif

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-build
SUBST_FILES.libpath+=	hotspot/src/os/bsd/vm/os_bsd.cpp
SUBST_VARS.libpath=	PREFIX

# SmartOS has ccs tools in /usr/bin
.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		ccspath
SUBST_STAGE.ccspath=	pre-build
SUBST_FILES.ccspath=	jdk/make/common/shared/Defs-utils.gmk
SUBST_FILES.ccspath+=	hotspot/make/solaris/makefiles/build_vm_def.sh
SUBST_SED.ccspath=	-e 's/UNIXCCS_PATH/UNIXCOMMAND_PATH/g'
SUBST_SED.ccspath+=	-e 's,/usr/ccs/bin,/usr/bin,g'
.endif

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		mapfix
SUBST_STAGE.mapfix=	pre-build
SUBST_FILES.mapfix=	jdk/make/com/sun/java/pack/mapfile-vers
SUBST_FILES.mapfix+=	jdk/make/java/main/java/mapfile-amd64
SUBST_FILES.mapfix+=	jdk/make/java/main/java/mapfile-i586
SUBST_SED.mapfix=	-e '/__fsr_init_value/d'
SUBST_SED.mapfix+=	-e '/__progname/d'

# environ should only be removed from this file (added by patches)
SUBST_CLASSES+=		mapfix2
SUBST_STAGE.mapfix2=	pre-build
SUBST_FILES.mapfix2=	jdk/make/com/sun/java/pack/mapfile-vers
SUBST_SED.mapfix2=	-e '/environ/d'
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-parentheses -Wno-sign-conversion \
			-Wno-shorten-64-to-32 -Wno-conversion \
			-Wno-unused-value -Wno-switch-enum -Wno-switch \
			-Wno-tautological-compare \
			-Wno-delete-non-virtual-dtor \
			-Wno-return-type -Wno-unused-parameter \
			-Wno-parentheses-equality -Wno-empty-body
CWRAPPERS_APPEND.cxx+=	-Wno-parentheses -Wno-sign-conversion \
			-Wno-shorten-64-to-32 -Wno-conversion \
			-Wno-unused-value -Wno-switch-enum -Wno-switch \
			-Wno-tautological-compare \
			-Wno-delete-non-virtual-dtor \
			-Wno-return-type -Wno-unused-parameter \
			-Wno-parentheses-equality -Wno-empty-body
.if ${OPSYS} != "FreeBSD"
_WRAP_EXTRA_ARGS.CXX+=	-Wno-new-returns-null
CWRAPPERS_APPEND.cxx+=	-Wno-new-returns-null
.endif
BUILDLINK_TRANSFORM+=	rm:-fcheck-new
BUILDLINK_TRANSFORM+=	rm:-fpch-deps
.  if ${MACHINE_ARCH} == "x86_64"
_WRAP_EXTRA_ARGS.CXX+=	-mstackrealign
.  endif
.endif
.include "bootstrap.mk"
.include "icedtea-extras.mk"

.include "options.mk"

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

PLIST_VARS+=	i386 jce manja
.if ${MACHINE_ARCH} == "i386"
PLIST.i386=	yes
.endif
.if ${OPSYS} != "SunOS"
PLIST.manja=	yes
.endif

PLIST_VARS+=	sctp alsa
.if ${OPSYS} == "FreeBSD"
PLIST.sctp=	yes
PLIST.alsa=	yes
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

post-extract:
	chmod +x ${ANT_BIN}/ant
	cd ${WRKDIR}/${ICEDTEA_WEB}/plugin/icedteanp/java && pax -rw . \
	  ${WRKSRC}/jdk/src/share/classes
	cd ${WRKDIR}/${ICEDTEA_WEB}/netx && pax -rw . \
	  ${WRKSRC}/jdk/src/share/classes
#	cd ${WRKSRC} && patch -s -p1 < ${WRKDIR}/${ICEDTEA}/patches/rhino.patch
.if ${OPSYS} == "SunOS"
	${MKDIR} ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/include ${ALT_BOOTDIR}/include
	${LN} -s ${JDK_BOOTDIR}/lib ${ALT_BOOTDIR}/lib
	${LN} -s ${JDK_BOOTDIR}/bin/java ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/javac ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/javah ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/javap ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/idlj ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/jar ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/native2ascii ${ALT_BOOTDIR}/bin
	${LN} -s ${JDK_BOOTDIR}/bin/rmic ${ALT_BOOTDIR}/bin
.elif ${OPSYS} == "NetBSD" && exists(${.CURDIR}/libs)
	cp ${.CURDIR}/libs/lib* ${ALT_BOOTDIR}/jre/lib/${MACHINE_ARCH:S/x86_64/amd64/}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
ALL_ENV+=	LDFLAGS_LIBGCC=-lgcc_s
.endif

do-build: ${WRKDIR}/stage3-done

# stage 1 builds a native JDK using the bootstrap binaries
${WRKDIR}/stage1-done:
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	rm -rf ${ALT_BOOTDIR}
	cd ${BUILDDIR} && mv j2sdk-image ${ALT_BOOTDIR}
	mv ${BUILDDIR} ${BUILDDIR}-stage1
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
		${ECHO} yes | LD_LIBRARY_PATH=${LD_LIBRARY_PATH} \
		  LC_ALL=C ${BUILDDIR}/bin/keytool		\
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

.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=
.endif

# Include binutils for objcopy and GNU strip on SmartOS
.if ${OS_VARIANT} == "SmartOS"
.include "../../devel/binutils/buildlink3.mk"
BUILDLINK_DEPMETHOD.binutils?=	build
MAKE_ENV+=	ALT_OBJCOPY=${PREFIX}/bin/gobjcopy
MAKE_ENV+=	STRIP=${PREFIX}/bin/gstrip
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_DEPMETHOD.cups?=	build
.include "../../print/cups15/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXp?=	build
.include "../../x11/libXp/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
