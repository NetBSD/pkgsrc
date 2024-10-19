# $NetBSD: Makefile,v 1.68 2024/10/19 15:33:48 pin Exp $

DISTNAME=	ncspot-1.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hrkfdn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/hrkfdn/ncspot/
COMMENT=	Cross-platform ncurses Spotify client written in Rust
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=  cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "options.mk"

.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
