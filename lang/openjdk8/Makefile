# $NetBSD: Makefile,v 1.127 2024/05/10 22:52:47 gdt Exp $

DISTNAME=	jdk8u-${GITHUB_TAG}
PKGNAME=	openjdk8-1.8.${GITHUB_TAG:C/.*u([0-9]+).*/\1/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=battleblow/}
MASTER_SITES+=	${MASTER_SITE_LOCAL:=openjdk7/}	# for bootstrap kits
GITHUB_PROJECT=	jdk8u
GITHUB_TAG=	jdk8u402-b06.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openjdk.java.net/
COMMENT=	Open-source implementation of the Java Platform, Standard Edition
LICENSE=	gnu-gpl-v2

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# Use same DIST_SUBDIR as openjdk7 to avoid duplication of common distfiles
DIST_SUBDIR=	openjdk7

JAVA_NAME=	openjdk8
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	jar java javac javadoc javah javap jcmd jhat jmap jps jstack \
		keytool orbd policytool rmid rmiregistry servertool tnameserv

TOOL_DEPENDS+=		mozilla-rootcerts>=1.0.20140820nb2:../../security/mozilla-rootcerts

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # not really GNU configure, only similar
USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_SCRIPT=	configure
CONFIG_SHELL=		bash
CONFIG_SUB_OVERRIDE+=	common/autoconf/build-aux/config.sub
CONFIG_GUESS_OVERRIDE+=	common/autoconf/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	common/autoconf/build-aux/autoconf-config.sub
CONFIG_GUESS_OVERRIDE+=	common/autoconf/build-aux/autoconf-config.guess
USE_LANGUAGES=		c c++
# openjdk8's build system objects to wrapper which invokes ccache,
# when trying to decide if it is gcc or clang, resulting in failure.
IGNORE_CCACHE=		yes
USE_TOOLS+=		bash gmake pax pkg-config unzip:run zip:run
UNLIMIT_RESOURCES=	datasize stacksize virtualsize cputime
PLIST_SRC+=		${PLIST_SRC_DFLT}
CHECK_SHLIBS_SKIP+=	java/${JAVA_NAME}/jre/lib/${LIBDIR_ARCH}/libinstrument.so

BUILDLINK_PASSTHRU_DIRS+=	${ALT_BOOTDIR}
PREPEND_PATH+=			${ALT_BOOTDIR}/bin

BUILDLINK_TRANSFORM+=	rm:-Werror

# hotspot/src/share/vm/adlc/dict2.cpp does that, but it's safe.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

