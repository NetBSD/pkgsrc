# $NetBSD: Makefile,v 1.37 2012/10/02 20:11:41 asau Exp $

DISTNAME=		gcc-${GCC_VERSION}
PKGNAME=		gcc44-${GCC_VERSION}
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		GNU Compiler Collection 4.4
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=		awk:run bash:run chmod gmake:run makeinfo sed:run

GCC_VERSION=		4.4.7

GCC_SUBPREFIX=		gcc44
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME}

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
.endif
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
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--enable-threads=posix

CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL}

MAKE_ENV+=		SHELL=${CONFIG_SHELL}
MAKE_ENV+=		ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD}

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

CPPFLAGS+=		-I${BUILDLINK_DIR}/include
CFLAGS+=		-I${BUILDLINK_DIR}/include

# Somone should fix this so it will match the NetBSD system compiler
#.if ${OPSYS} == "NetBSD"
#GCC_PLATFORM=	${LOWER_ARCH}--${LOWER_OPSYS}${APPEND_ELF}
#CONFIGURE_ARGS+=	--host=${GCC_PLATFORM:Q}
#MAKE_ENV+=		AR=/usr/bin/ar
#.endif # NetBSD

LIBS.SunOS+=		-lgmp


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
