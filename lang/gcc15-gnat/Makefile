# $NetBSD: Makefile,v 1.3 2025/08/27 18:59:44 dkazankov Exp $

DISTNAME=	gcc-${PKGVERSION_NOREV}
PKGNAME=	gcc15-gnat-15.2.0
#PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GNAT compiler and Ada tools
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=114065
BROKEN_ON_PLATFORM=	*-*-i386

CHECK_PIE_SUPPORTED=	no
CHECK_RELRO_SUPPORTED=	no

USE_LANGUAGES=		c c++ ada
USE_TOOLS+=		gmake makeinfo sed perl flex bison
USE_TOOLS.NetBSD+=	gsed
# Built-in Texinfo can no longer process GCC 15's files
TEXINFO_REQD+=		7.0
BISON_REQD+=		3.5

INFO_FILES=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no

.include "../../mk/bsd.prefs.mk"

USE_PKGSRC_GCC?=	yes
GCC_REQD+=		10

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/configure.orig_dist

## Build outside ${WRKSRC}
OBJDIR=			${WRKDIR}/build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PKGBASE}

.include "options.mk"

# DO NOT REMOVE THIS SUBST.  If it fails, the corruption to
# patch-gcc_Makefile.in chronicled in PR pkg/58963 `gcc:
# LINK_LIBGCC_SPEC snafu' <https://gnats.NetBSD.org/58963> probably got
# replicated yet again.  You must make sure that LINK_LIBGCC_SPEC is
# appropriately set with @GCC_TARGET_MACHINE@ in patch-gcc_Makefile.in
# or similar, or confirm with a discussion on tech-pkg@ that it is no
# longer relevant before you remove this SUBST.
SUBST_CLASSES+=		vars
SUBST_MESSAGE.vars=	Setting target machine name path in ${SUBST_FILES.vars}
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	gcc/Makefile.in
SUBST_VARS.vars=	GCC_TARGET_MACHINE

GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
BUILD_DEFS+=		GCC_TARGET_MACHINE

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			select
SUBST_MESSAGE.select=		Replace select with __gnat_select in ${SUBST_FILES.select}
SUBST_STAGE.select=		pre-configure
SUBST_FILES.select=		gcc/ada/libgnat/g-socthi.ads
SUBST_SED.select=		-e "s,\"select\",\"__gnat_select\","

SUBST_CLASSES+=			socket
SUBST_MESSAGE.socket=		Replace socket with __gnat_socket in ${SUBST_FILES.socket}
SUBST_STAGE.socket=		pre-configure
SUBST_FILES.socket=		gcc/ada/libgnat/g-socthi.adb
SUBST_SED.socket=		-e "s,\"socket\",\"__gnat_socket\","

SUBST_CLASSES+=			nanosleep
SUBST_MESSAGE.nanosleep=	Replace nanosleep with __gnat_nanosleep in ${SUBST_FILES.nanosleep}
SUBST_STAGE.nanosleep=		pre-configure
SUBST_FILES.nanosleep=		gcc/ada/libgnat/s-osprim__posix.adb
SUBST_SED.nanosleep=		-e "s,\"nanosleep\",\"__gnat_nanosleep\","

SUBST_CLASSES+=			gettimeofday
SUBST_MESSAGE.gettimeofday=	Replace gettimeofday with __gnat_gettimeofday in ${SUBST_FILES.gettimeofday}
SUBST_STAGE.gettimeofday=	pre-configure
SUBST_FILES.gettimeofday=	gcc/ada/libgnat/s-osprim__posix.adb
SUBST_SED.gettimeofday=		-e "s,\"gettimeofday\",\"__gnat_gettimeofday\","
.endif

#.if ${MACHINE_PLATFORM:MDarwin-*-*}
#BUILDLINK_TRANSFORM+=	rm:-nodefaultrpaths
#CONFIGURE_ARGS+=	--disable-darwin-at-rpath
#PATCHFILES=		gcc-15.1.0.diff
#PATCH_SITES=		https://raw.githubusercontent.com/Homebrew/formula-patches/bda0fad/gcc/
#PATCH_DIST_STRIP=	-p1
#.endif

.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		ccs
SUBST_STAGE.ccs=	pre-configure
SUBST_FILES.ccs=	contrib/make_sunver.pl
SUBST_SED.ccs=		-e 's,/usr/ccs/bin,/usr/bin,g'
.endif

# Disable fixincludes on SmartOS, header changes result in broken includes
# being generated, see https://github.com/joyent/pkgsrc-legacy/issues/270
.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		fixinc
SUBST_STAGE.fixinc=	pre-configure
SUBST_FILES.fixinc=	gcc/Makefile.in
SUBST_SED.fixinc=	-e "s,\./fixinc.sh,-c true,"
.endif

# In some cases LINKER_RPATH_FLAG needs a trailing space.
LINKER_RPATH_FLAG:=	${LINKER_RPATH_FLAG:S/-rpath/& /}

## The Library rpath to use in end programs.
#LDFLAGS_FOR_TARGET=	${LDFLAGS:M${COMPILER_RPATH_FLAG}*:N*/usr/lib*} ${LDFLAGS:M-Wl,-z*}
LDFLAGS_FOR_TARGET=	-static-libstdc++ -static-libgcc
LDFLAGS_FOR_TARGET+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PKGBASE}/lib
LDFLAGS_FOR_TARGET+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PKGBASE}/lib/gcc/${MACHINE_GNU_PLATFORM}/${PKGVERSION_NOREV}/adalib
LDFLAGS_FOR_TARGET+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

# The "-static-libstdc++ -static-libgcc" flags are normally added to the
# boot-ldflags by configure but because we are supply the boot-ldflags
# we mash supply them.
STAGE1_LDFLAGS=		${LDFLAGS:M*:N-Wl,-z*} -static
BOOT_LDFLAGS=		${LDFLAGS_FOR_TARGET:M*}

