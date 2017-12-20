# $NetBSD: Makefile,v 1.51.4.1 2017/12/20 16:54:59 spz Exp $

DISTNAME=	openjdk-1.8.152-20171128
PKGNAME=	openjdk8-1.8.152
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL:=openjdk7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/
COMMENT=	Open-source implementation of the Java Platform, Standard Edition
LICENSE=	gnu-gpl-v2

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# Use same DIST_SUBDIR as openjdk7 to avoid duplication of common distfiles
DIST_SUBDIR=	openjdk7

JAVA_NAME=	openjdk8
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	jar java javac javadoc javah javap jcmd jps jstack keytool \
		orbd policytool rmid rmiregistry servertool tnameserv

BUILD_DEPENDS+=		mozilla-rootcerts>=1.0.20140820nb2:../../security/mozilla-rootcerts

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	common/autoconf/configure
CONFIG_SHELL=		bash
CONFIG_SUB_OVERRIDE+=	common/autoconf/build-aux/config.sub
CONFIG_GUESS_OVERRIDE+=	common/autoconf/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	common/autoconf/build-aux/autoconf-config.sub
CONFIG_GUESS_OVERRIDE+=	common/autoconf/build-aux/autoconf-config.guess
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash gmake pax pkg-config unzip:run zip:run
UNLIMIT_RESOURCES=	datasize stacksize
WRKSRC=			${WRKDIR}/openjdk
PLIST_SRC+=		${PLIST_SRC_DFLT}
CHECK_SHLIBS_SKIP+=	java/openjdk8/jre/lib/${LIBDIR_ARCH}/libinstrument.so

BUILDLINK_PASSTHRU_DIRS+=	${ALT_BOOTDIR}
PREPEND_PATH+=			${ALT_BOOTDIR}/bin

CONFIGURE_ARGS+=	--disable-option-checking # for --with-libiconv-prefix
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--with-boot-jdk=${ALT_BOOTDIR}
CONFIGURE_ARGS+=	--with-zlib=system
CONFIGURE_ARGS+=	--with-giflib=bundled
CONFIGURE_ARGS+=	--with-cups=${BUILDLINK_PREFIX.cups}
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

NOT_PAX_MPROTECT_SAFE+= java/openjdk8/bin/[a-ik-z]*
NOT_PAX_MPROTECT_SAFE+= java/openjdk8/bin/j[b-z]*
NOT_PAX_MPROTECT_SAFE+= java/openjdk8/bin/jar*
NOT_PAX_MPROTECT_SAFE+= java/openjdk8/bin/java
NOT_PAX_MPROTECT_SAFE+= java/openjdk8/bin/java[a-z]*
NOT_PAX_MPROTECT_SAFE+= java/openjdk8/jre/bin/*

# Avoid build errors when JAVA_HOME and CLASSPATH are defined by user.
MAKE_ENV+=	JAVA_HOME=
MAKE_ENV+=	CLASSPATH=

BUILD_OPSYS=	${OPSYS:C/.*BSD/bsd/:S/DragonFly/bsd/:S/SunOS/solaris/}
BUILD_ARCH=	${MACHINE_ARCH:S/i386/x86/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
LIBDIR_ARCH=	${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
BUILDDIR=	${WRKSRC}/build/${BUILD_OPSYS}-${BUILD_ARCH}-normal-${BUILD_VARIANT}-${BUILD_DEBUG_LEVEL}
LD_LIBRARY_PATH=	${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}:${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}/jli:${WRKDIR}/bootstrap/jre/lib/${LIBDIR_ARCH}/server
CONFIGURE_ENV+=	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
MAKE_ENV+=	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
CONFIGURE_ENV+=	LFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	LFLAGS=${LDFLAGS:Q}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/java/openjdk8/jre/lib/${LIBDIR_ARCH}

PLIST_SUBST+=	ARCH=${LIBDIR_ARCH}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS:S/sunos/solaris/}

.include "../../mk/compiler.mk"

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-build
SUBST_FILES.libpath+=	hotspot/src/os/bsd/vm/os_bsd.cpp
SUBST_VARS.libpath=	PREFIX

CFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
CXXFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV+=	USE_GCC=1
MAKE_ENV+=	ARCH_DATA_MODEL=${ABI:Q}
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
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
.endif
.include "bootstrap.mk"

.include "options.mk"

SUBST_CLASSES+=			fontpaths
SUBST_STAGE.fontpaths=		pre-build
SUBST_MESSAGE.fontpaths=	fixing font paths
SUBST_FILES.fontpaths=		jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
SUBST_FILES.fontpaths+=		jdk/src/solaris/native/sun/awt/fontpath.c
SUBST_SED.fontpaths=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.fontpaths+=		-e 's|@BUILDLINK_PREFIX.fontconfig@|${BUILDLINK_PREFIX.fontconfig}|g'

SUBST_CLASSES+=			zlibpath
SUBST_STAGE.zlibpath=		pre-build
SUBST_FILES.zlibpath=		jdk/make/CompileLaunchers.gmk jdk/make/lib/CoreLibraries.gmk
SUBST_FILES.zlibpath+=		jdk/make/lib/Awt2dLibraries.gmk jdk/make/lib/ServiceabilityLibraries.gmk
SUBST_VARS.zlibpath=		COMPILER_RPATH_FLAG BUILDLINK_PREFIX.zlib
SUBST_VARS.zlibpath+=		BUILDLINK_PREFIX.iconv

PLIST_VARS+=	i386
.if ${MACHINE_ARCH} == "i386"
PLIST.i386=	yes
.endif

PLIST_VARS+=	sctp
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS"
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
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} images
	rm -rf ${ALT_BOOTDIR}
	cd ${BUILDDIR}/images && mv j2sdk-image ${ALT_BOOTDIR}
.for d in corba hotspot jaxp jaxws langtools tmp
	mv ${BUILDDIR}/${d} ${BUILDDIR}/${d}-stage1
.endfor
	touch ${.TARGET}

# stage 1.5 reconfigures, since the bootstrap JDK major version might have changed now
${WRKDIR}/stage1_5-done: ${WRKDIR}/stage1-done
.if defined(TOOLS_PLATFORM.paxctl)
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/[a-ik-z]*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/j[b-z]*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/jar*
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/java
	${PAXCTL} +m ${WRKDIR}/bootstrap/bin/java[a-z]*
.endif
.if defined(BATCH)
	@${RECURSIVE_MAKE} ${MAKEFLAGS} apply-va-hack
.endif
	@${STEP_MSG} "Reconfiguring with newly built JDK"
	@${RECURSIVE_MAKE} ${MAKEFLAGS} do-configure
	touch ${.TARGET}

# stage 2 rebuilds the JDK using native tools
${WRKDIR}/stage2-done: ${WRKDIR}/stage1_5-done
	${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} images
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
	ln -s ${LOWER_OPSYS:S/sunos/solaris/}/jni_md.h					\
	  ${DESTDIR}${JAVA_HOME}/include/jni_md.h

.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=
.endif

# Include binutils for objcopy and GNU strip on SmartOS
.if ${OS_VARIANT} == "SmartOS"
.include "../../devel/binutils/buildlink3.mk"
BUILDLINK_DEPMETHOD.binutils?=	build
MAKE_ENV+=	STRIP=${PREFIX}/bin/gstrip
.endif

# disabled the ALSA support for now on BSDs via patch
#.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_DEPMETHOD.cups?=	build
.include "../../print/cups/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
