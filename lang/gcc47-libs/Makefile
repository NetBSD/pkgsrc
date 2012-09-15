# $NetBSD: Makefile,v 1.3 2012/09/15 08:10:20 sbd Exp $

GCC_PKGNAME=		gcc47
.include		"../../lang/${GCC_PKGNAME}/version.mk"

DISTNAME=		gcc-${GCC_DIST_VERSION}
PKGNAME=		${GCC_PKGNAME}-libs-${GCC_DIST_VERSION}
## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc47 package so that with the dependence pattern 
## '{gcc47,gcc47-libs}>=4.7.*' pkg_all will choose gcc47-libs over gcc47.
PKGREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		The GNU Compiler Collection (GCC) support shared libraries.
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax

NO_BUILD=		yes

## Depend on exactly ${GCC_DIST_VERSION}.
BUILD_DEPENDS+=		${GCC_PKGNAME}-${GCC_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc47

.include "../../mk/bsd.prefs.mk"

FIND_PREFIX:=		GCC_PKG_PREFIX=${GCC_PKGNAME}-${GCC_DIST_VERSION}*
.include "../../mk/find-prefix.mk"

GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${GCC_PKG_PREFIX}/${GCC_SUBPREFIX}

.if defined(_PKGSRC_BARRIER) && exists(${GCC_PREFIX}/bin/gcc)
TARGET_TRIPLE!=		${GCC_PREFIX}/bin/gcc -dumpmachine
.endif

.include "../../mk/bsd.prefs.mk"
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
.endif

LIBRARY_FILES=	${WRKDIR}/lib_files

GENERATE_PLIST+= ${SED} -e 's,^,${GCC_SUBPREFIX}/${TARGET_TRIPLE}/,' \
			${LIBRARY_FILES};
GENERATE_PLIST+= ${GREP} -q 'lib/' ${LIBRARY_FILES} || \
		   ${ECHO} '@pkgdir ${GCC_SUBPREFIX}/${TARGET_TRIPLE}/lib' ;

${LIBRARY_FILES}:
	${PKG_INFO} -qL '${GCC_PKGNAME}-${GCC_DIST_VERSION}*' |		\
	${SED} -n -e's,^${GCC_PREFIX}/,,' -e'/libexec\//d'		\
		-e'/libgij/d;/libgcj/d;/libjvm/d'			\
		-e'/lib.*\.${SHLIB_EXT}/p' 		>${LIBRARY_FILES}

do-install: ${LIBRARY_FILES}
.if defined(TARGET_TRIPLE) && !empty(TARGET_TRIPLE)
	${TEST} -d ${DESTDIR}${GCC_PREFIX}/${TARGET_TRIPLE}/lib ||	\
		${MKDIR} ${DESTDIR}${GCC_PREFIX}/${TARGET_TRIPLE}/lib
	cd ${GCC_PREFIX} && 						\
	  ${PAX} -rw ${DESTDIR}${GCC_PREFIX}/${TARGET_TRIPLE} <${LIBRARY_FILES}
.else
	${FALSE}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
