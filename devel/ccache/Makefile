# $NetBSD: Makefile,v 1.80 2024/05/30 06:28:20 adam Exp $

DISTNAME=	ccache-4.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ccache/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# We choose gzip to minimize dependencies; some platforms do not have
# xz builtin.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccache.dev/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:build pkg-config
CMAKE_ARGS+=	-DENABLE_TESTING=OFF
TEST_TARGET=	test

USE_CXX_FEATURES+=	filesystem

LDFLAGS.SunOS+=	-lsocket

.include "../../lang/ruby/rubyversion.mk"
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor>=2.0.0:../../textproc/ruby-asciidoctor

SUBST_CLASSES+=		rubyver
SUBST_SED.rubyver+=	-e "s/asciidoctor/asciidoctor${RUBY_SUFFIX}/"
SUBST_FILES.rubyver+=	doc/CMakeLists.txt
SUBST_STAGE.rubyver=	pre-configure
SUBST_MESSAGE.rubyver=	Fixing asciidoctor executable name.

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
