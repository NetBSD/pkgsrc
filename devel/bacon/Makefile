# $NetBSD: Makefile,v 1.35 2025/12/11 04:28:07 pin Exp $

DISTNAME=	bacon-3.20.3
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
