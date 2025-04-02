# $NetBSD: Makefile,v 1.3 2025/04/02 10:50:24 pin Exp $

DISTNAME=	cargo-licenses-0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://static.crates.io/crates/cargo-licenses/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jhenrique04/cargo-licenses/
COMMENT=	Tool to audit license information for Rust projects
LICENSE=	apache-2.0 OR mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

#RUST_REQ=	1.83.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.83.0 on amd64
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
