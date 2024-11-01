# $NetBSD: Makefile,v 1.28 2024/11/01 12:54:02 wiz Exp $

DISTNAME=	slumber-2.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LucasPickering/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