# Needed on Darwin when LDFLAGS point to a SDK
.if !empty(OSX_SDK_PATH)
BOOT_LDFLAGS+=		${LDFLAGS:M-Wl,-syslibroot*}
.endif

# GCC does not understand this option; remove it, or stage build will fail
BUILDLINK_TRANSFORM+=	rm:-stdlib=libc++

.if ${MACHINE_PLATFORM:MNetBSD-*-*}
# on NetBSD, use the native SSP code in libc
CONFIGURE_ARGS+=	--disable-libssp
# Match base libstdc++ major
SUBST_CLASSES+=		libstdc
SUBST_STAGE.libstdc=	pre-configure
SUBST_FILES.libstdc=	libstdc++-v3/configure
SUBST_MESSAGE.libstdc=	Bumping libstdc++ major to 7
SUBST_SED.libstdc=	-e 's,libtool_VERSION=6:,libtool_VERSION=7:,g'
.else
CONFIGURE_ARGS+=	--enable-libssp
.endif

CONFIGURE_ARGS+=	--enable-languages=ada,c,c++ --enable-stage1-languages=ada,c,c++

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-host-shared
#CONFIGURE_ARGS+=	--enable-host-pie
#CONFIGURE_ARGS+=	--enable-host-bind-now
#CONFIGURE_ARGS+=	--enable-default-pie
#CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${PREFIX}/${PKGBASE}
CONFIGURE_ARGS+=	--with-gxx-include-dir=${PREFIX}/${PKGBASE}/include/c++
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--enable-threads=posix

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
CONFIGURE_ENV+=		CXX_FOR_BUILD=${NATIVE_CXX:Q}
CONFIGURE_ARGS+=	--with-stage1-ldflags=${BOOT_LDFLAGS:M*:Q}
.else
CONFIGURE_ARGS+=	--with-stage1-ldflags=${STAGE1_LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-boot-ldflags=${BOOT_LDFLAGS:M*:Q}
.endif
## For target librarys and libjava programs.
CONFIGURE_ENV+=		LDFLAGS_FOR_TARGET=${LDFLAGS_FOR_TARGET:Q}

# causes build errors even when using lang/gcc* to self host
CONFIGURE_ARGS.SunOS+=	--disable-libsanitizer
# multilib on Darwin requires fat-binaries
CONFIGURE_ARGS.Darwin+=	--disable-multilib
.if !empty(OSX_SDK_PATH)
CONFIGURE_ARGS.Darwin+=	--with-sysroot=${OSX_SDK_PATH:Q}
.endif
MAKE_ENV.NetBSD+=	ac_cv_func_clock_gettime=yes
MAKE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
MAKE_ENV.NetBSD+=	ac_cv_func_freelocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_newlocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_uselocale=no
MAKE_ENV.SunOS+=	ac_cv_func_mkostemp=no

.if !empty(PKGSRC_COMPILER:Mclang) || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-bootstrap
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || ${MACHINE_PLATFORM:MLinux-*-i386}
CONFIGURE_ARGS+=	--with-arch=i486 --with-tune=i486
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || ${MACHINE_PLATFORM:MLinux-*-x86_64}
CONFIGURE_ARGS+=	--with-arch=nocona --with-tune=nocona --with-fpmath=sse
.endif

.if ${MACHINE_PLATFORM:MDarwin-[0-8].*-*}
CONFIGURE_ARGS+=	--with-dwarf2
.endif

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

# GCC 15 requires latest binutils
BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.35
.include "../../devel/binutils/buildlink3.mk"

CONFIGURE_ARGS+=	--with-gnu-ld --with-ld=${PREFIX}/bin/gld
CONFIGURE_ARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas

.if ${OPSYS} == "Linux"
# glibc limitations, needs at least -O1
FORTIFY_SUPPORTED=	no
.endif

CTF_FILES_SKIP+=	*/gengtype	# CPU limit exceeded

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-test:
	${RUN} cd ${WRKSRC} && cd ${OBJDIR} &&	\
	${SHELL} ${WRKSRC}/contrib/test_summary >${WRKDIR}/test_summary.log
	${INFO_MSG} "Test summary are available in ${WRKDIR}/test_summary.log"

post-install:
# Fix group write mode
	${CHMOD} g-w ${DESTDIR}${PREFIX}/${PKGBASE}/lib/gcc/${MACHINE_GNU_PLATFORM}/${PKGVERSION_NOREV}/adainclude/standard.ads.h
# Create old name that modern gnat no longer provides
	${TEST} -f ${DESTDIR}${PREFIX}/${PKGBASE}/bin/gnat && \
		( ${RUN} cd ${DESTDIR}${PREFIX}/${PKGBASE}/bin && ${LN} -f gnat ada )
.if ${MACHINE_PLATFORM:MSunOS-*-*86*} && ${OS_VERSION} != "5.11"
	${SH} files/values.c ${DESTDIR}${PREFIX}/${PKGBASE}/bin/gcc -m32 || ${TRUE}
	${SH} files/values.c ${DESTDIR}${PREFIX}/${PKGBASE}/bin/gcc -m64 || ${TRUE}
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${PKGBASE} \( -type f -or -type l \) -print | ${SORT};

TEST_TARGET=	-j ${MAKE_JOBS} -k check || ${TRUE}
TEST_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu

CHECK_BUILTIN.zlib:= yes
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.zlib:= no
.if ${USE_BUILTIN.zlib:tl} == yes
CONFIGURE_ARGS+=	--with-system-zlib
.else
CONFIGURE_ARGS+=	--without-system-zlib
.endif

.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zstd=${BUILDLINK_PREFIX.zstd}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
