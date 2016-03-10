# $NetBSD: Makefile,v 1.85 2016/03/10 18:15:51 jperkin Exp $

DISTNAME=	nspr-${NSPR_RELEASE:S/.0$//}
NSPR_RELEASE=	4.12.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=nspr/releases/v${NSPR_RELEASE:S/.0$//}/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR
COMMENT=	Platform-neutral API for system level and libc like functions
LICENSE=	mpl-2.0

CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}js/src/configure
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}configure

OVERRIDE_DIRDEPTH=	3

GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR=nspr
CONFIGURE_DIRS=		nspr

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		autoconf gmake perl
REPLACE_PERL+=		nspr/pr/src/misc/compile-et.pl

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ENV+=		LIBRUNPATH=${PREFIX:Q}/lib/nspr

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			nspr-config
SUBST_STAGE.nspr-config=	pre-configure
SUBST_MESSAGE.nspr-config=	Fixing nspr-config run path
SUBST_FILES.nspr-config=	nspr/config/nspr-config.in
SUBST_SED.nspr-config=		-e 's|-L$$libdir|"${COMPILER_RPATH_FLAG}$$libdir -L$$libdir"|g'

SUBST_CLASSES+=			nspr-rpath
SUBST_STAGE.nspr-rpath=		pre-configure
SUBST_FILES.nspr-rpath=		nspr/lib/libc/src/Makefile.in nspr/lib/ds/Makefile.in
SUBST_SED.nspr-rpath=		-e 's|$$$$ORIGIN|${PREFIX}/lib/nspr|g'

.if ${OPSYS} == "OpenBSD"
CHECK_SHLIBS_SUPPORTED= no
.endif

SUBST_CLASSES.Darwin+=		exec_path
SUBST_STAGE.exec_path=		pre-configure
SUBST_MESSAGE.exec_path=	Fixing @executable_path
SUBST_FILES.exec_path=		nspr/configure.in
SUBST_SED.exec_path=		-e 's,@executable_path,${PREFIX}/lib/nspr,g'

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

PLIST_VARS+=		sun4u_32
# see nspr/pr/src/md/unix/Makefile.in
# for the bit about 32-bit sun4u machines installing an extra file.
# That is why we have this specific test and modify the PLIST
.if ${OPSYS} == "SunOS"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  else
HW_CLASS!=	${UNAME} -m
.    if ${HW_CLASS} == "sun4u"
PLIST.sun4u_32=                yes
.    endif
.  endif
.endif

.if ${OPSYS} == "Linux"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endif

.if ${OPSYS} == "Darwin"
# Avoid using invalid deployment targets.
CONFIGURE_ARGS+=	--with-macos-sdk=/nonexistent
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endif

.if ${OPSYS} == "Darwin" && exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=	Developer/Headers/FlatCarbon
.endif

pre-configure:
	cd ${WRKSRC}/nspr && autoconf

post-build:
	set -e; ( \
	  ${ECHO} "Name: NSPR"; \
	  ${ECHO} "Description: The Netscape Portable Runtime";	\
	  ${ECHO} "Version: ${NSPR_RELEASE}";			\
	  ${ECHO} "Cflags: -I${PREFIX}/include/nspr";		\
	  ${ECHO} "Libs: -L${PREFIX}/lib/nspr"			\
	    "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr"		\
	    "-lplds4 -lplc4 -lnspr4 "${BUILDLINK_LIBS.pthread:Q};	\
	) > ${WRKDIR}/nspr.pc

INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKDIR}/nspr.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
