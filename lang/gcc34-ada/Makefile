# $NetBSD: Makefile,v 1.25 2009/06/14 22:58:02 joerg Exp $
#

DISTNAME=	gcc-${GCC_VERSION}
PKGNAME=	gcc34-ada-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 Ada compiler

GCC_VERSION=		3.4.6

USE_TOOLS+=		gmake msgfmt
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-languages="c,ada"
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
PATCHDIR=	${.CURDIR}/../../lang/gcc34/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/gcc34/distinfo

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
AS_VERSION!=	${AS} --version | ${AWK} '{	\
	split($$3, v, /[.]/);	\
	printf "%02d%02d%02d%02d\n",v[1],v[2],v[3],v[4];	\
	exit;	\
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
CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		SHELL=${CONFIG_SHELL}

# Ada bootstrap compiler section
# An Ada compiler is required to build the Ada compiler. You
# may specify:
#USE_GCC34	=# Define to use gcc34
# You may also specify the path of a gcc/gnat Ada compiler
# outside of the pkgsrc system by specifying the full path
# of the compiler (example) below:
#ALT_GCC=	prefix/bin/gcc
.if defined(ALT_GCC)
.	if exists(${ALT_GCC})
ALT_GCC_RTS!=	${ALT_GCC} --print-file-name=adalib
.        if !empty(ALT_GCC_RTS)
RALT_GCC_RTS=	${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.        else
PKG_SKIP_REASON+=	"${ALT_GCC} does not appear to be an Ada compiler"
.        endif
.	else
PKG_SKIP_REASON+=	"Missing bootstrap Ada compiler"
.	endif
.endif
.if !defined(USE_GCC34) && !defined(ALT_GCC)
PKG_SKIP_REASON+=	"An Ada bootstrap compiler must be specified"
.endif

# Make location overridable, to allow ping-pong bootstraps.
GCC34_DEFAULT_SUBPREFIX=	gcc34-ada
GCC34_INSTALLTO_SUBPREFIX?=	${GCC34_DEFAULT_SUBPREFIX}
.if ${GCC34_INSTALLTO_SUBPREFIX} != ${GCC34_DEFAULT_SUBPREFIX}
GCC34_PKGMODIF=		${GCC34_INSTALLTO_SUBPREFIX}
.endif

GCC_SUBPREFIX=		${GCC34_INSTALLTO_SUBPREFIX}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GCC_PLATFORM=		${LOWER_ARCH}--${LOWER_OPSYS}${APPEND_ELF}${LOWER_OS_VERSION:C/[_a-z].*//}
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM:Q}
GCC_ARCHSUBDIR=		${GCC_SUBPREFIX}/lib/gcc/${GCC_PLATFORM}/${GCC_VERSION}
GCC_ARCHDIR=		${PREFIX}/${GCC_ARCHSUBDIR}
PLIST_SUBST+=		GCC_SUBPREFIX=${GCC_SUBPREFIX:Q}
FILES_SUBST+=		GCC_PREFIX=${GCC_PREFIX:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
PTHREAD_OPTS+=		require native
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--enable-threads=gnat
GCC_DIR=	${WRKDIR}/.gcc

post-patch:
	(cd files; \
	${CP} adasignal.c ${WRKSRC}/gcc/ada; \
	${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
	${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
	for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

.if defined(USE_GCC34)
pre-configure:
.include "../../lang/gcc34/preconfigure.mk"
.elif defined(ALT_GCC)
pre-configure:
	(${TEST} -d ${WRKDIR}/.gcc/bin/ || ${MKDIR} ${WRKDIR}/.gcc/bin/)
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ${LN} -sf ${ALT_GCC_RTS}/libgnat.a .)
	(cd ${ALT_GCC:H} && \
	files=`${FIND} . -type f \( -perm -0100 \) -print` && \
	cd ${GCC_DIR}/bin/ && \
	for file in ${ALT_GCC:T} $${files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${file}; \
		${ECHO} -n "exec ${ALT_GCC:H}/$${file} " >>$${file}; \
		${ECHO} '"$$@"' >>$${file}; \
		${CHMOD} +x $${file}; \
	done )
.endif

do-configure:
	${MKDIR} ${WRKDIR}/obj
	cd ${WRKDIR}/obj && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap)
	(cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib-shared)
	(cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd files && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj/gcc && ${GMAKE} check-ada)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)
	(SPECPATH=`${GCC_PREFIX}/bin/gcc -print-file-name=specs` && \
	for EXPANDEDSPECPATH in $${SPECPATH} ; do \
		SPECDIR=`${DIRNAME} $${EXPANDEDSPECPATH}`; \
		${ECHO} $${SPECDIR}/adainclude > $${SPECDIR}/ada_source_path;	\
		${ECHO} $${SPECDIR}/adalib > $${SPECDIR}/ada_object_path;	\
	done )

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/ada > ${WRKDIR}/ada
	${ECHO} '"$$@"' >> ${WRKDIR}/ada
	${INSTALL_DATA} ${WRKDIR}/ada ${PREFIX}/bin/ada
	${CHMOD} +x ${WRKDIR}/ada ${PREFIX}/bin/ada
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print	\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"	\
		>> ${PLIST_SRC}

.if defined(USE_GCC34)
BUILDLINK_DEPMETHOD.gcc34=	build
.include "../../lang/gcc34/buildlink3.mk"
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
