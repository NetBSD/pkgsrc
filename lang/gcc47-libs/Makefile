# $NetBSD: Makefile,v 1.4 2012/09/26 10:27:47 sbd Exp $

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
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
BUILD_DEFS+=		GCC_TARGET_MACHINE

.include "../../mk/bsd.prefs.mk"
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
.endif

LIBRARY_FILES=	${WRKDIR}/lib_files

GENERATE_PLIST+= ${SED} -e 's,^,${GCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/,' \
			${LIBRARY_FILES};
GENERATE_PLIST+= ${GREP} -q 'lib/' ${LIBRARY_FILES} || \
	   ${ECHO} '@pkgdir ${GCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/lib' ;

${LIBRARY_FILES}:
	${PKG_INFO} -qL '${GCC_PKGNAME}-${GCC_DIST_VERSION}*' |		\
	${SED} -n -e's,^${GCC_PREFIX}/,,' -e'/libexec\//d'		\
		-e'/libgij/d;/libgcj/d;/libjvm/d'			\
		-e'/lib.*\.${SHLIB_EXT}/p' 		>${LIBRARY_FILES}

do-install: ${LIBRARY_FILES}
	${TEST} -d ${DESTDIR}${GCC_PREFIX}/${GCC_TARGET_MACHINE}/lib ||	\
		${MKDIR} ${DESTDIR}${GCC_PREFIX}/${GCC_TARGET_MACHINE}/lib
	cd ${GCC_PREFIX} && 						\
	  ${PAX} -rw ${DESTDIR}${GCC_PREFIX}/${GCC_TARGET_MACHINE} <${LIBRARY_FILES}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
