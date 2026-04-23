# $NetBSD: Makefile,v 1.1 2026/04/23 18:12:56 pin Exp $

DISTNAME=	bulletty-0.2.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=CrociDB/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CrociDB/bulletty/
COMMENT=	Feed reader for the terminal that stores the articles as Markdown
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

.include "cargo-depends.mk"

RUST_REQ=	1.90

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib


.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
