# $NetBSD: Makefile,v 1.171 2019/08/11 13:18:47 wiz Exp $

DISTNAME=		nss-${NSS_RELEASE:S/.0$//}
NSS_RELEASE=		3.45.0
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=security/nss/releases/NSS_${NSS_DIST_DIR_VERSION:S/_0$//}_RTM/src/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS
COMMENT=		Libraries to support development of security-enabled applications
LICENSE=		mpl-2.0

CHECK_PORTABILITY_SKIP+=	nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=	js/src/configure
CHECK_PORTABILITY_SKIP+=	configure

CTF_SUPPORTED=		no # https://smartos.org/bugview/OS-6510

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c99
USE_TOOLS+=		gmake perl pax pkg-config
MAKE_JOBS_SAFE=		no

BUILD_DIRS=		nss

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES.Darwin+=		exec_path
SUBST_STAGE.exec_path=		pre-configure
SUBST_MESSAGE.exec_path=	Fixing @executable_path
SUBST_FILES.exec_path=		nss/coreconf/Darwin.mk
SUBST_SED.exec_path=		-e 's,@executable_path,${PREFIX}/lib/nss,g'

SUBST_CLASSES+=			zlib
SUBST_STAGE.zlib=		pre-configure
SUBST_MESSAGE.zlib=		Use ZLIB_LIBS from environment
SUBST_FILES.zlib=		nss/coreconf/*.mk
SUBST_SED.zlib=			-e 's,^ZLIB_LIBS,\#ZLIB_LIBS,g'

BUILDLINK_TRANSFORM+=	rm:-Werror
BUILDLINK_TRANSFORM+=	rm:-ansi

MAKE_ENV.Linux+=	FREEBL_NO_DEPEND=0

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV.SunOS+=	NS_USE_GCC=YES
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_ENV.SunOS+=	CC_IS_CLANG=YES
.endif

SUBST_CLASSES+=		64bit
SUBST_STAGE.64bit=	pre-configure
SUBST_FILES.64bit=	nss/lib/freebl/*
SUBST_SED.64bit=	-e 's,NSS_USE_64,_LP64,g'
SUBST_MESSAGE.64bit=	Use a generic 64bit check

# Just to be safe, do this as well as the _LP64 replacement
# NSS has a lot more logic for USE_64
.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
MAKE_ENV+=	USE_64=1
.  endif
.endfor

MAKE_ENV+=	BUILD_OPT=1
#MAKE_ENV+=	OPTIMIZER=${CFLAGS:Q}
MAKE_ENV+=	INCLUDES=-I${BUILDLINK_PREFIX.nspr}/include/nspr
MAKE_ENV+=	NSS_USE_SYSTEM_SQLITE=1
MAKE_ENV+=	ZLIB_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -L${BUILDLINK_PREFIX.zlib}/lib -lz"
MAKE_ENV+=	USE_SYSTEM_ZLIB=1
MAKE_ENV+=	EXTRA_SHARED_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nspr}/lib/nspr ${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss -L${BUILDLINK_PREFIX.nspr}/lib/nspr -lplc4 -lplds4 -lnspr4 "${LDFLAGS:Q}
MAKE_ENV+=	NSS_DISABLE_GTESTS=yes
MAKE_ENV+=	NSS_ENABLE_TLS_1_3=1
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[0-7]*)
CFLAGS+=	-DNSS_NO_GCC48
.endif

NSS_MAJOR_VERSION=	${NSS_RELEASE:C/\.[0-9.]*//}
NSS_MINOR_VERSION=	${NSS_RELEASE:S/3.//:C/\.[0-9]*//}
NSS_PATCH_VERSION=	${NSS_RELEASE:C/[0-9.]*\.//}
NSS_DIST_DIR_VERSION=	${NSS_MAJOR_VERSION}_${NSS_MINOR_VERSION}_${NSS_PATCH_VERSION}


SUBST_CLASSES+=		config
SUBST_VARS.config=	PREFIX
SUBST_VARS.config+=	NSS_MAJOR_VERSION
SUBST_VARS.config+=	NSS_MINOR_VERSION
SUBST_VARS.config+=	NSS_PATCH_VERSION
SUBST_VARS.config+=	COMPILER_RPATH_FLAG
SUBST_SED.config+=	-e "s,@PTHREAD@,${BUILDLINK_LIBS.pthread:Q},"
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Preparing *-config files.
SUBST_FILES.config+=	nss.pc nss-config

INSTALLATION_DIRS=	bin include/nss lib/nss lib/pkgconfig
DIST=	${WRKSRC}/dist

INSTALL_CMDS+=		certutil cmsutil crlutil derdump makepqg \
			mangle modutil ocspclnt oidcalc p7content p7env p7sign \
			p7verify pk12util rsaperf shlibsign signtool signver \
			ssltap strsclnt symkeyutil vfychain vfyserv

post-extract:
	find ${WRKSRC} -type f | xargs ${CHMOD} 644
	find ${WRKSRC} -type d | xargs ${CHMOD} 755
	${CP} ${FILESDIR}/nss.pc.in ${WRKSRC}/nss.pc
	${CP} ${FILESDIR}/nss-config.in ${WRKSRC}/nss-config

do-install:
	(cd ${DIST}/public && pax -Lrw . ${DESTDIR}${PREFIX}/include/nss/ )
	(cd ${DIST}/*_OPT.OBJ/lib && \
		pax -Lrw *.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib/nss/ )
	${INSTALL_LIB} ${DIST}/*_OPT.OBJ/lib/libcrmf.a \
		${DESTDIR}${PREFIX}/lib/nss/
	${INSTALL_DATA} ${WRKSRC}/nss.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/nss.pc
	${INSTALL_SCRIPT} ${WRKSRC}/nss-config ${DESTDIR}${PREFIX}/bin/nss-config
.for cmd in ${INSTALL_CMDS}
	${INSTALL_PROGRAM} ${DIST}/*_OPT.OBJ/bin/${cmd} ${DESTDIR}${PREFIX}/bin
.endfor

# For consistency of libxul.so link in www/firefox.
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.8.4.2
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.19
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
