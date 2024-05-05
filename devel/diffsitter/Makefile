# $NetBSD: Makefile,v 1.11 2024/05/05 16:27:47 wiz Exp $

DISTNAME=	diffsitter-0.8.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=afnanenayet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/afnanenayet/diffsitter/
COMMENT=	Tree-sitter based AST difftool to get meaningful semantic diffs
LICENSE=	mit

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "cargo-depends.mk"

USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		dynamic-grammar-libs

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
