# $NetBSD: Makefile,v 1.22 2024/04/01 19:19:59 pin Exp $

DISTNAME=	cargo-modules-0.15.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
