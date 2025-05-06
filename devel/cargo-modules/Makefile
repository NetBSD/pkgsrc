# $NetBSD: Makefile,v 1.39 2025/05/06 19:12:22 pin Exp $

DISTNAME=	cargo-modules-0.23.1
# cargo-modules >= 0.24.0 requires Rust >= 1.86
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.85.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
