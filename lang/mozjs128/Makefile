# $NetBSD: Makefile,v 1.4 2024/10/09 19:00:32 wiz Exp $

MOZVER=		128.1.0esr
DISTNAME=	firefox-${MOZVER}.source
PKGNAME=	mozjs128-${MOZVER:S/esr//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${MOZVER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spidermonkey.dev/
COMMENT=	SpiderMonkey JavaScript library (128.x branch)
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/firefox-${PKGVERSION_NOREV}
USE_TOOLS+=	gm4 gmake perl pkg-config
USE_LANGUAGES=	c c++

# "ERROR: Only GCC 8.1 or newer is supported"
GCC_REQD+=	8

TOOL_DEPENDS+=	cbindgen>=0.26.0:../../devel/cbindgen

CHECK_PORTABILITY_SKIP+=	security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	security/nss/tests/multinit/multinit.sh

CONFIGURE_DIRS=	js/src/build
BUILD_DIRS=	js/src/build

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--disable-jemalloc
CONFIGURE_ARGS+=	--disable-debug-symbols
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--with-intl-api
# --disable-optimize

OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
OVERRIDE_DIRDEPTH=		4

CPPFLAGS.SunOS+=	-DSOLARIS

# For rustc/cargo detection
.include "../../mk/bsd.prefs.mk"

# This is to work around build failures where an upstream configuration script
# is confused by having more than one approximate match to MACHINE_GNU_PLATFORM
# "i486" when attempting to select the Rust compiler target.
.if ${MACHINE_PLATFORM:MNetBSD-*-i386}
CONFIGURE_ARGS+=	--target=i586-unknown-netbsd
CONFIGURE_ARGS+=	--host=i586-unknown-netbsd
.elif ${MACHINE_PLATFORM:MSunOS-*}
CONFIGURE_ARGS+=	--target=x86_64-unknown-illumos
CONFIGURE_ARGS+=	--host=x86_64-unknown-illumos
.else
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set variables in configuration file.
SUBST_FILES.conf+=	js/moz.configure
SUBST_VARS.conf=	PREFIX

PKGCONFIG_OVERRIDE+=	js/src/build/js.pc.in
PKGCONFIG_OVERRIDE+=	js/src/ctypes/libffi/libffi.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

TEST_DEPENDS+=			${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

TEST_TARGET=			check-jstests

post-install:
	cd ${DESTDIR}${PREFIX}/lib && \
		${MV} libmozjs-128.so libmozjs-128.so.0.0.0 && \
		${LN} -s libmozjs-128.so.0.0.0 libmozjs-128.so.0 && \
		${LN} -s libmozjs-128.so.0 libmozjs-128.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/libjs_static.ajs
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-128/js-config.h
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-128.pc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.41.0
.include "../../lang/rust/rust.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
# XXX This does not work entirely correctly at present. There are
# 26 atomic type test failures on powerpc, where these pass on i386.
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
