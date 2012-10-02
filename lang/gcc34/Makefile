# $NetBSD: Makefile,v 1.55 2012/10/02 20:11:40 asau Exp $
#

DISTNAME=	gcc-${GCC_VERSION}
PKGNAME=	gcc34-${GCC_VERSION}
PKGREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 compiler
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GCC_VERSION=		3.4.6

NOT_FOR_PLATFORM=	Interix-*-*

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

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
.elif ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		OBJDUMP=/usr/sfw/bin/gobjdump
CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
.  if !exists(/usr/sfw/bin/gas)
CONFIGURE_ARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
.  else
CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
.  endif
.endif
.if defined(USE_BINUTILS) && !empty(USE_BINUTILS:M[yY][eE][sS])
DEPENDS+=	binutils>=2.14:../../devel/binutils
CONFIGURE_ARGS+=	--with-as=${LOCALBASE}/bin/as
CONFIGURE_ARGS+=	--with-ld=${LOCALBASE}/bin/ld
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
.endif

CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}

UNLIMIT_RESOURCES+=	datasize

# GNU pth is useless here
PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

USE_TOOLS+=		gmake makeinfo
HAS_CONFIGURE=		YES # no GNU_CONFIGURE!
CONFIG_SHELL?=		${SH}
CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL:Q}

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

.if ${OPSYS} == "DragonFly"
pre-configure:
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
.if !empty(PKG_OPTIONS:Mgcc-ada)
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib-shared)
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)
.endif

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd ${FILESDIR} && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${DESTDIR}${GCC_PREFIX}/bin/gcc ${DESTDIR}${GCC_PREFIX}/bin/cc)
.if !empty(PKG_OPTIONS:Mgcc-ada)
		(SPECPATH=`${GCC_PREFIX}/bin/gcc -print-file-name=specs` && \
		for EXPANDEDSPECPATH in $${SPECPATH} ; do \
			SPECDIR=`${DIRNAME} $${EXPANDEDSPECPATH}`; \
			${ECHO} $${SPECDIR}/adainclude > $${SPECDIR}/ada_source_path;	\
			${ECHO} $${SPECDIR}/adalib > $${SPECDIR}/ada_object_path;	\
		done )
.endif

GENERATE_PLIST+=							\
	${FIND} ${DESTDIR}${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${DESTDIR}${PREFIX}/,,g";

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
