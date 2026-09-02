# $NetBSD: Makefile,v 1.89 2026/09/02 19:00:57 wiz Exp $

DISTNAME=	ncspot-1.3.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hrkfdn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hrkfdn/ncspot/
COMMENT=	Cross-platform ncurses Spotify client written in Rust
LICENSE=	2-clause-bsd

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

#RUST_REQ=	1.97.0-beta.2
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.97.0-beta.2 on amd64
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
PYTHON_FOR_BUILD_ONLY=	tool

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "options.mk"

.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
