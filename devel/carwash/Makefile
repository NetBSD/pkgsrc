# $NetBSD: Makefile,v 1.4 2025/11/16 16:57:10 pin Exp $

DISTNAME=	carwash-0.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
