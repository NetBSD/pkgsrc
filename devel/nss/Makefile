# $NetBSD: Makefile,v 1.27 2008/02/08 10:34:19 tnn Exp $

DISTNAME=		nss-3.11.5
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=security/nss/releases/NSS_3_11_5_RTM/src/}

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

BUILD_DIRS=		mozilla/security/nss

USE_TOOLS+=		awk gmake perl
DIST=			${WRKSRC}/mozilla/dist
BUILD_TARGET=		nss_build_all
MAKE_ENV+=		LD_LIBS="-L${BUILDLINK_PREFIX.nspr}/lib/nspr ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nspr}/lib/nspr ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/nss"
MAKE_ENV+=		LIBRUNPATH=${PREFIX}/lib BUILD_OPT=1

MAKE_JOBS_SAFE=		no

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKEFLAGS+=	NS_USE_GCC=YES
.endif

pre-configure:
	${CP} ${FILESDIR}/DragonFly.mk \
		${WRKSRC}/mozilla/security/coreconf/

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nss
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nss
	(cd ${DIST}/public && ${PAX} -Lrwpe . ${PREFIX}/include/nss/ )
	(cd ${DIST}/*_OPT.OBJ/lib && \
		${PAX} -Lrwpe *.${SO_SUFFIX} ${PREFIX}/lib/nss/ )
	set -e; \
	{ ${ECHO} "Name: NSS"; \
	  ${ECHO} "Description: Mozilla Network Security Services"; \
	  ${ECHO} "Version: ${PKGVERSION}"; \
	  ${ECHO} "Cflags: -I${PREFIX}/include/nss"; \
	  ${ECHO} "Libs: -L${PREFIX}/lib/nss" \
	      "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss" \
	      "-lnss3 -lsmime3 -lssl3 -lsoftokn3 "${BUILDLINK_LIBS.pthread:Q}; \
	} >${PREFIX}/lib/pkgconfig/nss.pc

# The exact set of libfreebl* libs built and installed depends on the
# operating system and platform.  For example, on solaris/sparc you might
# get
#  libfreebl_32fpu_3.so
#  libfreebl_32int_3.so
#  libfreebl_32int64_3.so
# and on others
#  libfreebl3.so
# Since this has been a continual problem in many mozilla packages, just
# do that part dynamically rather than trying to always keep our conditionals
# up to date.
PLIST_SRC=	${WRKDIR}/PLIST
post-install:
	${AWK} '/@comment libfreebl/ {exit} {print}' ${.CURDIR}/PLIST > ${PLIST_SRC}
	ls ${PREFIX}/lib/nss/libfreebl*.${SO_SUFFIX} | ${SORT} | \
		${SED} 's;${PREFIX}/;;g' >> ${PLIST_SRC}
	${AWK} 'ok == 1 {print} /@comment libfreebl/ {ok=1}' ${.CURDIR}/PLIST >> ${PLIST_SRC}
	cd ${PREFIX}/include/nss && ${CHMOD} ${SHAREMODE} nss/*.h dbm/*.h nss/*.api

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.4.1nb2

.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
