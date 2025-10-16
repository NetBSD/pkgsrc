# $NetBSD: Makefile,v 1.33 2025/10/16 10:46:56 pin Exp $

DISTNAME=	bacon-3.19.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dystroy.org/bacon/
COMMENT=	Background rust code check
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

RUST_REQ=	1.77.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
