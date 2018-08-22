# $NetBSD: Makefile,v 1.9 2018/08/22 09:45:22 wiz Exp $

DISTNAME=	mozjs-52.7.4
PKGREVISION=	4
PKGNAME=	${DISTNAME:S/mozjs/spidermonkey52/}
CATEGORIES=	lang
MASTER_SITES=	https://queue.taskcluster.net/v1/task/YqG2fjJJSTGzGX090FjDYg/runs/0/artifacts/public/build/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey/Releases/52
COMMENT=	Standalone JavaScript implementation in C (major version 52)
LICENSE=	mpl-2.0

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl gmake autoconf213
AUTOCONF_REQD=	2.13

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--disable-jemalloc

CONFIGURE_DIRS=		js/src

PKGCONFIG_OVERRIDE+=	js/src/ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	js/src/js.pc.in

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		yes

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.if ${MACHINE_ARCH} == "i386"
# Needs 8 byte atomics.
CXXFLAGS+=		-march=i586
.endif

# fails, does not find hg/git checkout
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC}/js/src && autoconf

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/libjs_static.ajs

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
