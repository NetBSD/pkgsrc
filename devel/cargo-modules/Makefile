# $NetBSD: Makefile,v 1.44 2026/08/06 13:10:17 pin Exp $

DISTNAME=	cargo-modules-0.27.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.95.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
