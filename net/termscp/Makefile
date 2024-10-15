# $NetBSD: Makefile,v 1.14 2024/10/15 03:38:40 pin Exp $

DISTNAME=	termscp-0.16.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=veeso/}
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://termscp.veeso.dev/
COMMENT=	Feature rich TUI file transfer and explorer
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
