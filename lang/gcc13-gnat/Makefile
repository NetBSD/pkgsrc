# $NetBSD: Makefile,v 1.1 2024/03/08 12:02:33 wiz Exp $

GCC_PKGNAME=gcc13
.include "../../lang/${GCC_PKGNAME}/version.mk"

PKGNAME=	${GCC_PKGNAME}-gnat-${GCC13_DIST_VERSION}
COMMENT=	GNAT Compiler and Ada tools
DISTNAME=	gcc-${GCC13_DIST_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC13_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

INFO_FILES=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake makeinfo sed:run tar perl
USE_TOOLS.NetBSD+=	gsed

MKPIE_SUPPORTED=	no

CHECK_RELRO_SKIP+=	${GCC_PKGNAME}-gnat/lib/*

.include "../../mk/bsd.prefs.mk"

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

USE_LANGUAGES=		c c++ ada
GCC_REQD+=	10
.include "../../mk/compiler/gcc.mk"

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/configure.orig_dist

## Build outside ${WRKSRC}
OBJDIR=			${WRKDIR}/build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNAT_SUBPREFIX=		${GCC_PKGNAME}-gnat
GNAT_PREFIX=		${PREFIX}/${GNAT_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GNAT_PREFIX}

.include "options.mk"

CONFIGURE_ARGS+=	--disable-libstdcxx-pch

# In some cases LINKER_RPATH_FLAG needs a trailing space.
LINKER_RPATH_FLAG:=	${LINKER_RPATH_FLAG:S/-rpath/& /}

## The Library rpath to use in end programs.
LDFLAGS_FOR_TARGET=	${LDFLAGS:M${COMPILER_RPATH_FLAG}*:N*/usr/lib*} ${LDFLAGS:M-Wl,-z*}

# The "-static-libstdc++ -static-libgcc" flags are normally added to the
# boot-ldflags by configure but because we are supply the boot-ldflags
# we mash supply them.
BOOT_LDFLAGS=		-static-libstdc++ -static-libgcc ${LDFLAGS_FOR_TARGET}
# Needed on Darwin when LDFLAGS point to a SDK
BOOT_LDFLAGS+=		${LDFLAGS:M-Wl,-syslibroot*}
# GCC does not understand this option; remove it, or stage build will fail
BUILDLINK_TRANSFORM+=	rm:-stdlib=libc++

STAGE1_LDFLAGS=	-static ${BOOT_LDFLAGS}

# Disable fixincludes on SmartOS, header changes result in broken includes
# being generated, see https://github.com/joyent/pkgsrc-legacy/issues/270
.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		fixinc
SUBST_STAGE.fixinc=	pre-configure
SUBST_FILES.fixinc=	gcc/Makefile.in
SUBST_SED.fixinc=	-e "s,\./fixinc.sh,-c true,"
.endif

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

## For target librarys and libjava programs.
CONFIGURE_ENV+=	LDFLAGS_FOR_TARGET=${LDFLAGS_FOR_TARGET:Q}

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q}
CONFIGURE_ENV+=	CXX_FOR_BUILD=${NATIVE_CXX:Q}
.endif

CONFIGURE_ARGS+=	--enable-languages=c,c++,ada --enable-stage1-languages=c++,ada
#CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GNAT_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-__cxa_atexit
#CONFIGURE_ARGS+=	--with-gxx-include-dir='${GNAT_PREFIX}/include/c++'
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--with-stage1-ldflags=${STAGE1_LDFLAGS:Q}
CONFIGURE_ARGS+=	--with-boot-ldflags=${BOOT_LDFLAGS:Q}
# causes build errors even when using lang/gcc13 to self host
CONFIGURE_ARGS.SunOS+=	--disable-libsanitizer
# multilib on Darwin requires fat-binaries
CONFIGURE_ARGS.Darwin+=	--disable-multilib
.if !empty(OSX_SDK_PATH)
CONFIGURE_ARGS.Darwin+=	--with-sysroot=${OSX_SDK_PATH}
.endif
CONFIGURE_ARGS.NetBSD+=	--with-gnu-ld --with-ld=/usr/bin/ld
CONFIGURE_ARGS.NetBSD+=	--with-gnu-as --with-as=/usr/bin/as
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
MAKE_ENV+=	ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=	lt_cv_path_SED=${TOOLS_SED}

# Determine whether to use binutils
.if ${OPSYS} == "SunOS"
.  if exists(/usr/sfw/bin/gobjdump)
CONFIGURE_ENV+=OBJDUMP=/usr/sfw/bin/gobjdump
.  endif
.  if exists(/usr/bin/ld)
CONFIGURE_ARGS+=--without-gnu-ld --with-ld=/usr/bin/ld
.  else
CONFIGURE_ARGS+=--without-gnu-ld --with-ld=/usr/ccs/bin/ld
.  endif
.  if exists(/usr/sfw/bin/gas)
CONFIGURE_ARGS+=--with-gnu-as --with-as=/usr/sfw/bin/gas
.  elif exists(/usr/ccs/bin/as)
CONFIGURE_ARGS+=--without-gnu-as --with-as=/usr/ccs/bin/as
.  else
BUILDLINK_DEPMETHOD.binutils=full
.    include "../../devel/binutils/buildlink3.mk"
CONFIGURE_ARGS+=--with-gnu-as --with-as=${PREFIX}/bin/gas
.  endif
.endif

.if ${OPSYS} == "Linux"
# glibc limitations, needs at least -O1
FORTIFY_SUPPORTED=	no
.endif

.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		ccs
SUBST_STAGE.ccs=	pre-configure
SUBST_FILES.ccs=	contrib/make_sunver.pl
SUBST_SED.ccs=		-e 's,/usr/ccs/bin,/usr/bin,g'
.endif

CTF_FILES_SKIP+=	*/gengtype	# CPU limit exceeded

TEST_TARGET=	-j ${MAKE_JOBS} -k check || ${TRUE}
TEST_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_SUBPREFIX} \( -type f -or -type l \) -print | ${SORT};

.include "../../archivers/zstd/buildlink3.mk"
CONFIGURE_ARGS+=--with-zstd=${BUILDLINK_PREFIX.zstd}

CHECK_BUILTIN.zlib=yes
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.zlib=no
.if ${USE_BUILTIN.zlib:tl} == yes
CONFIGURE_ARGS+=--with-system-zlib
.else
CONFIGURE_ARGS+=--without-system-zlib
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-test:
	${RUN} cd ${WRKSRC} && cd ${OBJDIR} &&	\
	${SHELL} ${WRKSRC}/contrib/test_summary >${WRKDIR}/test_summary.log
	${INFO_MSG} "Test summary are available in ${WRKDIR}/test_summary.log"

post-install:
	${TEST} -f ${DESTDIR}${GNAT_PREFIX}/bin/gnat && \
		( cd ${DESTDIR}${GNAT_PREFIX}/bin ; ${LN} -f gnat ada )
.if ${MACHINE_PLATFORM:MSunOS-*-*86*} && ${OS_VERSION} != "5.11"
	${SH} files/values.c ${DESTDIR}${GNAT_PREFIX}/bin/gcc -m32 || ${TRUE}
	${SH} files/values.c ${DESTDIR}${GNAT_PREFIX}/bin/gcc -m64 || ${TRUE}
.endif

.include "../../mk/bsd.pkg.mk"
