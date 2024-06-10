# $NetBSD: Makefile,v 1.261 2024/06/10 14:52:33 wiz Exp $
#
# release notes
# https://firefox-source-docs.mozilla.org/security/nss/releases/index.html

DISTNAME=		nss-${NSS_RELEASE:S/.0$//}
NSS_RELEASE=		3.101.0
CATEGORIES=		devel security
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=security/nss/releases/NSS_${NSS_DIST_DIR_VERSION:S/_0$//}_RTM/src/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://firefox-source-docs.mozilla.org/security/nss/
COMMENT=		Libraries to support development of security-enabled applications
LICENSE=		mpl-2.0

CHECK_PORTABILITY_SKIP+=	nss/tests/*/*.sh
CHECK_PORTABILITY_SKIP+=	js/src/configure
CHECK_PORTABILITY_SKIP+=	configure

CTF_SUPPORTED=		no # https://smartos.org/bugview/OS-6510

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c
USE_CC_FEATURES+=	c99
USE_TOOLS+=		gmake perl pax pkg-config
# Fails to detect jobserver on systems where /bin/make and /bin/gmake both
# exist. This is because nss uses "gmake" explicitly rather than $MAKE to
# launch subprocesses.
MAKE_JOBS_SAFE=		no

BUILD_DIRS=		nss

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == yes

MAKE_FLAGS+=		CROSS_COMPILE=1
MAKE_FLAGS+=		NATIVE_CC=${NATIVE_CC:Q}
MAKE_FLAGS+=		NATIVE_CFLAGS=
MAKE_FLAGS+=		NATIVE_LDFLAGS=
MAKE_FLAGS+=		NATIVE_EXTRA_SHARED_LIBS=

NSS_CPU_ARCH.aarch64eb=		aarch64
NSS_CPU_ARCH.amd64=		x86_64
NSS_CPU_ARCH.arm26?=		arm
NSS_CPU_ARCH.arm32?=		arm
NSS_CPU_ARCH.earm?=		arm
NSS_CPU_ARCH.earmeb?=		arm
NSS_CPU_ARCH.earmhf?=		arm
NSS_CPU_ARCH.earmhfeb?=		arm
NSS_CPU_ARCH.earmv4?=		arm
NSS_CPU_ARCH.earmv4eb?=		arm
NSS_CPU_ARCH.earmv5?=		arm
NSS_CPU_ARCH.earmv5eb?=		arm
NSS_CPU_ARCH.earmv6?=		arm
NSS_CPU_ARCH.earmv6eb?=		arm
NSS_CPU_ARCH.earmv6hf?=		arm
NSS_CPU_ARCH.earmv6hfeb?=	arm
NSS_CPU_ARCH.earmv7?=		arm
NSS_CPU_ARCH.earmv7eb?=		arm
NSS_CPU_ARCH.earmv7hf?=		arm
NSS_CPU_ARCH.earmv7hfeb?=	arm
NSS_CPU_ARCH.i386=		x86
NSS_CPU_ARCH.i486=		x86
NSS_CPU_ARCH.i586=		x86
NSS_CPU_ARCH.i686=		x86
NSS_CPU_ARCH.powerpc64=		ppc64
NSS_CPU_ARCH.powerpc=		ppc

NSS_CPU_ARCH=		${NSS_CPU_ARCH.${MACHINE_ARCH}:U${MACHINE_ARCH}}
MAKE_FLAGS+=		CPU_ARCH=${NSS_CPU_ARCH:Q}

.endif

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
LDFLAGS.NetBSD+=	-lrt # sem_wait(3)

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
MAKE_ENV+=		NS_USE_GCC=YES
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_ENV+=		CC_IS_CLANG=YES
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
.if ${CC_VERSION:Mgcc-4.[0-7]*}
CFLAGS+=	-DNSS_NO_GCC48
.endif

MOD_MAJOR_VERSION=	${NSS_RELEASE:C/\.[0-9.]*//}
MOD_MINOR_VERSION=	${NSS_RELEASE:S/3.//:C/\.[0-9]*//}
MOD_PATCH_VERSION=	${NSS_RELEASE:C/[0-9.]*\.//}
NSS_DIST_DIR_VERSION=	${MOD_MAJOR_VERSION}_${MOD_MINOR_VERSION}_${MOD_PATCH_VERSION}

NSPR_MINIMUM_VERSION=	4.35

PKGCONFIG_OVERRIDE=	nss.pc

SUBST_CLASSES+=		config
# nss.pc
SUBST_SED.config+=	-e "s,@PTHREAD@,${BUILDLINK_LIBS.pthread:Q},"
SUBST_SED.config+=	-e "s,%prefix%,${PREFIX},"
SUBST_SED.config+=	-e "s,%exec_prefix%,${PREFIX},"
SUBST_SED.config+=	-e "s,%libdir%,${PREFIX}/lib/nss,"
SUBST_SED.config+=	-e "s,%includedir%,${PREFIX}/include/nss,"
SUBST_SED.config+=	-e "s,%NSS_VERSION%,${PKGVERSION_NOREV},"
SUBST_SED.config+=	-e "s,%NSPR_VERSION%,${NSPR_MINIMUM_VERSION},"
# nss-config
SUBST_SED.config+=	-e "s,@prefix@,${PREFIX},"
SUBST_VARS.config+=	MOD_MAJOR_VERSION
SUBST_VARS.config+=	MOD_MINOR_VERSION
SUBST_VARS.config+=	MOD_PATCH_VERSION
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Preparing *-config files.
SUBST_FILES.config+=	nss.pc nss-config

INSTALLATION_DIRS=	bin include/nss lib/nss lib/pkgconfig

INSTALL_CMDS+=		certutil cmsutil crlutil derdump makepqg \
			mangle modutil ocspclnt oidcalc p7content p7env p7sign \
			p7verify pk12util rsaperf shlibsign signtool signver \
			ssltap strsclnt symkeyutil vfychain vfyserv

post-extract:
	find ${WRKSRC} -type f | xargs ${CHMOD} 644
	find ${WRKSRC} -type d | xargs ${CHMOD} 755
	${CP} ${WRKSRC}/nss/pkg/pkg-config/nss.pc.in ${WRKSRC}/nss.pc
	${CP} ${WRKSRC}/nss/pkg/pkg-config/nss-config.in ${WRKSRC}/nss-config

do-install:
	(cd ${WRKSRC}/dist/public/nss && pax -Lrw . ${DESTDIR}${PREFIX}/include/nss )
	(cd ${WRKSRC}/dist/*_OPT.OBJ/lib && \
		pax -Lrw *.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib/nss/ )
	${INSTALL_DATA} ${WRKSRC}/dist/*_OPT.OBJ/lib/libcrmf.a \
		${DESTDIR}${PREFIX}/lib/nss/
	${INSTALL_DATA} ${WRKSRC}/nss.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/nss.pc
	${INSTALL_SCRIPT} ${WRKSRC}/nss-config ${DESTDIR}${PREFIX}/bin/nss-config
.for cmd in ${INSTALL_CMDS}
	${INSTALL_PROGRAM} ${WRKSRC}/dist/*_OPT.OBJ/bin/${cmd} ${DESTDIR}${PREFIX}/bin
.endfor

# For consistency of libxul.so link in www/firefox.
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.8.4.2
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=${NSPR_MINIMUM_VERSION}
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
