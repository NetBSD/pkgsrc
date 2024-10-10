# $NetBSD: Makefile,v 1.12 2024/10/10 12:42:49 pin Exp $

DISTNAME=	bacon-3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.76.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
