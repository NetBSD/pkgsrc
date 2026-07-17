# $NetBSD: Makefile,v 1.39 2026/07/17 05:14:46 pin Exp $

DISTNAME=	bacon-3.24.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.85.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
