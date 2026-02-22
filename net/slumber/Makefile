# $NetBSD: Makefile,v 1.55 2026/02/22 15:04:52 wiz Exp $

DISTNAME=	slumber-5.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LucasPickering/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://slumber.lucaspickering.me/
COMMENT=	Terminal-based REST client
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=	1.90.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
