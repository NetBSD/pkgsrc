# $NetBSD: Makefile,v 1.129 2026/05/05 14:00:36 wiz Exp $

DISTNAME=	nspr-4.39
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=nspr/releases/v${PKGVERSION_NOREV}/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR
COMMENT=	Platform-neutral API for system level and libc like functions
LICENSE=	mpl-2.0

GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR= nspr
CONFIGURE_DIRS=		nspr

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		autoconf gmake perl
REPLACE_PERL+=		nspr/pr/src/misc/compile-et.pl

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ENV+=		LIBRUNPATH=${PREFIX}/lib/nspr

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		native

.if ${USE_CROSS_COMPILE:U:tl} == yes
MAKE_FLAGS+=		HOST_CC=${NATIVE_CC:Q}
MAKE_FLAGS+=		HOST_CXX=${NATIVE_CXX:Q}
post-install: post-install-rm-perl
.PHONY: post-install-rm-perl
post-install-rm-perl:
	${RUN} rm ${DESTDIR:Q}${PREFIX:Q}/bin/compile-et.pl
	${RUN} rm ${DESTDIR:Q}${PREFIX:Q}/bin/prerr.properties
.else
# XXX Not actually sure if compile-et.pl or prerr.properties are
# supposed to be included -- they are run at build-time, and other
# packaging systems like Debian exclude them.  But out of an abundance
# of caution, let's avoid breaking downstream packages for now
# (20230609) by continuing to include these in native builds.  (Cross
# builds break because of the missing interpreter.)
PLIST.native=		yes
.endif

BUILDLINK_TRANSFORM+=	rm:-Wall

SUBST_CLASSES+=			nspr-config
SUBST_STAGE.nspr-config=	pre-configure
SUBST_MESSAGE.nspr-config=	Fixing nspr-config run path
SUBST_FILES.nspr-config=	nspr/config/nspr-config.in
SUBST_SED.nspr-config=		-e 's|-L$$libdir|"${COMPILER_RPATH_FLAG}$$libdir -L$$libdir"|g'

SUBST_CLASSES+=			nspr-rpath
SUBST_STAGE.nspr-rpath=		pre-configure
SUBST_FILES.nspr-rpath=		nspr/lib/libc/src/Makefile.in nspr/lib/ds/Makefile.in
SUBST_SED.nspr-rpath=		-e 's|$$$$ORIGIN|${PREFIX}/lib/nspr|g'

PKGCONFIG_OVERRIDE+=	nspr/config/nspr.pc.in

.if ${OPSYS} == "OpenBSD"
CHECK_SHLIBS_SUPPORTED=	no
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

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endif

.if ${OPSYS} == "Darwin"
.  if exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=	Developer/Headers/FlatCarbon
.  endif
.endif

INSTALLATION_DIRS+=	lib/pkgconfig

pre-configure:
	cd ${WRKSRC}/nspr && autoconf

post-install:
	${LN} -s ../nspr/pkgconfig/nspr.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
