# $NetBSD: Makefile,v 1.63 2013/01/05 19:02:45 ryoon Exp $

DISTNAME=		nss-${NSS_RELEASE}
NSS_RELEASE=		3.14.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=security/nss/releases/NSS_${NSS_RELEASE:S/./_/g}_RTM/src/}

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications
LICENSE=		mpl-2.0

CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}js/src/configure
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}configure

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla

USE_TOOLS+=		gmake perl pax pkg-config

.include		"../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SUBST_CLASSES+=			exec_path
SUBST_STAGE.exec_path=		pre-configure
SUBST_MESSAGE.exec_path=	Fixing @executable_path
SUBST_FILES.exec_path=		security/nss/lib/freebl/config.mk
SUBST_FILES.exec_path=		security/coreconf/Darwin.mk
SUBST_SED.exec_path=		-e 's,@executable_path,${PREFIX}/lib/nss,g'
.endif

.if ${OPSYS} == "Linux"
MAKE_ENV+=	FREEBL_NO_DEPEND=0
.endif

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV+=	NS_USE_GCC=YES
.endif

.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
MAKE_ENV+=	USE_64=1
.  endif
.endfor

MAKE_ENV+=	BUILD_OPT=1
#MAKE_ENV+=	OPTIMIZER=${CFLAGS:Q}
MAKE_ENV+=	INCLUDES=-I${BUILDLINK_PREFIX.nspr}/include/nspr
MAKE_ENV+=	NSS_USE_SYSTEM_SQLITE=1
MAKE_ENV+=	EXTRA_SHARED_LIBS="-Wl,-R${BUILDLINK_PREFIX.nspr}/lib/nspr -Wl,-R,${PREFIX}/lib/nss -L${BUILDLINK_PREFIX.nspr}/lib/nspr -lplc4 -lplds4 -lnspr4"

post-extract:
	find ${WRKSRC} -type f | xargs ${CHMOD} 644
	find ${WRKSRC} -type d | xargs ${CHMOD} 755

do-build:
	cd ${WRKSRC}/security/nss && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
	  build_coreconf build_dbm all

INSTALLATION_DIRS=	include/nss lib/nss lib/pkgconfig
DIST=	${WRKSRC}/dist

do-install:
	(cd ${DIST}/public && pax -Lrw . ${DESTDIR}${PREFIX}/include/nss/ )
	(cd ${DIST}/*_OPT.OBJ/lib && \
		pax -Lrw *.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib/nss/ )
	${INSTALL_LIB} ${DIST}/*_OPT.OBJ/lib/libcrmf.a \
		${DESTDIR}${PREFIX}/lib/nss/
	set -e; \
	{ ${ECHO} "Name: NSS"; \
	  ${ECHO} "Description: Mozilla Network Security Services"; \
	  ${ECHO} "Version: ${PKGVERSION_NOREV}"; \
	  ${ECHO} "Requires: nspr >= 4.8.2"; \
	  ${ECHO} "Cflags: -I${PREFIX}/include/nss/nss -I${PREFIX}/include/nss"; \
	  ${ECHO} "Libs: -L${PREFIX}/lib/nss" \
	      "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss" \
	      "-lnss3 -lsmime3 -lssl3 -lsoftokn3 -lnssutil3" \
	      ${BUILDLINK_LIBS.pthread:Q}; \
	} >${DESTDIR}${PREFIX}/lib/pkgconfig/nss.pc

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
