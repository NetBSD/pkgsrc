# $NetBSD: Makefile,v 1.12 2024/08/15 13:32:32 pin Exp $

DISTNAME=	diffsitter-0.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=afnanenayet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/afnanenayet/diffsitter/
COMMENT=	Tree-sitter based AST difftool to get meaningful semantic diffs
LICENSE=	mit

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
PYTHON_FOR_BUILD_ONLY=		tool

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		dynamic-grammar-libs

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
