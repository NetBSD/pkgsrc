# $NetBSD: Makefile,v 1.6 2025/12/12 08:07:49 pin Exp $

DISTNAME=	carwash-0.3.4
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	https://static.crates.io/crates/carwash/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/epistates/carwash/
COMMENT=	TUI for managing multiple Rust projects with ease
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0
USE_TOOLS+=	pkg-config gmake perl

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
