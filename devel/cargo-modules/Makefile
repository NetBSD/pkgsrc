# $NetBSD: Makefile,v 1.34 2024/10/13 20:19:03 pin Exp $

DISTNAME=	cargo-modules-0.17.0
# cargo-modules >= 0.18.0 requires Rust >= 1.81.0 to build.
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.80.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
