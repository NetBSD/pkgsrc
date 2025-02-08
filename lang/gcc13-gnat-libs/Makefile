# $NetBSD: Makefile,v 1.1 2025/02/08 14:05:50 wiz Exp $

GCC_PKGNAME=		gcc13
GCC13_DIST_VERSION=	13.3.0

DISTNAME=	gcc-${GCC13_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-gnat-libs-${GCC13_DIST_VERSION}
## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc13 package so that with the dependence pattern
## '{gcc13,gcc13-libs}>=13.1.*' pkg_add will choose gcc13-libs over gcc13.
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) support shared libraries
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=	pax

CHECK_RELRO_SUPPORTED=	no

## Depend on exactly ${GCC13_DIST_VERSION}.
TOOL_DEPENDS+=		${GCC_PKGNAME}-gnat-${GCC13_DIST_VERSION}{,nb[0-9]*}:../../lang/gcc13-gnat
TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf

.include "../../mk/bsd.prefs.mk"

LIBGCC_SUBPREFIX=	${GCC_PKGNAME}-gnat
LIBGCC_PREFIX=		${LOCALBASE}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
BUILD_DEFS+=		GCC_TARGET_MACHINE

LIBRARY_FILES=	${WRKDIR}/list.txt
TARGET_LIBDIR=	${LIBGCC_SUBPREFIX}/${GCC_TARGET_MACHINE}/lib

GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX}	\
			${FIND} lib \( -type f -or -type l \) -print | ${SORT} || \
			${ECHO} '@pkgdir ${TARGET_LIBDIR}' ;

do-build:
	${PKG_INFO} -qL '${GCC_PKGNAME}-gnat-${GCC13_DIST_VERSION}*' | \
	${SED} -n -e's,^${LIBGCC_PREFIX}/,,p' | \
	${SED} -n -e'/lib\/.*\/crt.*\.o/p' \
		-e'/lib\/.*\/adalib\/lib.*\.so.*/p' \
		-e'/.*\/ada_target_properties/p' \
		-e'/lib\/lib.*\.so.*/p' > \
		${LIBRARY_FILES}

do-install:
	${TEST} -d ${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR} || \
		${MKDIR} ${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR}
	cd ${LIBGCC_PREFIX} && \
		${PAX} -rw -s '/^\(.*\/\)\([^\/]*\)/\2/' \
		${DESTDIR}${LOCALBASE}/${TARGET_LIBDIR} <${LIBRARY_FILES}
	${ECHO} "Patching RPATH in destination libraries..."
	cd ${DESTDIR}${LOCALBASE} && \
		${FIND} ${TARGET_LIBDIR} \( -name \*.so\* -and -type f \) -print \
			-exec patchelf --force-rpath --set-rpath '$$ORIGIN:${LOCALBASE}/${TARGET_LIBDIR}' {} \;

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
