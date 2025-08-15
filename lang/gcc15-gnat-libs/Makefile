# $NetBSD: Makefile,v 1.2 2025/08/15 07:50:56 dkazankov Exp $

GNAT_PKGNAME=	gcc15-gnat

DISTNAME=	gcc-${PKGVERSION_NOREV}
PKGNAME=	${GNAT_PKGNAME}-libs-15.1.0

## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc15-gnat package so that with the dependence pattern
## '{gcc15-gnat,gcc15-gnat-libs}>=15.1.*' pkg_add will choose gcc15-gnat-libs over gcc15-gnat.
PKGREVISION=	2

CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) GNAT support shared libraries
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=	pax

# Workaround for PR pkg/58966
CHECK_SHLIBS_SUPPORTED=	no
CHECK_RELRO_SUPPORTED=	no

## Depend on exactly ${GCC_DIST_VERSION}.
TOOL_DEPENDS+=		${GNAT_PKGNAME}-${PKGVERSION_NOREV}{,nb[0-9]*}:../../lang/${GNAT_PKGNAME}

.include "../../mk/bsd.prefs.mk"

LIBRARY_FILES=	${WRKDIR}/library_files

do-build:
	${PKG_INFO} -qL '${GNAT_PKGNAME}-${PKGVERSION_NOREV}*' | \
	${SED} -n -e's,^${PREFIX}/${GNAT_PKGNAME}/,,p' | \
	${SED} -n -e'/lib\/.*\/crt.*\.o/p' \
		-e'/lib\/.*\/adalib\/lib.*\.so.*/p' \
		-e'/.*\/ada_target_properties/p' \
		-e'/lib\/lib.*\.so.*/p' \
		> ${LIBRARY_FILES}

TARGET_LIBDIR=	${GNAT_PKGNAME}/${MACHINE_GNU_PLATFORM}/lib

do-install:
	${TEST} -d ${DESTDIR}${PREFIX}/${TARGET_LIBDIR} || \
		${MKDIR} ${DESTDIR}${PREFIX}/${TARGET_LIBDIR}
	cd ${PREFIX}/${GNAT_PKGNAME} && \
		${PAX} -rw -s '/^\(.*\/\)\([^\/]*\)/\2/' \
		${DESTDIR}${PREFIX}/${TARGET_LIBDIR} <${LIBRARY_FILES}

GENERATE_PLIST+=	${ECHO} '@pkgdir ${TARGET_LIBDIR}' ;
GENERATE_PLIST+=	${SED} -e 's,^\(.*\/\)\([^\/]*\),\2,' ${LIBRARY_FILES} | \
			${SED} -e 's,^,${GNAT_PKGNAME}/${MACHINE_GNU_PLATFORM}/lib/,' ;
#			${SED} -e 's,^,${PREFIX}/${GNAT_PKGNAME}/${MACHINE_GNU_PLATFORM}/lib/,' ;

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
