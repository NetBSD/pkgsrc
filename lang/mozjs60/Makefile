# $NetBSD: Makefile,v 1.1 2020/04/05 06:10:28 wiz Exp $

DISTNAME=	mozjs60_60.8.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	lang
MASTER_SITES=	http://deb.debian.org/debian/pool/main/m/mozjs60/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/unstable/libmozjs-60-0
COMMENT=	SpiderMonkey JavaScript library (60.x branch)
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/mozjs-60.8.0/js/src
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
CONFIGURE_ARGS+=	--with-system-nspr
#CONFIGURE_ARGS+=	--enable-posix-nspr-emulation
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--disable-jemalloc
CONFIGURE_ARGS+=	--disable-debug-symbols
CONFIGURE_ARGS+=	--enable-strip
# --with-intl-api
# --disable-optimize

PKGCONFIG_OVERRIDE+=	build/js.pc.in
PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in

PYTHON_VERSIONS_ACCEPTED=	27

pre-configure:
	cd ${WRKSRC} && autoconf-2.13
	mkdir ${WRKSRC}/build

post-install:
	cd ${DESTDIR}${PREFIX}/lib && \
		${MV} libmozjs-60.so libmozjs-60.so.0.0.0 && \
		${LN} -s libmozjs-60.so.0.0.0 libmozjs-60.so.0 && \
		${LN} -s libmozjs-60.so.0 libmozjs-60.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/libjs_static.ajs
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/mozjs-60/js-config.h
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/pkgconfig/mozjs-60.pc

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
