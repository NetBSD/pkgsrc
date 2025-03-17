# $NetBSD: Makefile,v 1.2 2025/03/17 20:58:48 pin Exp $

DISTNAME=	cargo-edit-0.13.1
# v0.13.2 requires Rust >= 1.85
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=killercup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/killercup/cargo-edit/
COMMENT=	Utility for managing cargo dependencies from the command line
LICENSE=	mit

SITES.curl-sys-0.4.78+curl-8.11.0.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
