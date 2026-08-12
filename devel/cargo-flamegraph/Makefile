# $NetBSD: Makefile,v 1.2 2026/08/12 12:52:37 adam Exp $

DISTNAME=	cargo-flamegraph-0.6.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=flamegraph-rs/}
GITHUB_PROJECT=	flamegraph
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flamegraph-rs/flamegraph
COMMENT=	Rust-powered flamegraph generator
LICENSE=	apache-2.0 OR mit

RUST_REQ=	1.86.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
