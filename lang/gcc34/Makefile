# $NetBSD: Makefile,v 1.44 2010/03/24 19:43:25 asau Exp $
#

DISTNAME=	gcc-${GCC_VERSION}
PKGNAME=	gcc34-${GCC_VERSION}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 compiler

GCC_VERSION=		3.4.6

NOT_FOR_PLATFORM=	Interix-*-*

.include "../../mk/bsd.prefs.mk"

# Determine whether to use binutils
.if ${OPSYS} == "NetBSD"
.  if !defined(USE_BINUTILS)
AS_PATH:=	${AS}
.    for _dir_ in ${PATH:C/\:/ /g}
.      if empty(AS_PATH:M/*)
.        if exists(${_dir_}/${AS})
AS_PATH:=	${_dir_}/${AS}
.        endif
.      endif
.    endfor
.    if !empty(AS_PATH:M${LOCALBASE}/*)
USE_BINUTILS=	YES
.    else
AS_VERSION!=	${AS_PATH} --version | ${AWK} '{			\
		    split($$3, v, /[.]/);				\
		    printf "%02d%02d%02d%02d\n",v[1],v[2],v[3],v[4];	\
		    exit;						\
		}'
USE_BINUTILS!=	${TEST} ${AS_VERSION} -lt 02130201 && ${ECHO} YES || ${ECHO} NO
.    endif
MAKEFLAGS+=	USE_BINUTILS=${USE_BINUTILS:Q}
.  endif
.endif
.if defined(USE_BINUTILS) && !empty(USE_BINUTILS:M[yY][eE][sS])
DEPENDS+=	binutils>=2.14:../../devel/binutils
CONFIGURE_ARGS+=	--with-as=${LOCALBASE}/bin/as
CONFIGURE_ARGS+=	--with-ld=${LOCALBASE}/bin/ld
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
.endif

REPLACE_AWK+=		libjava/addr2name.awk
USE_TOOLS+=		awk:run

# Optional languages - change as required
#   If BUILD_ADA is YES, then you'll need to specify
#   an Ada in the "Ada bootstrap compiler section"
BUILD_DEFS+=	BUILD_ADA BUILD_CXX BUILD_F77 \
		BUILD_JAVA BUILD_OBJC
BUILD_ADA?=	NO
BUILD_CXX?=	YES
BUILD_F77?=	NO
BUILD_JAVA?=	YES
BUILD_OBJC?=	YES

LANGS='c'
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
LANGS+='ada'
.endif
.if !empty(BUILD_CXX:M[Yy][Ee][Ss])
LANGS+='c++'
.endif
.if !empty(BUILD_F77:M[Yy][Ee][Ss])
LANGS+='f77'
.endif
.if !empty(BUILD_JAVA:M[Yy][Ee][Ss])
LANGS+='java'
.endif
.if !empty(BUILD_OBJC:M[Yy][Ee][Ss])
LANGS+='objc'
.endif
CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}

# FIXME Because gcc ignores rpath for some reason, it breaks on DragonFly -
# binaries are linked against libintl. Disabling NLS for now.
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-nls
.endif

UNLIMIT_RESOURCES+=	datasize

.if !empty(BUILD_F77:M[Yy][Ee][Ss])
.include "../../devel/gmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
USE_TOOLS+=		chmod
MAKE_ENV+=		ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD:Q}
.endif

# GNU pth is useless here
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
# ADA tasking strictly requires native threads
PTHREAD_OPTS+=		require native
.else
PTHREAD_OPTS+=		native
.endif
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

USE_TOOLS+=		gmake makeinfo msgfmt
HAS_CONFIGURE=		YES # no GNU_CONFIGURE!
CONFIG_SHELL?=		${SH}
CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL:Q}

.if !empty(BUILD_ADA:M[Yy][Ee][Ss])

# Ada bootstrap compiler section
# An Ada compiler is required to build the Ada compiler. You
# may specify:
#USE_GCC34ADA	=# Define to use gcc-3.4.x-ada
# Or, you may specify the path of any gcc/gnat Ada compiler
# by providing the full path of the compiler (example) below:
#ALT_GCC=	prefix/bin/gcc
.  if defined(ALT_GCC)
.     if exists(${ALT_GCC})
ALT_GCC_RTS!=	${ALT_GCC} --print-file-name=adalib
.        if !empty(ALT_GCC_RTS)
RALT_GCC_RTS=	${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.        else
PKG_SKIP_REASON+=	"${ALT_GCC} does not appear to be an Ada compiler"
.        endif
.     else
PKG_SKIP_REASON+=	"Missing bootstrap Ada compiler"
.     endif
.  endif
.  if !defined(USE_GCC34ADA) && !defined(ALT_GCC)
PKG_SKIP_REASON+=	"An Ada bootstrap compiler must be specified to BUILD_ADA"
.  endif
.endif

GCC_SUBPREFIX=		gcc34
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.if ${OPSYS} == "NetBSD"
# thread / crtbegin / __cxa_atexit support depend on a "netbsd2" OS name
GCC_PLATFORM=	${LOWER_ARCH}--${LOWER_OPSYS}${APPEND_ELF}${LOWER_OS_VERSION:C/[_a-z].*//}
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM:Q}
ABI_BASELINE_PAIR=	${GCC_PLATFORM:C/--/-/}
MAKE_ENV+=	ABI_BASELINE_PAIR=${ABI_BASELINE_PAIR:Q}
.endif # NetBSD

