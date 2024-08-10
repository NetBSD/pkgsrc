# $NetBSD: Makefile,v 1.24 2024/08/10 15:26:46 pin Exp $

DISTNAME=	slumber-1.7.0
# slumber-1.8.0 requires Rust >= 1.80.0 to build.
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LucasPickering/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://slumber.lucaspickering.me/
COMMENT=	Terminal-based REST client
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.76.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
