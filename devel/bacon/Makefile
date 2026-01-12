# $NetBSD: Makefile,v 1.36 2026/01/12 11:47:43 pin Exp $

DISTNAME=	bacon-3.21.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.82.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
