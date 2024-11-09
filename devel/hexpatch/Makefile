# $NetBSD: Makefile,v 1.5 2024/11/09 19:44:27 pin Exp $

DISTNAME=	HexPatch-1.9.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Etto48/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://etto48.github.io/HexPatch/
COMMENT=	Binary patcher and editor with TUI interface
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/HexPatch-1.9.3

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
