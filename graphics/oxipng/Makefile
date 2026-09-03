# $NetBSD: Makefile,v 1.23 2026/09/03 04:42:55 adam Exp $

DISTNAME=	oxipng-10.2.1
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
