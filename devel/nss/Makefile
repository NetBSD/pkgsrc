# $NetBSD: Makefile,v 1.15 2006/07/12 15:39:50 rillig Exp $

DISTNAME=		nss-3.9.2
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_9_2_RTM/src/

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

# NSS will build and run on other platforms when MAINTAINER knows what
# magic Makefile glue is required
ONLY_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* Linux-*-* DragonFly-*-*
# Solaris has missing symbols when linking.  It looks like some of those problem
# have been addressed in the nss source tree so this should be enabled after
# the next update.
#SunOS-*-*

BUILD_DIRS=		mozilla/security/nss

USE_TOOLS+=		gmake perl
DIST=			${WRKSRC}/mozilla/dist
BUILD_TARGET=		nss_build_all
MAKE_ENV+=		LD_LIBS="-L${BUILDLINK_PREFIX.nspr}/lib/nspr ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nspr}/lib/nspr ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/nss"
MAKE_ENV+=		LIBRUNPATH=${PREFIX}/lib BUILD_OPT=1

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

.if ${OPSYS} == "SunOS" && ${PKGSRC_COMPILER} == "gcc"
MAKEFLAGS+=	NS_USE_GCC=YES
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
NSS_OBJ_DIR=	${OPSYS}${OS_VERSION}_OPT.OBJ
.elif ${OPSYS} == "Linux"
NSS_SHORT_OS_VERSION!=	echo ${OS_VERSION} | ${SED} -e 's/^\([[:digit:]]\.[[:digit:]]\)\..*$$/\1/'
.  if ${MACHINE_ARCH} == "i386"
NSS_MACHINE_ARCH=	_x86
.  elif ${MACHINE_ARCH} == "parisc" || ${MACHINE_ARCH} == "parisc64"
NSS_MACHINE_ARCH=	_hppa
.  elif ${MACHINE_ARCH} == "sparc64"
NSS_MACHINE_ARCH=	_sparc
.  else
NSS_MACHINE_ARCH=	_${MACHINE_ARCH}
.  endif
NSS_OBJ_DIR=	${OPSYS}${NSS_SHORT_OS_VERSION}${NSS_MACHINE_ARCH}_glibc_PTH_OPT.OBJ
.endif

pre-configure:
	${CP} ${FILESDIR}/DragonFly.mk \
		${WRKSRC}/mozilla/security/coreconf/

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nss
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nss
	(cd ${DIST}/public && ${PAX} -Lrwpe . ${PREFIX}/include/nss/ )
	(cd ${DIST}/${NSS_OBJ_DIR}/lib && \
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

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.4.1nb2

.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
