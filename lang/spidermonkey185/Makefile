# $NetBSD: Makefile,v 1.15 2023/08/14 05:24:46 wiz Exp $
#

DISTNAME=	js185-1.0.0
PKGNAME=	spidermonkey185-1.8.5
PKGREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/js-1.8.5/js/src

USE_TOOLS+=	gmake pkg-config perl:build zip:build
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threadsafe
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--with-system-nspr

PYTHON_VERSIONS_ACCEPTED=	27

SUBST_CLASSES+=			incdir
SUBST_STAGE.incdir=		pre-configure
SUBST_MESSAGE.incdir=		Adjust include path
SUBST_FILES.incdir=		js-config.in mozjs185.pc.in
SUBST_SED.incdir=		-e 's,/js,/js-1.8.5,g'

# XXX: workaround for js-config command and mozjs185.pc
CONFIGURE_ENV+=		MOZILLA_VERSION=4.0

CHECK_PORTABILITY_SKIP+=	configure.in

PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	mozjs185.pc.in

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm"
PLIST_SUBST+=	ARCH=ARM
.elif ${MACHINE_ARCH} == "mips"
PLIST_SUBST+=	ARCH=MIPS
.elif ${MACHINE_ARCH} == "powerpc"
PLIST_SUBST+=	ARCH=PPC
.elif ${MACHINE_ARCH} == "sparc"
PLIST_SUBST+=	ARCH=Sparc
.elif ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	ARCH=X64
.else
PLIST_SUBST+=	ARCH=${MACHINE_ARCH}
.endif

TEST_TARGET=		check

# o Install js interpreter
# o Install the binaries and headers with a proper version suffix
# o Adjust headers permissions
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/js ${DESTDIR}${PREFIX}/bin/js185
	${MV} ${DESTDIR}${PREFIX}/bin/js-config ${DESTDIR}${PREFIX}/bin/js185-config
	${MV} ${DESTDIR}${PREFIX}/include/js ${DESTDIR}${PREFIX}/include/js-1.8.5
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/js-1.8.5/*

# Python is only needed for the test target
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
