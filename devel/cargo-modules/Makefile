# $NetBSD: Makefile,v 1.35 2024/11/25 14:50:39 pin Exp $

DISTNAME=	cargo-modules-0.19.1
# Newer versions require Rust >= 1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.81.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