CONFIGURE_ARGS+=	--disable-option-checking # for --with-libiconv-prefix
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--openjdk-target=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--with-boot-jdk=${ALT_BOOTDIR}
CONFIGURE_ARGS+=	--with-zlib=system
CONFIGURE_ARGS+=	--with-giflib=bundled
CONFIGURE_ARGS+=	--with-cups-include=${BUILDLINK_PREFIX.libcups}/include
CONFIGURE_ARGS+=	--with-freetype-lib=${BUILDLINK_PREFIX.freetype2}/lib
CONFIGURE_ARGS+=	--with-freetype-include=${BUILDLINK_PREFIX.freetype2}/include
CONFIGURE_ARGS+=	--disable-freetype-bundling
CONFIGURE_ARGS+=	--with-jobs=${MAKE_JOBS:U1}
CONFIGURE_ARGS+=	--with-num-cores=${MAKE_JOBS:U1}
CONFIGURE_ARGS+=	--with-memory-size=768
CONFIGURE_ARGS+=	--disable-precompiled-headers
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--with-user-release-suffix=pkgsrc_${PKGVERSION}
CONFIGURE_ARGS+=	--with-update-version=${PKGVERSION_NOREV:S/1.8.//}
CONFIGURE_ARGS+=	--with-extra-ldflags=${LDFLAGS:Q}

CHECK_PORTABILITY_SKIP+=	hotspot/test/runtime/*/*.sh
CHECK_PORTABILITY_SKIP+=	hotspot/test/compiler/*/*/*.sh

# Avoid build errors when JAVA_HOME and CLASSPATH are defined by user.
MAKE_ENV+=	JAVA_HOME=
MAKE_ENV+=	CLASSPATH=

BUILD_OPSYS=			${OPSYS:C/.*BSD/bsd/:S/DragonFly/bsd/:S/SunOS/solaris/:S/Linux/linux/}
BUILD_ARCH=			${MACHINE_ARCH:S/i386/x86/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
LIBDIR_ARCH=			${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
BUILDDIR=			${WRKSRC}/build/${BUILD_OPSYS}-${BUILD_ARCH}-normal-${BUILD_VARIANT}-${BUILD_DEBUG_LEVEL}
LD_LIBRARY_PATH=		${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}:${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}/jli:${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}/server
CONFIGURE_ENV+=			LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
MAKE_ENV+=			LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
CONFIGURE_ENV+=			LFLAGS=${LDFLAGS:Q}
MAKE_ENV+=			LFLAGS=${LDFLAGS:Q}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/java/${JAVA_NAME}/jre/lib/${LIBDIR_ARCH}

PLIST_SUBST+=	ARCH=${LIBDIR_ARCH}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS:S/sunos/solaris/}

.include "../../mk/compiler.mk"

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-build
SUBST_FILES.libpath+=	hotspot/src/os/bsd/vm/os_bsd.cpp
SUBST_VARS.libpath=	PREFIX

CFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
CXXFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS

CONFIGURE_ENV+=	CFLAGS_JDK=${CFLAGS:Q}
CONFIGURE_ENV+=	CXXFLAGS_JDK=${CXXFLAGS:Q}

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV+=	USE_GCC=1
MAKE_ENV+=	ARCH_DATA_MODEL=${ABI:Q}
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--with-toolchain-type=clang
MAKE_ENV+=		USE_CLANG=true
_WRAP_EXTRA_ARGS.CC+=	-Wno-return-type
CWRAPPERS_APPEND.cc+=	-Wno-return-type
_WRAP_EXTRA_ARGS.CXX+=	-Wno-parentheses -Wno-sign-conversion \
			-Wno-shorten-64-to-32 -Wno-conversion \
			-Wno-unused-value -Wno-switch-enum -Wno-switch \
			-Wno-tautological-compare \
			-Wno-delete-non-virtual-dtor \
			-Wno-return-type -Wno-unused-parameter \
			-Wno-parentheses-equality -Wno-empty-body \
			-Wno-format -Wno-dynamic-class-memaccess
CWRAPPERS_APPEND.cxx+=	-Wno-parentheses -Wno-sign-conversion \
			-Wno-shorten-64-to-32 -Wno-conversion \
			-Wno-unused-value -Wno-switch-enum -Wno-switch \
			-Wno-tautological-compare \
			-Wno-delete-non-virtual-dtor \
			-Wno-return-type -Wno-unused-parameter \
			-Wno-parentheses-equality -Wno-empty-body \
			-Wno-format -Wno-dynamic-class-memaccess
.  if ${OPSYS} != "FreeBSD"
_WRAP_EXTRA_ARGS.CXX+=	-Wno-new-returns-null
CWRAPPERS_APPEND.cxx+=	-Wno-new-returns-null
.  endif
BUILDLINK_TRANSFORM+=	rm:-fcheck-new
BUILDLINK_TRANSFORM+=	rm:-fpch-deps
.  if ${MACHINE_ARCH} == "x86_64"
_WRAP_EXTRA_ARGS.CXX+=	-mstackrealign
CWRAPPERS_APPEND.cxx+=	-mstackrealign
.  endif
.else
# GCC
CONFIGURE_ARGS+=	--with-toolchain-type=gcc
.endif
.include "bootstrap.mk"

.include "options.mk"

SUBST_CLASSES+=			fontpaths
SUBST_STAGE.fontpaths=		pre-build
SUBST_MESSAGE.fontpaths=	fixing font paths
SUBST_FILES.fontpaths=		jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
SUBST_FILES.fontpaths+=		jdk/src/solaris/native/sun/awt/fontpath.c
SUBST_VARS.fontpaths=		PREFIX
SUBST_VARS.fontpaths+=		BUILDLINK_PREFIX.fontconfig

SUBST_CLASSES+=			zlibpath
SUBST_STAGE.zlibpath=		pre-build
SUBST_FILES.zlibpath=		jdk/make/CompileLaunchers.gmk jdk/make/lib/CoreLibraries.gmk
SUBST_FILES.zlibpath+=		jdk/make/lib/Awt2dLibraries.gmk
SUBST_VARS.zlibpath=		COMPILER_RPATH_FLAG BUILDLINK_PREFIX.zlib
SUBST_VARS.zlibpath+=		BUILDLINK_PREFIX.iconv

.if ${OPSYS} == "NetBSD"
# NetBSD's EVFILT_* are different from FreeBSD/OpenBSD's values.
SUBST_CLASSES+=			kqueue
SUBST_STAGE.kqueue=		pre-configure
SUBST_MESSAGE.kqueue=		fixing kqueue filter values
SUBST_FILES.kqueue=		jdk/src/solaris/classes/sun/nio/ch/KQueue.java
SUBST_SED.kqueue=		-e 's/static final int EVFILT_READ  = -1;/static final int EVFILT_READ  = 0;/'
SUBST_SED.kqueue+=		-e 's/static final int EVFILT_WRITE = -2;/static final int EVFILT_WRITE = 1;/'
.endif

PLIST_VARS+=	i386
.if ${MACHINE_ARCH} == "i386"
PLIST.i386=	yes
.endif

PLIST_VARS+=	sctp
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
PLIST.sctp=	yes
.endif

post-extract:
# These libs are bundled w/ the netbsd-7 bootstrap to facilitate building with
# MKLLVM=yes / MKGCC=no. Nuke them from bootstrap if they are present in base.
.if exists(/lib/libgcc_s.so.1)
	${RM} -f ${ALT_BOOTDIR}/jre/lib/${LIBDIR_ARCH}/libgcc_s.so*
.endif
.if exists(/usr/lib/libstdc++.so.7)
	${RM} -f ${ALT_BOOTDIR}/jre/lib/${LIBDIR_ARCH}/libstdc++.so*
.endif
# This can be removed after bootstrap kits have been refreshed
.if defined(TOOLS_PLATFORM.paxctl)
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/[a-ik-z]*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/j[b-z]*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/jar*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/java
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/java[a-z]*
.endif

do-build: ${WRKDIR}/stage3-done

# stage 1 builds a native JDK using the bootstrap binaries
${WRKDIR}/stage1-done:
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} images
	rm -rf ${ALT_BOOTDIR}
	cd ${BUILDDIR}/images && mv j2sdk-image ${ALT_BOOTDIR}
.for d in corba hotspot jaxp jaxws langtools tmp
	mv ${BUILDDIR}/${d} ${BUILDDIR}/${d}-stage1
.endfor
	touch ${.TARGET}

# stage 1.5 reconfigures, since the bootstrap JDK major version might have changed now
${WRKDIR}/stage1_5-done: ${WRKDIR}/stage1-done
	@${STEP_MSG} "Reconfiguring with newly built JDK"
	@${RECURSIVE_MAKE} ${MAKEFLAGS} do-configure
	touch ${.TARGET}

# stage 2 rebuilds the JDK using native tools
${WRKDIR}/stage2-done: ${WRKDIR}/stage1_5-done
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} images
	touch ${.TARGET}

# stage 3 builds third party add-ons
${WRKDIR}/stage3-done: ${WRKDIR}/stage2-done ${WRKDIR}/cacerts.out
	touch ${.TARGET}

${WRKDIR}/cacerts.out:
	mkdir ${WRKDIR}/cacerts && cd ${WRKDIR}/cacerts && 		\
		${PREFIX}/sbin/mozilla-rootcerts extract
	for cert in ${WRKDIR}/cacerts/*.pem; do				\
		${INFO_MSG} "Importing $$cert" &&			\
		 ${SETENV} LD_LIBRARY_PATH=${LD_LIBRARY_PATH} LC_ALL=C	\
		  ${ALT_BOOTDIR}/bin/keytool				\
		  -noprompt						\
		  -importcert						\
		  -keystore ${.TARGET}					\
		  -alias `${ECHO} $$cert | sed 's,.*/\\([^/]*\\)\\.pem,\\1,'` \
		  -file $$cert						\
		  -storepass changeit;					\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${JAVA_HOME}
	cd ${BUILDDIR}/images/j2sdk-image && pax -rwpp .		\
	  ${DESTDIR}${JAVA_HOME}/.
	${INSTALL_DATA} ${WRKDIR}/cacerts.out				\
	  ${DESTDIR}${JAVA_HOME}/jre/lib/security/cacerts
	rm -f ${DESTDIR}${JAVA_HOME}/include/jni_md.h
	ln -s ${LOWER_OPSYS:S/sunos/solaris/}/jni_md.h			\
	  ${DESTDIR}${JAVA_HOME}/include/jni_md.h

.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=
.endif

# Include binutils for objcopy and GNU strip on SmartOS
.if ${OS_VARIANT} == "SmartOS" || ${OS_VARIANT} == "OmniOS"
.include "../../devel/binutils/buildlink3.mk"
BUILDLINK_DEPMETHOD.binutils?=	build
MAKE_ENV+=	STRIP=${PREFIX}/bin/gstrip
.endif

# disabled the ALSA support for now on BSDs via patch
.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# Headers from CUPS are required to build the native implementation of
# sun.print.* which is used by java.awt.print.
BUILDLINK_DEPMETHOD.libcups?=	build
.include "../../print/libcups/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
