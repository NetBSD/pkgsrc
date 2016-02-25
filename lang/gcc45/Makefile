# $NetBSD: Makefile,v 1.21 2016/02/25 14:42:55 jperkin Exp $

DISTNAME=		gcc-${GCC_VERSION}
PKGNAME=		gcc45-${GCC_VERSION}
PKGREVISION=		7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		GNU Compiler Collection 4.5
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=		awk:run bash:run chmod gmake:run makeinfo sed:run
GCC_REQD+=		4.4

GCC_VERSION=		4.5.3

GCC_SUBPREFIX=		gcc45
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}


# To avoid GNU surprises
CONFIG_SHELL=		${TOOLS_PATH.bash}

NOT_FOR_PLATFORM=	Interix-*-* DragonFly-*-*
UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# Determine whether to use binutils
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		OBJDUMP=/usr/sfw/bin/gobjdump
CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
. if !exists(/usr/sfw/bin/gas)
CONFIGURE_ARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
. else
CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
. endif
.endif

# REPLACE_AWK+=	gcc/testsuite/gcc.test-framework/test-framework.awk	\
# 		gcc/mkmap-symver.awk					\
# 		gcc/optc-gen.awk					\
# 		gcc/mkmap-flat.awk					\
# 		gcc/opt-gather.awk					\
# 		gcc/opth-gen.awk					\
# 		gcc/opt-functions.awk

REPLACE_BASH+= contrib/dg-cmp-results.sh
REPLACE_BASH+= contrib/reghunt/bin/gcc-svn-patchlist
REPLACE_BASH+= contrib/reghunt/bin/gcc-svn-update
REPLACE_BASH+= contrib/reghunt/bin/gcc-svn-update-fix
REPLACE_BASH+= contrib/reghunt/bin/reg-hunt
REPLACE_BASH+= contrib/reghunt/bin/reg-test
REPLACE_BASH+= contrib/reghunt/date_based/reg_periodic
REPLACE_BASH+= contrib/reghunt/date_based/reg_search
REPLACE_BASH+= gcc/dbgcnt.def
REPLACE_BASH+= gcc/testsuite/gcc.test-framework/gen_directive_tests
REPLACE_BASH+= libstdc++-v3/scripts/run_doxygen


CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-libssp
CONFIGURE_ARGS+=	--enable-threads=posix
.if ${OPSYS} == "NetBSD"
.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ld=${PREFIX}/gnu/bin/ld
CONFIGURE_ARGS+=	--with-libelf=${PREFIX}
MAKE_ENV+=		ac_cv_func_clock_gettime=yes
.endif

CONFIGURE_ARGS.Linux+=	--disable-libquadmath --disable-libquadmath-support

# See ${WRKSRC}/libgcc/config/t-slibgcc-darwin: It uses strip(1) to
# create a stub library, not just to remove symbols, so we must not
# let strip(1) be a no-op regardless of ${INSTALL_UNSTRIPPED} or the
# build fails for missing files.
CONFIGURE_ARGS.Darwin+=	STRIP_FOR_TARGET=${TOOLS_PLATFORM.strip}

.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CONFIGURE_ARGS+=	--with-dwarf2
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-powerpc) \
 || (!empty(MACHINE_PLATFORM:MLinux-*-x86_64) && \
      exists(/usr/include/gnu/stubs-64.h) && \
     !exists(/usr/include/gnu/stubs-32.h))
CONFIGURE_ARGS+=	--disable-multilib
.endif

CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL}

MAKE_ENV+=		SHELL=${CONFIG_SHELL}
MAKE_ENV+=		ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD}

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

CPPFLAGS+=		-I${BUILDLINK_DIR}/include
CFLAGS+=		-I${BUILDLINK_DIR}/include


# Somone should fix this so it will match the NetBSD system compiler
#.if ${OPSYS} == "NetBSD"
#GCC_PLATFORM=	${MACHINE_ARCH}--${LOWER_OPSYS}${APPEND_ELF}
#CONFIGURE_ARGS+=	--host=${GCC_PLATFORM:Q}
#MAKE_ENV+=		AR=/usr/bin/ar
#.endif # NetBSD

pre-configure:
.if ${OPSYS} == "DragonFly"
	${CP} ${FILESDIR}/dragonfly.h ${WRKSRC}/gcc/config/dragonfly.h
	${CP} ${FILESDIR}/dragonfly-spec.h ${WRKSRC}/gcc/config/dragonfly-spec.h
	${CP} ${FILESDIR}/i386-dragonfly.h ${WRKSRC}/gcc/config/i386/dragonfly.h
	${CP} ${FILESDIR}/i386-dragonfly64.h ${WRKSRC}/gcc/config/i386/dragonfly64.h
.endif

.if ${OPSYS} == "NetBSD"
	${CP} ${WRKSRC}/gcc/config/freebsd-stdint.h ${WRKSRC}/gcc/config/netbsd-stdint.h
.endif

do-configure:
	${MKDIR} ${WRKDIR}/obj
	cd ${WRKDIR}/obj; ${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1:Q} )

do-test:
#.if (${MACHINE_GNU_ARCH} == "x86_64")
#	(cd ${FILESDIR} && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
#.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install DESTDIR=${DESTDIR} \
	 && ${TEST} -f ${DESTDIR}${GCC_PREFIX}/bin/cc || ${LN} -f ${DESTDIR}${GCC_PREFIX}/bin/gcc ${DESTDIR}${GCC_PREFIX}/bin/cc)

.if ${OPSYS} == "SunOS" && ${OS_VERSION} != "5.11" && !empty(MACHINE_ARCH:M*86*)
post-install:
	-${SH} files/values.c ${DESTDIR}${GCC_PREFIX}/bin/gcc -m32
	-${SH} files/values.c ${DESTDIR}${GCC_PREFIX}/bin/gcc -m64
.endif

GENERATE_PLIST+=                                                        \
	cd ${DESTDIR}${PREFIX} && ${FIND} ${GCC_SUBPREFIX} \( -type f -o -type l \) -print \
	| ${SORT} ;

.include "../../mk/bsd.pkg.mk"
