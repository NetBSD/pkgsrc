# $NetBSD: Makefile,v 1.21 2024/03/22 08:31:04 pin Exp $

# Do not update prior to freeze,
# 0.15.0 and higher require Rust-1.76 or, higher.
DISTNAME=	cargo-modules-0.14.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=regexident/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/regexident/cargo-modules/
COMMENT=	Render your crate's module/item structure as a tree or graph
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
