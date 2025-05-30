# $NetBSD: Makefile,v 1.8 2025/05/30 10:56:52 pin Exp $

DISTNAME=	cargo-edit-0.13.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=killercup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/killercup/cargo-edit/
COMMENT=	Utility for managing cargo dependencies from the command line
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUST_REQ=	1.85.0
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
