# $NetBSD: Makefile,v 1.8 2025/03/16 01:03:24 pin Exp $

DISTNAME=	HexPatch-1.11.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Etto48/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://etto48.github.io/HexPatch/
COMMENT=	Binary patcher and editor with TUI interface
LICENSE=	mit

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=				https://static.crates.io/crates/wasi/
SITES.wasi-0.13.3+wasi-0.2.2.crate=					https://static.crates.io/crates/wasi/
SITES.internal-russh-forked-ssh-key-0.6.10+upstream-0.6.7.crate=	https://static.crates.io/crates/internal-russh-forked-ssh-key/

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/HexPatch-1.11.0

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
