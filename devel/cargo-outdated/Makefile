# $NetBSD: Makefile,v 1.8 2024/12/08 17:21:35 pin Exp $

DISTNAME=	cargo-outdated-0.16.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kbknapp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kbknapp/cargo-outdated
COMMENT=	Cargo subcommand for displaying when Rust dependencies are out of date
LICENSE=	mit

SITES.curl-sys-0.4.78+curl-8.11.0.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

RUST_REQ=	1.81.0
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
