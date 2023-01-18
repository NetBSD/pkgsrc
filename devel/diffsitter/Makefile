# $NetBSD: Makefile,v 1.4 2023/01/18 10:56:42 pin Exp $

DISTNAME=	diffsitter-0.7.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=afnanenayet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/afnanenayet/diffsitter/
COMMENT=	Tree-sitter based AST difftool to get meaningful semantic diffs
LICENSE=	mit

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "cargo-depends.mk"

USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		dynamic-grammar-libs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/diffsitter \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
