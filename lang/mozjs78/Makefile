# $NetBSD: Makefile,v 1.3 2020/11/21 02:28:13 gutteridge Exp $

DISTNAME=	mozjs78_78.4.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	lang
MASTER_SITES=	http://deb.debian.org/debian/pool/main/m/mozjs78/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/bullseye/libmozjs-78-0
COMMENT=	SpiderMonkey JavaScript library (78.x branch)
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/firefox-${PKGVERSION_NOREV}/js/src
USE_TOOLS+=	autoconf213 gmake perl pkg-config
USE_LANGUAGES=	c c++

# "ERROR: Only GCC 6.1 or newer is supported"
GCC_REQD+=	6

HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		build
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
# For rustc/cargo detection
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}

PKGCONFIG_OVERRIDE+=	build/js.pc.in
PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool
TOOL_DEPENDS+=			${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
ALL_ENV+=			PYTHON3=${PYTHONBIN}

pre-configure:
	cd ${WRKSRC} && autoconf-2.13 old-configure.in > old-configure \
		&& autoconf-2.13
	mkdir ${WRKSRC}/build && touch ${WRKSRC}/build/old-configure.vars

post-install:
	cd ${DESTDIR}${PREFIX}/lib && \
		${MV} libmozjs-78.so libmozjs-78.so.0.0.0 && \
		${LN} -s libmozjs-78.so.0.0.0 libmozjs-78.so.0 && \
		${LN} -s libmozjs-78.so.0 libmozjs-78.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/libjs_static.ajs
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-78/js-config.h
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-78.pc

BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.41.0
.include "../../lang/rust/rust.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
