# $NetBSD: Makefile,v 1.22 2026/08/09 05:29:05 adam Exp $

DISTNAME=	oxipng-10.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shssoichiro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shssoichiro/oxipng
COMMENT=	Multithreaded PNG optimizer
LICENSE=	mit

RUST_REQ=	1.88.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
