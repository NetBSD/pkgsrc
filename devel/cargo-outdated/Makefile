# $NetBSD: Makefile,v 1.6 2024/11/30 19:59:42 wiz Exp $

DISTNAME=	cargo-outdated-0.15.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kbknapp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kbknapp/cargo-outdated/
COMMENT=	Cargo subcommand for displaying when Rust dependencies are out of date
LICENSE=	mit

# https://github.com/kbknapp/cargo-outdated/issues/401
BROKEN=		"Waiting for a release supporting rust 1.80+"

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
