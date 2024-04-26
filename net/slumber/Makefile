# $NetBSD: Makefile,v 1.11 2024/04/26 09:43:29 pin Exp $

DISTNAME=	slumber-1.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LucasPickering/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://slumber.lucaspickering.me/
COMMENT=	Terminal-based REST client
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
