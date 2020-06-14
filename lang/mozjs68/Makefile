# $NetBSD: Makefile,v 1.5 2020/06/14 15:33:28 nia Exp $

DISTNAME=	mozjs68_68.6.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://deb.debian.org/debian/pool/main/m/mozjs68/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/bullseye/libmozjs-68-0
COMMENT=	SpiderMonkey JavaScript library (68.x branch)
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/firefox-68.6.0/js/src
USE_TOOLS+=	autoconf213 gmake perl pkg-config
USE_LANGUAGES=	c c++

GCC_REQD+=	4.8

HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--enable-posix-nspr-emulation
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

NOT_PAX_MPROTECT_SAFE+=	bin/js68

# Python 2.7 and Python 3.6 or later are required simultaneously.
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool
.if !empty(PYTHON_VERSION_DEFAULT:M3[6789])
TOOL_DEPENDS+=			python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT}
ALL_ENV+=			PYTHON3=${LOCALBASE}/bin/python${PYTHON_VERSION_DEFAULT:S/3/3./}
.else
TOOL_DEPENDS+=			python37-[0-9]*:../../lang/python37
ALL_ENV+=			PYTHON3=${LOCALBASE}/bin/python3.7
.endif

pre-configure:
	cd ${WRKSRC} && autoconf-2.13
	mkdir ${WRKSRC}/build

post-install:
	cd ${DESTDIR}${PREFIX}/lib && \
		${MV} libmozjs-68.so libmozjs-68.so.0.0.0 && \
		${LN} -s libmozjs-68.so.0.0.0 libmozjs-68.so.0 && \
		${LN} -s libmozjs-68.so.0 libmozjs-68.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/libjs_static.ajs
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-68/js-config.h
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-68.pc

BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
RUST_TYPE=	1.34.0
.include "../../lang/rust/rust.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
