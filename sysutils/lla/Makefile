# $NetBSD: Makefile,v 1.7 2024/11/27 10:18:18 pin Exp $

DISTNAME=	lla-0.2.6
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/lla/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/triyanox/lla/
COMMENT=	The Elegant ls Alternative
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
