# $NetBSD: Makefile,v 1.15 2026/10/22 11:06:36 pin Exp $

DISTNAME=	cargo-edit-0.13.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=killercup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/killercup/cargo-edit/
COMMENT=	Utility for managing cargo dependencies from the command line
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUST_REQ=	1.97.0

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
