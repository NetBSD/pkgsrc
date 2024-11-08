# $NetBSD: Makefile,v 1.6 2024/11/08 08:59:24 pin Exp $

DISTNAME=	flawz-0.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/orhun/flawz/
COMMENT=	TUI for browsing security vulnerabilities
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.74.1
USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
