# $NetBSD: Makefile,v 1.17 2026/11/17 04:07:57 pin Exp $

DISTNAME=	chess-tui-2.8.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=thomas-mauran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thomas-mauran.github.io/chess-tui/
COMMENT=	Chess TUI implementation in rust
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

RUST_REQ=	1.90
USE_TOOLS+=	pkg-config perl gmake

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
