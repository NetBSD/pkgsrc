# $NetBSD: Makefile,v 1.26 2025/04/02 17:32:24 pin Exp $

DISTNAME=	bacon-3.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.13.3+wasi-0.2.2.crate=		https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

RUST_REQ=	1.76.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
