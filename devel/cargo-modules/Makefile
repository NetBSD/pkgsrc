# $NetBSD: Makefile,v 1.33 2024/10/01 07:54:38 pin Exp $

DISTNAME=	cargo-modules-0.16.10
# cargo-modules-0.17.0 requires Rust >= 1.80.0 to build.
# cargo-modules-0.18.0 requires Rust >= 1.81.0 to build.
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.78.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
