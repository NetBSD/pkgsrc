# $NetBSD: Makefile,v 1.43 2026/04/19 17:36:48 pin Exp $

DISTNAME=	cargo-modules-0.26.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.91.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
