# $NetBSD: Makefile,v 1.9 2025/10/18 05:33:15 dkazankov Exp $

GNAT_PKGNAME=	gcc14-gnat

DISTNAME=	gcc-${PKGVERSION_NOREV}
PKGNAME=	${GNAT_PKGNAME}-libs-14.3.0

## The PKGREVISION of this package needs to be at least 1 more than the
## PKGREVISION of the lang/gcc14-gnat package so that with the dependence pattern
## '{gcc14-gnat,gcc14-gnat-libs}>=14.1.*' pkg_add will choose gcc14-gnat-libs over gcc14-gnat.
PKGREVISION=	4

CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) support shared libraries
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_TOOLS+=	pax

CHECK_RELRO_SUPPORTED=	no

## Depend on exactly ${GCC_DIST_VERSION}.
TOOL_DEPENDS+=		${GNAT_PKGNAME}-${PKGVERSION_NOREV}{,nb[0-9]*}:../../lang/gcc14-gnat
TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf

.include "../../mk/bsd.prefs.mk"

# Workaround for PR pkg/58966
CHECK_SHLIBS_SUPPORTED=	no

LIBRARY_FILES=	${WRKDIR}/list.txt
TARGET_LIBDIR=	${GNAT_PKGNAME}/${MACHINE_GNU_PLATFORM}/lib

GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX} && \
			${FIND} ${GNAT_PKGNAME} \( -type f -or -type l \) -print | ${SORT};
GENERATE_PLIST+=	${ECHO} '@pkgdir ${TARGET_LIBDIR}';

do-build:
	${PKG_INFO} -qL '${GNAT_PKGNAME}-${PKGVERSION_NOREV}*' | \
	${SED} -n -e's,^${PREFIX}/${GNAT_PKGNAME}/,,p' | \
	${SED} -n -e'/lib\/.*\/crt.*\.o/p' \
		-e'/lib\/.*\/adalib\/lib.*\.so.*/p' \
		-e'/.*\/ada_target_properties/p' \
		-e'/lib\/lib.*\.so.*/p' > \
		${LIBRARY_FILES}

do-install:
	${TEST} -d ${DESTDIR}${PREFIX}/${TARGET_LIBDIR} || \
		${MKDIR} ${DESTDIR}${PREFIX}/${TARGET_LIBDIR}
	cd ${PREFIX}/${GNAT_PKGNAME} && \
		${PAX} -rw -s '/^\(.*\/\)\([^\/]*\)/\2/' \
		${DESTDIR}${PREFIX}/${TARGET_LIBDIR} <${LIBRARY_FILES}
	${ECHO} "Patching RPATH in destination libraries..."
	cd ${DESTDIR}${PREFIX} && \
		${FIND} ${TARGET_LIBDIR} \( -name \*.so\* -and -type f \) -print \
			-exec patchelf --force-rpath --set-rpath '$$ORIGIN:${PREFIX}/${TARGET_LIBDIR}' {} \;

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
