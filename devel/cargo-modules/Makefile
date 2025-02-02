# $NetBSD: Makefile,v 1.37 2025/02/02 18:07:51 pin Exp $

DISTNAME=	cargo-modules-0.21.2
# cargo-modules-0.22.0 require Rust >= 1.84
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.82.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
