# $NetBSD: Makefile,v 1.1.1.1 2004/06/29 18:01:24 shannonjr Exp $
#

DISTNAME=	gcc-${GCC_VERSION}-${GCC_VERSION_DATE}
PKGNAME=	gcc34-${GCC_VERSION}
CATEGORIES=	lang
#MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/prerelease-${GCC_VERSION}-${GCC_VERSION_DATE}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	This is the gcc 3.4 compiler

GCC_VERSION=		3.4.1
GCC_VERSION_DATE=	20040625

.include "../../mk/bsd.prefs.mk"

# Optional languages - change as required
#   If BUILD_ADA is YES, then you'll need to specify
#   an Ada in the "Ada bootstrap compiler section"
BUILD_DEFS=	BUILD_ADA BUILD_CXX BUILD_F77 \
		BUILD_JAVA BUILD_OBJC
BUILD_ADA?=	NO
BUILD_CXX?=	YES
BUILD_F77?=	YES
BUILD_JAVA?=	NO
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
CONFIGURE_ARGS+=	--enable-languages="${LANGS}"
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--enable-clocale=generic

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		YES
USE_MAKEINFO=		YES
USE_NEW_TEXINFO=	YES
PTHREAD_OPTS+=	require native
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
# Ada bootstrap compiler section
# An Ada compiler is required to build the Ada compiler. Two
may be used:
#USE_GCC33ADA	=# Define to use gcc-3.3.x-ada
#USE_GCC34ADA	=# Define to use gcc-3.4.x-ada
# You may also specify the path of a gcc/gnat Ada compiler
# outside of the pkgsrc system by specifying the full path
# of the compiler (example) below:
#ALT_GCC=	prefix/bin/gcc
.  if defined(ALT_GCC)
.     if exists(${ALT_GCC})
ALT_GCC_PREFIX:=	${ALT_GCC:H}/..
ALT_GCC_RTS!=	${FIND} ${ALT_GCC_PREFIX} -name adalib
RALT_GCC_RTS=	${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.     else
PKG_SKIP_REASON=	"Missing bootstrap Ada compiler"
.     endif
.  endif
.  if !defined(USE_GCC33ADA) && !defined(USE_GCC34ADA) && !defined(ALT_GCC)
PKG_SKIP_REASON=	"An Ada bootstrap compiler must be specified to BUILD_ADA"
.  endif
.endif

GCC_SUBPREFIX=		gcc34
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
FILES_SUBST+=		PKGNAME=${PKGNAME}
MESSAGE_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
GCC_PLATFORM=		${MACHINE_GNU_ARCH}--netbsdelf2.0
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM}
GCC_ARCHSUBDIR=	${GCC_SUBPREFIX}/lib/gcc/${GCC_PLATFORM}/${GCC_VERSION}
GCC_ARCHDIR=	${PREFIX}/${GCC_ARCHSUBDIR}

post-patch:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(${TEST} -d ${WRKSRC}/libstdc++-v3/config/abi/x86_64-netbsdelf2.0 || \
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/abi/x86_64-netbsdelf2.0 )
	${CP} ${FILESDIR}/baseline_symbols64.txt ${WRKSRC}/libstdc++-v3/config/abi/x86_64-netbsdelf2.0/baseline_symbols.txt
.else
	(${TEST} -d ${WRKSRC}/libstdc++-v3/config/abi/i386-netbsdelf2.0 || \
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/abi/i386-netbsdelf2.0 )
	${CP} ${FILESDIR}/baseline_symbols.txt ${WRKSRC}/libstdc++-v3/config/abi/i386-netbsdelf2.0
.endif
	(cd ${FILESDIR}; \
		${CP} adasignal.c ${WRKSRC}/gcc/ada; \
		${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
		${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
		for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

.if ${BUILD_ADA} == "YES"
.  if defined(USE_GCC34ADA)
# Overide compiler.mk setup to use gcc-3.4.x-ada
pre-configure:
.include "../../lang/gcc34-ada/preconfigure.mk"
.  elif defined(ALT_GCC)
pre-configure:
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ${LN} -sf ${ALT_GCC_RTS}/libgnat.a .)
	(cd ${ALT_GCC:H} && \
	bin_files=`${FIND} . -type f \( -perm -0100 \)` && \
	cd ${WRKDIR}/.gcc/bin/ && \
	for filename in ${ALT_GCC:T} $${bin_files} ; do \
	  $(ECHO) '#!/bin/sh' > $${filename}; \
	  $(ECHO) -n "exec ${ALT_GCC:H}/$${filename} " >>$${filename}; \
	  $(ECHO) '"$$@"' >>$${filename}; \
	  $(CHMOD) +x $${filename}; \
	done )
.  endif
.endif

do-configure:
	((${TEST} -d  ${WRKDIR}/obj || ${MKDIR} ${WRKDIR}/obj) && \
	 (cd ${WRKDIR}/obj && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS}))

do-build:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} bootstrap)
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
	(cd ${WRKDIR}/obj/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)
.endif

do-test:
.if (${MACHINE_GNU_ARCH} == "x86_64")
	(cd files && ${CP} netbsd64macro.dfs ${WRKSRC}/gcc/testsuite/ada/acats/support/macro.dfs)
.endif
	(cd ${WRKDIR}/obj && ${GMAKE} -k check)

do-install:
	(cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL} \
	 && ${TEST} -f ${GCC_PREFIX}/bin/cc || ${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc)
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
		(SPECPATH=`${GCC_PREFIX}/bin/gcc -print-file-name=specs` && \
		for EXPANDEDSPECPATH in $${SPECPATH} ; do \
			SPECDIR=`${DIRNAME} $${EXPANDEDSPECPATH}`; \
			${ECHO} $${SPECDIR}/adainclude > $${SPECDIR}/ada_source_path;	\
			${ECHO} $${SPECDIR}/adalib > $${SPECDIR}/ada_object_path;	\
		done )
.endif

post-install:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print	\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"	\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print	\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"
.if !empty(BUILD_ADA:M[Yy][Ee][Ss])
.  if defined(USE_GCC33ADA)
.include "../../lang/gcc3-ada/buildlink3.mk"
.  elif  defined(USE_GCC34ADA)
BUILDLINK_DEPMETHOD.gcc3-ada=build
.include "../../lang/gcc34-ada/buildlink3.mk"
.  endif
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
