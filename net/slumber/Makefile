# $NetBSD: Makefile,v 1.33 2025/02/16 16:42:38 pin Exp $

DISTNAME=	slumber-3.0.0
CATEGORIES=	net
#MASTER_SITES=	${MASTER_SITE_GITHUB:=LucasPickering/}
MASTER_SITES=	https://static.crates.io/crates/slumber/
#GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://slumber.lucaspickering.me/
COMMENT=	Terminal-based REST client
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.80.1
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
