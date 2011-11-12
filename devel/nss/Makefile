# $NetBSD: Makefile,v 1.46 2011/11/12 13:00:29 tnn Exp $

.include "../../devel/xulrunner/dist.mk"
PKGNAME=		nss-${NSS_RELEASE}${MOZ_BRANCH_MINOR}
NSS_RELEASE=		3.12.11.0
CATEGORIES=		security

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}js/src/configure
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}configure

USE_TOOLS+=		gmake perl pax pkg-config

.include		"../../mk/bsd.prefs.mk"

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

pre-configure:
# sanity check: make sure the nss release is what we think it is.
	@set -e; if [ '"${NSS_RELEASE}"' !=			\
	  "`${AWK} '/NSS_VERSION/ {print $$3}' <		\
	  ${WRKSRC}/security/nss/lib/nss/nss.h`" ]; then	\
	  ${ECHO} "package is out of date";			\
	  exit 1;						\
	fi

do-build:
	cd ${WRKSRC}/security/nss && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
	  build_coreconf build_dbm all

INSTALLATION_DIRS=	include/nss lib/nss lib/pkgconfig
DIST=	${WRKSRC}/dist

do-install:
	(cd ${DIST}/public && pax -Lrwpe . ${DESTDIR}${PREFIX}/include/nss/ )
	(cd ${DIST}/*_OPT.OBJ/lib && \
		pax -Lrwpe *.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib/nss/ )
	set -e; \
	{ ${ECHO} "Name: NSS"; \
	  ${ECHO} "Description: Mozilla Network Security Services"; \
	  ${ECHO} "Version: ${PKGVERSION}"; \
	  ${ECHO} "Requires: nspr >= 4.8.2"; \
	  ${ECHO} "Cflags: -I${PREFIX}/include/nss/nss -I${PREFIX}/include/nss"; \
	  ${ECHO} "Libs: -L${PREFIX}/lib/nss" \
	      "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss" \
	      "-lnss3 -lsmime3 -lssl3 -lsoftokn3 "${BUILDLINK_LIBS.pthread:Q}; \
	} >${DESTDIR}${PREFIX}/lib/pkgconfig/nss.pc

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
