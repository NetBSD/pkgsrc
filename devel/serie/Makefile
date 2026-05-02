# $NetBSD: Makefile,v 1.25 2026/05/02 19:44:01 pin Exp $

DISTNAME=	serie-0.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lusingander/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lusingander/serie/
COMMENT=	Rich git commit graph in your terminal
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