post-patch:
.if ${OPSYS} == "NetBSD"
.  if exists(${FILESDIR}/${LOWER_ARCH}-baseline_symbols${LOWER_OS_VERSION:C/\..*//}.txt)
	(${TEST} -d ${WRKSRC}/libstdc++-v3/config/abi/${ABI_BASELINE_PAIR} || \
		${MKDIR} ${WRKSRC}/libstdc++-v3/config/abi/${ABI_BASELINE_PAIR})
	${CP} ${FILESDIR}/${LOWER_ARCH}-baseline_symbols${LOWER_OS_VERSION:C/\..*//}.txt \
		${WRKSRC}/libstdc++-v3/config/abi/${ABI_BASELINE_PAIR}/baseline_symbols.txt
.  endif
.endif
	(cd ${FILESDIR}; \
		${CP} adasignal.c ${WRKSRC}/gcc/ada; \
		${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
		${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
		for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
.  if defined(USE_GCC34ADA)
# Overide compiler.mk setup to use gcc-3.4.x-ada
pre-configure:
.include "../../lang/gcc34-ada/preconfigure.mk"
.  elif defined(ALT_GCC)
pre-configure:
	(${TEST} -d ${WRKDIR}/.gcc/bin/ || ${MKDIR} ${WRKDIR}/.gcc/bin/)
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ${LN} -sf ${ALT_GCC_RTS}/libgnat.a .)
	(cd ${ALT_GCC:H} && \
	bin_files=`${FIND} . -type f \( -perm -0100 \) -print` && \
	cd ${WRKDIR}/.gcc/bin/ && \
	for filename in ${ALT_GCC:T} $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${filename}; \
		${ECHO} -n "exec ${ALT_GCC:H}/$${filename} " >>$${filename}; \
		${ECHO} '"$$@"' >>$${filename}; \
		${CHMOD} +x $${filename}; \
	done )
.  endif
.endif
.if ${OPSYS} == "DragonFly"
	${CP} ${FILESDIR}/dragonfly.h ${WRKSRC}/gcc/config/dragonfly.h
	${CP} ${FILESDIR}/dragonfly-spec.h ${WRKSRC}/gcc/config/dragonfly-spec.h
	${CP} ${FILESDIR}/i386-dragonfly.h ${WRKSRC}/gcc/config/i386/dragonfly.h
	${CP} ${FILESDIR}/i386-dragonfly64.h ${WRKSRC}/gcc/config/i386/dragonfly64.h
.endif

do-configure:
	${MKDIR} ${WRKDIR}/obj
	cd ${WRKDIR}/obj; ${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap)
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib-shared)
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)
.endif

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd ${FILESDIR} && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
		(SPECPATH=`${GCC_PREFIX}/bin/gcc -print-file-name=specs` && \
		for EXPANDEDSPECPATH in $${SPECPATH} ; do \
			SPECDIR=`${DIRNAME} $${EXPANDEDSPECPATH}`; \
			${ECHO} $${SPECDIR}/adainclude > $${SPECDIR}/ada_source_path;	\
			${ECHO} $${SPECDIR}/adalib > $${SPECDIR}/ada_object_path;	\
		done )
.endif

GENERATE_PLIST+=							\
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g";

.include "../../mk/bsd.prefs.mk"
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
.  if  defined(USE_GCC34ADA)
BUILDLINK_DEPMETHOD.gcc34-ada=build
.include "../../lang/gcc34-ada/buildlink3.mk"
.  endif
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
